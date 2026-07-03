#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

// SIGALRM 的信号处理函数
void alarm_handler(int sig)
{
    printf("\n[Alarm] 滴滴滴！3秒时间到！\n");
    // 重新设置 3 秒的闹钟，实现周期性触发
    alarm(3);
}

int main()
{
    char ch;

    // 1. 注册 SIGALRM 信号的处理函数
    if (signal(SIGALRM, alarm_handler) == SIG_ERR)
    {
        perror("信号注册失败");
        return 1;
    }

    printf("闹钟程序已启动，每 3 秒提示一次。\n");
    printf("请输入 's' 并按下回车键停止闹钟：\n");

    // 2. 启动第一次 3 秒后的定时器
    alarm(3);

    // 3. 主循环：等待并检测用户输入
    while (1)
    {
        ch = getchar(); // 阻塞等待用户输入字符

        // 如果输入的是小写 's' 或大写 'S'
        if (ch == 's' || ch == 'S')
        {
            printf("检测到输入 's'，闹钟关闭。\n");
            alarm(0); // 传入 0 表示取消当前所有未决的闹钟
            break;    // 退出循环，结束程序
        }
    }

    return 0;
}