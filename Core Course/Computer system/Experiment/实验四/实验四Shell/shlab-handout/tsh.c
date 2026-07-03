/*
 * tsh - A tiny shell program with job control
 *
 * <Put your name and login ID here>
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/* Misc manifest constants */
#define MAXLINE 1024   /* max line size */
#define MAXARGS 128    /* max args on a command line */
#define MAXJOBS 16     /* max jobs at any point in time */
#define MAXJID 1 << 16 /* max job ID */

/* Job states */
#define UNDEF 0 /* undefined */
#define FG 1    /* running in foreground */
#define BG 2    /* running in background */
#define ST 3    /* stopped */

/*
 * Jobs states: FG (foreground), BG (background), ST (stopped)
 * Job state transitions and enabling actions:
 *     FG -> ST  : ctrl-z
 *     ST -> FG  : fg command
 *     ST -> BG  : bg command
 *     BG -> FG  : fg command
 * At most 1 job can be in the FG state.
 */

/* Global variables */
extern char **environ;   /* defined in libc */
char prompt[] = "tsh> "; /* command line prompt (DO NOT CHANGE) */
int verbose = 0;         /* if true, print additional output */
int nextjid = 1;         /* next job ID to allocate */
char sbuf[MAXLINE];      /* for composing sprintf messages */

struct job_t
{                          /* The job struct */
    pid_t pid;             /* job PID */
    int jid;               /* job ID [1, 2, ...] */
    int state;             /* UNDEF, BG, FG, or ST */
    char cmdline[MAXLINE]; /* command line */
};
struct job_t jobs[MAXJOBS]; /* The job list */
/* End global variables */

/* Function prototypes */

/* Here are the functions that you will implement */
void eval(char *cmdline);
int builtin_cmd(char **argv);
void do_bgfg(char **argv);
void waitfg(pid_t pid);

void sigchld_handler(int sig);
void sigtstp_handler(int sig);
void sigint_handler(int sig);

/* Here are helper routines that we've provided for you */
int parseline(const char *cmdline, char **argv);
void sigquit_handler(int sig);

void clearjob(struct job_t *job);
void initjobs(struct job_t *jobs);
int maxjid(struct job_t *jobs);
int addjob(struct job_t *jobs, pid_t pid, int state, char *cmdline);
int deletejob(struct job_t *jobs, pid_t pid);
pid_t fgpid(struct job_t *jobs);
struct job_t *getjobpid(struct job_t *jobs, pid_t pid);
struct job_t *getjobjid(struct job_t *jobs, int jid);
int pid2jid(pid_t pid);
void listjobs(struct job_t *jobs);

void usage(void);
void unix_error(char *msg);
void app_error(char *msg);
typedef void handler_t(int);
handler_t *Signal(int signum, handler_t *handler);

/*
 * main - The shell's main routine
 */
int main(int argc, char **argv)
{
    char c;
    char cmdline[MAXLINE];
    int emit_prompt = 1; /* emit prompt (default) */

    /* Redirect stderr to stdout (so that driver will get all output
     * on the pipe connected to stdout) */
    dup2(1, 2);

    /* Parse the command line */
    while ((c = getopt(argc, argv, "hvp")) != EOF)
    {
        switch (c)
        {
        case 'h': /* print help message */
            usage();
            break;
        case 'v': /* emit additional diagnostic info */
            verbose = 1;
            break;
        case 'p':            /* don't print a prompt */
            emit_prompt = 0; /* handy for automatic testing */
            break;
        default:
            usage();
        }
    }

    /* Install the signal handlers */

    /* These are the ones you will need to implement */
    Signal(SIGINT, sigint_handler);   /* ctrl-c */
    Signal(SIGTSTP, sigtstp_handler); /* ctrl-z */
    Signal(SIGCHLD, sigchld_handler); /* Terminated or stopped child */

    /* This one provides a clean way to kill the shell */
    Signal(SIGQUIT, sigquit_handler);

    /* Initialize the job list */
    initjobs(jobs);

    /* Execute the shell's read/eval loop */
    while (1)
    {

        /* Read command line */
        if (emit_prompt)
        {
            printf("%s", prompt);
            fflush(stdout);
        }
        if ((fgets(cmdline, MAXLINE, stdin) == NULL) && ferror(stdin))
            app_error("fgets error");
        if (feof(stdin))
        { /* End of file (ctrl-d) */
            fflush(stdout);
            exit(0);
        }

        /* Evaluate the command line */
        eval(cmdline);
        fflush(stdout);
        fflush(stdout);
    }

    exit(0); /* control never reaches here */
}

/*
 * eval - Evaluate the command line that the user has just typed in
 *
 * If the user has requested a built-in command (quit, jobs, bg or fg)
 * then execute it immediately. Otherwise, fork a child process and
 * run the job in the context of the child. If the job is running in
 * the foreground, wait for it to terminate and then return.  Note:
 * each child process must have a unique process group ID so that our
 * background children don't receive SIGINT (SIGTSTP) from the kernel
 * when we type ctrl-c (ctrl-z) at the keyboard.
 */
void eval(char *cmdline)
{
    char *argv[MAXARGS]; // 参数列表
    pid_t pid;           // 进程PID
    int state;           // 是否在后台运行，命令结尾是否有&

    sigset_t mask_all, mask_one, prev_one;

    // 1.先进行解析命令，把"ls -l"变成argv[0]="ls"，argv[1]="-l"
    if (parseline(cmdline, argv))
        state = BG;
    else
        state = FG;

    // 空命令行:直接返回
    if (argv[0] == NULL)
        return;

    // 2.判断前后台运行,如果是内部命令直接在builtin_cmd中执行并结束
    if (!builtin_cmd(argv))
    {
        // 3.不是内部命令，先fork一个子进程然后在子进程中加载程序
        // 先初始化信号集
        sigfillset(&mask_all);
        sigemptyset(&mask_one);
        sigaddset(&mask_one, SIGCHLD);

        // 阻塞SIGCHLD信号，防止子进程fork出来还没addjob就暴毙
        sigprocmask(SIG_BLOCK, &mask_one, &prev_one);

        if ((pid = fork()) == 0)
        {
            // fork出来子进程时恢复原来的阻塞，防止子进程一直阻塞
            sigprocmask(SIG_SETMASK, &prev_one, NULL);
            // 自己成立一个进程组(否则向整个进程组发信号)，保证ctrl+c只发给当前进程
            setpgid(0, 0);
            if (execve(argv[0], argv, environ) < 0)
            {

                // 如果execve返回了，说明执行失败
                printf("%s: Command not found.\n", argv[0]);
                exit(0); // 子进程必须退出程序，否则子进程返回eval变成另一个shell
            }
        }
        // 在添加工作时阻塞全部信号
        sigprocmask(SIG_BLOCK, &mask_all, NULL);
        addjob(jobs, pid, state, cmdline);         // 把出生的工作放在工作本里
        sigprocmask(SIG_SETMASK, &prev_one, NULL); // 添加完工作解锁阻塞信号

        // 判断前后台运行
        if (state == FG)
        { // 如果是前台，等待子进程结束收尸
            waitfg(pid);
        }
        else
        { // 如果是后台，只打印一行提示
            printf("[%d] (%d) %s", pid2jid(pid), pid, cmdline);
        }
    }

    return;
}

/*
 * parseline - Parse the command line and build the argv array.
 *
 * Characters enclosed in single quotes are treated as a single
 * argument.  Return true if the user has requested a BG job, false if
 * the user has requested a FG job.
 */
int parseline(const char *cmdline, char **argv)
{
    static char array[MAXLINE]; /* holds local copy of command line */
    char *buf = array;          /* ptr that traverses command line */
    char *delim;                /* points to first space delimiter */
    int argc;                   /* number of args */
    int bg;                     /* background job? */

    strcpy(buf, cmdline);
    buf[strlen(buf) - 1] = ' ';   /* replace trailing '\n' with space */
    while (*buf && (*buf == ' ')) /* ignore leading spaces */
        buf++;

    /* Build the argv list */
    argc = 0;
    if (*buf == '\'')
    {
        buf++;
        delim = strchr(buf, '\'');
    }
    else
    {
        delim = strchr(buf, ' ');
    }

    while (delim)
    {
        argv[argc++] = buf;
        *delim = '\0';
        buf = delim + 1;
        while (*buf && (*buf == ' ')) /* ignore spaces */
            buf++;

        if (*buf == '\'')
        {
            buf++;
            delim = strchr(buf, '\'');
        }
        else
        {
            delim = strchr(buf, ' ');
        }
    }
    argv[argc] = NULL;

    if (argc == 0) /* ignore blank line */
        return 1;

    /* should the job run in the background? */
    if ((bg = (*argv[argc - 1] == '&')) != 0)
    {
        argv[--argc] = NULL;
    }
    return bg;
}

/*
 * builtin_cmd - If the user has typed a built-in command then execute
 *    it immediately.
 */
int builtin_cmd(char **argv)
{
    if (strcmp(argv[0], "quit") == 0)
        exit(0);
    else if (strcmp(argv[0], "jobs") == 0)
        listjobs(jobs);
    else if (strcmp(argv[0], "bg") == 0 || strcmp(argv[0], "fg") == 0)
        do_bgfg(argv);
    else
        return 0; // 不是内置命令直接返回
    return 1;
}

/*
 * do_bgfg - Execute the builtin bg and fg commands
 */
void do_bgfg(char **argv)
{
    struct job_t *job = NULL;
    int jid;
    int pid;

    // 检验：检查bg/fg有没有带参数
    if (argv[1] == NULL)
    {
        printf("%s command requires PID or %%jobid argument\n", argv[0]);
        return;
    }
    // 解析:是pid还是jid
    if (argv[1][0] == '%')
    {
        // 说明是JID，跳过%，并把后面的字符串转换为数字
        jid = atoi(&argv[1][1]);
        job = getjobjid(jobs, jid);
        if (job == NULL)
        {
            printf("%%%d: No such job\n", jid);
            return;
        }
    }
    else if (isdigit(argv[1][0]))
    {
        // 说明是PID，直接把字符串转换为数字
        pid = atoi(argv[1]);
        job = getjobpid(jobs, pid);
        if (job == NULL)
        {
            printf("(%d): No such process\n", pid);
            return;
        }
    }
    else
    {
        // 输入了乱七八糟的非数字参数 (如 bg abc)
        printf("%s: argument must be a PID or %%jobid\n", argv[0]);
        return;
    }
    // 核心任务：修改状态并发信号重新唤醒
    pid = job->pid;
    if (strcmp(argv[0], "bg") == 0)
    { // 如果是后台指令
        // 1.修改状态
        job->state = BG;
        // 2.打印提示
        printf("[%d] (%d) %s", job->jid, job->pid, job->cmdline);
        // 3.发信号
        kill(-pid, SIGCONT);
    }
    else
    { // 如果是前台指令
        // 1.修改状态
        job->state = FG;
        // 2.发信号
        kill(-pid, SIGCONT);
        // 3.等待前台完成
        waitfg(pid);
    }
    return;
}

/*
 * waitfg - Block until process pid is no longer the foreground process
 */
void waitfg(pid_t pid)
{
    // 新建空信号集
    sigset_t wait;
    sigemptyset(&wait);

    // 只要系统前台程序的pid还是pid就继续挂起，避免使用空循环占用CPU资源
    while (fgpid(jobs) == pid)
        sigsuspend(&wait);
    // int sigsuspend(const sigset_t *mask);
    // 用于在接收到某个信号之前，临时用mask替换进程的信号掩码，并暂停进程执行，直到收到信号为止

    // 出函数时打印调试语句
    if (verbose)
    {
        printf("waitfg: Process (%d) no longer the fg process\n", pid);
    }
    return;
}

/*****************
 * Signal handlers
 *****************/

/*
 * sigchld_handler - The kernel sends a SIGCHLD to the shell whenever
 *     a child job terminates (becomes a zombie), or stops because it
 *     received a SIGSTOP or SIGTSTP signal. The handler reaps all
 *     available zombie children, but doesn't wait for any other
 *     currently running children to terminate.
 */
void sigchld_handler(int sig)
{
    // 打印调试信息
    if (verbose)
    {
        printf("sigchld_handler: entering\n");
    }

    // 保存原始errno，防止影响主线程
    int olderrno = errno;
    pid_t pid;
    int jid;
    int status;
    struct job_t *job = NULL;

    while ((pid = waitpid(-1, &status, WNOHANG | WUNTRACED)) > 0)
    {
        // 如果当前这个子进程的job已经删除了，则表示有错误发生
        if ((job = getjobpid(jobs, pid)) == NULL)
        {
            printf("Lost track of (%d)\n", pid);
            continue;
        }

        jid = job->jid;

        // 情况一：子进程正常退出
        if (WIFEXITED(status))
        {
            // 直接删除工作集
            if (deletejob(jobs, pid))
            {
                if (verbose)
                {
                    printf("sigchld_handler: Job [%d] (%d) deleted\n", jid, pid);
                    printf("sigchld_handler: Job [%d] (%d) terminates OK (status %d)\n", jid, pid, WEXITSTATUS(status));
                    // 用WEXITSTATUS(status) 得到退出编号（exit的参数）
                }
            }
        }
        // 情况二：被外部信号掐死
        else if (WIFSIGNALED(status))
        {
            int sig_num = WTERMSIG(status); // 获取掐死信号
            // 从工作集中删除
            if (deletejob(jobs, pid))
            {
                if (verbose)
                    printf("sigchld_handler: Job [%d] (%d) deleted\n", jid, pid);
            }
            // 打印异常终止通知
            printf("Job [%d] (%d) terminated by signal %d\n", jid, pid, sig_num);
        }
        // 情况三：被暂时挂起
        else if (WIFSTOPPED(status))
        {
            int sig_num = WSTOPSIG(status); // 获取挂起信号
            // 打印挂起通知
            printf("Job [%d] (%d) stopped by signal %d\n", jid, pid, sig_num);
            // 只是挂起，只用修改工作状态
            job->state = ST;
        }
    }
    errno = olderrno;
    if (verbose)
    {
        printf("sigchld_handler: exiting\n");
    }
    return;
}

/*
 * sigint_handler - The kernel sends a SIGINT to the shell whenver the
 *    user types ctrl-c at the keyboard.  Catch it and send it along
 *    to the foreground job.
 */
void sigint_handler(int sig)
{
    if (verbose)
    {
        printf("sigint_handler: entering\n");
    }
    int olderrno = errno; // 保护errno

    pid_t pid = fgpid(jobs);

    if (pid != 0)
    {
        // 向整个子进程组发信号
        kill(-pid, SIGINT);
        if (verbose)
        {
            printf("sigint_handler: Job (%d) killed\n", pid);
        }
    }

    errno = olderrno;
    if (verbose)
    {
        printf("sigint_handler: exiting\n");
    }
    return;
}

/*
 * sigtstp_handler - The kernel sends a SIGTSTP to the shell whenever
 *     the user types ctrl-z at the keyboard. Catch it and suspend the
 *     foreground job by sending it a SIGTSTP.
 */
void sigtstp_handler(int sig)
{
    if (verbose)
    {
        printf("sigtstp_handler: entering\n");
    }
    int olderrno = errno;

    pid_t pid = fgpid(jobs);
    struct job_t *job = getjobpid(jobs, pid);

    if (pid != 0)
    {
        kill(-pid, SIGTSTP);
        if (verbose)
        {
            printf("sigstp_handler: Job [%d] (%d) stopped\n", job->jid, pid);
        }
    }

    errno = olderrno;
    if (verbose)
    {
        printf("sigtstp_handler: exiting\n");
    }
    return;
}

/*********************
 * End signal handlers
 *********************/

/***********************************************
 * Helper routines that manipulate the job list
 **********************************************/

/* clearjob - Clear the entries in a job struct */
void clearjob(struct job_t *job)
{
    job->pid = 0;
    job->jid = 0;
    job->state = UNDEF;
    job->cmdline[0] = '\0';
}

/* initjobs - Initialize the job list */
void initjobs(struct job_t *jobs)
{
    int i;

    for (i = 0; i < MAXJOBS; i++)
        clearjob(&jobs[i]);
}

/* maxjid - Returns largest allocated job ID */
int maxjid(struct job_t *jobs)
{
    int i, max = 0;

    for (i = 0; i < MAXJOBS; i++)
        if (jobs[i].jid > max)
            max = jobs[i].jid;
    return max;
}

/* addjob - Add a job to the job list */
int addjob(struct job_t *jobs, pid_t pid, int state, char *cmdline)
{
    int i;

    if (pid < 1)
        return 0;

    for (i = 0; i < MAXJOBS; i++)
    {
        if (jobs[i].pid == 0)
        {
            jobs[i].pid = pid;
            jobs[i].state = state;
            jobs[i].jid = nextjid++;
            if (nextjid > MAXJOBS)
                nextjid = 1;
            strcpy(jobs[i].cmdline, cmdline);
            if (verbose)
            {
                printf("Added job [%d] %d %s\n", jobs[i].jid, jobs[i].pid, jobs[i].cmdline);
            }
            return 1;
        }
    }
    printf("Tried to create too many jobs\n");
    return 0;
}

/* deletejob - Delete a job whose PID=pid from the job list */
int deletejob(struct job_t *jobs, pid_t pid)
{
    int i;

    if (pid < 1)
        return 0;

    for (i = 0; i < MAXJOBS; i++)
    {
        if (jobs[i].pid == pid)
        {
            clearjob(&jobs[i]);
            nextjid = maxjid(jobs) + 1;
            return 1;
        }
    }
    return 0;
}

/* fgpid - Return PID of current foreground job, 0 if no such job */
pid_t fgpid(struct job_t *jobs)
{
    int i;

    for (i = 0; i < MAXJOBS; i++)
        if (jobs[i].state == FG)
            return jobs[i].pid;
    return 0;
}

/* getjobpid  - Find a job (by PID) on the job list */
struct job_t *getjobpid(struct job_t *jobs, pid_t pid)
{
    int i;

    if (pid < 1)
        return NULL;
    for (i = 0; i < MAXJOBS; i++)
        if (jobs[i].pid == pid)
            return &jobs[i];
    return NULL;
}

/* getjobjid  - Find a job (by JID) on the job list */
struct job_t *getjobjid(struct job_t *jobs, int jid)
{
    int i;

    if (jid < 1)
        return NULL;
    for (i = 0; i < MAXJOBS; i++)
        if (jobs[i].jid == jid)
            return &jobs[i];
    return NULL;
}

/* pid2jid - Map process ID to job ID */
int pid2jid(pid_t pid)
{
    int i;

    if (pid < 1)
        return 0;
    for (i = 0; i < MAXJOBS; i++)
        if (jobs[i].pid == pid)
        {
            return jobs[i].jid;
        }
    return 0;
}

/* listjobs - Print the job list */
void listjobs(struct job_t *jobs)
{
    int i;

    for (i = 0; i < MAXJOBS; i++)
    {
        if (jobs[i].pid != 0)
        {
            printf("[%d] (%d) ", jobs[i].jid, jobs[i].pid);
            switch (jobs[i].state)
            {
            case BG:
                printf("Running ");
                break;
            case FG:
                printf("Foreground ");
                break;
            case ST:
                printf("Stopped ");
                break;
            default:
                printf("listjobs: Internal error: job[%d].state=%d ",
                       i, jobs[i].state);
            }
            printf("%s", jobs[i].cmdline);
        }
    }
}
/******************************
 * end job list helper routines
 ******************************/

/***********************
 * Other helper routines
 ***********************/

/*
 * usage - print a help message
 */
void usage(void)
{
    printf("Usage: shell [-hvp]\n");
    printf("   -h   print this message\n");
    printf("   -v   print additional diagnostic information\n");
    printf("   -p   do not emit a command prompt\n");
    exit(1);
}

/*
 * unix_error - unix-style error routine
 */
void unix_error(char *msg)
{
    fprintf(stdout, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

/*
 * app_error - application-style error routine
 */
void app_error(char *msg)
{
    fprintf(stdout, "%s\n", msg);
    exit(1);
}

/*
 * Signal - wrapper for the sigaction function
 */
handler_t *Signal(int signum, handler_t *handler)
{
    struct sigaction action, old_action;

    action.sa_handler = handler;
    sigemptyset(&action.sa_mask); /* block sigs of type being handled */
    action.sa_flags = SA_RESTART; /* restart syscalls if possible */

    if (sigaction(signum, &action, &old_action) < 0)
        unix_error("Signal error");
    return (old_action.sa_handler);
}

/*
 * sigquit_handler - The driver program can gracefully terminate the
 *    child shell by sending it a SIGQUIT signal.
 */
void sigquit_handler(int sig)
{
    printf("Terminating after receipt of SIGQUIT signal\n");
    exit(1);
}
