#include <iostream>
using namespace std;
class person
{
private:
    int no;      /* 人的编号 */
    person *next;   /* 指向相邻的下一个人 */
public:
    person(int num)
    {
        no=num;
        next=NULL;
    }
    void setNext(person *p)
    {
        next=p;
    }
    int getNo()
    {
        return no;
    }
    person *getNext()
    {
        return next;
    }
};

class cycle
{
private:
    person *start;    /* 开始数数的位置 */
    int out;          /* 数到几出列 */
    int inQueue;      /* 队伍中现有人数 */
public:
    cycle(int num, int from, int whoOut)
    {
        inQueue=num, out=whoOut;
        person *prv=NULL, *first=NULL;
        for(int i=1; i<=num; i++)
        {
            person *p=new person(i);
            if (i==1)
                first=p;
            if (i==from)
                start=p;
            if (i>1)
                prv->setNext(p);

            prv=p;
        }
        prv->setNext(first);
    }
    int getInQueue()
    {
        return inQueue;
    }
    void cnt()   /* 根据题目要求数数，确定出列的人，将该人从圈中剔除 */
    {
  
    person* cur = start;

    // 找到 start 的前驱（out == 1 时必须）
    while (cur->getNext() != start)
        cur = cur->getNext();

    // 从 start 开始，走到出列者前一个
    for (int i = 1; i <= out - 1; i++)
        cur = cur->getNext();

    person* del = cur->getNext();   // 出列者
    cur->setNext(del->getNext());

    start = del->getNext();         // 从下一个继续数
    delete del;
    inQueue--;



    }

    person *getStart()
    {
        return start;
    }

    ~cycle()
    {
        delete start;
    }
};

int main()
{
    int n,k, m ;   /* n 圈内人数  k 开始数数 m 可数出列 */
    cin>>n>>k>>m;

    cycle *p=new cycle(n,k,m);

    while(p->getInQueue()>1)
        p->cnt();

    person *winer=p->getStart();
    cout<<winer->getNo()<<endl;

    delete p;

    return 0;
}

