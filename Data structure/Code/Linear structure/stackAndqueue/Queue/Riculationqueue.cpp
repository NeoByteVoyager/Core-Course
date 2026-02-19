#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 4
typedef int Elemtype;
struct Queue
{
    Elemtype *data;
    int front;
    int rear;
};
// 初始化
Queue *init()
{
    Queue *q = new Queue; // 先要创建队列
    q->data = new Elemtype[MAXSIZE];
    q->front = q->rear = 0;
    return q;
}
// 判断队列是否已满
bool isFull(Queue *q)
{
    return (q->rear + 1) % MAXSIZE == q->front;
}
// 判断队列是否空的
bool isEmpty(Queue *q)
{
    return q->rear == q->front;
}
// 获取对头元素
bool Front(Queue *q, Elemtype *e)
{
    if (isEmpty(q))
    {
        cout << "该队列是空队列\n";
        return false;
    }
    *e = q->data[q->front];
    return true;
}

// 添加元素
bool Push(Queue *q, Elemtype e)
{
    if (isFull(q))
    {
        return false;
    }
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % MAXSIZE;
    return true;
}
// 删除元素
bool Pop(Queue *q, Elemtype *e)
{
    if (isEmpty(q))
    {
        cout << "空队列\n";
        return false;
    }
    *e = q->data[q->front];
    q->front = (q->front + 1) % MAXSIZE;
    return true;
}

int main()
{
    Queue *q = init();
    Push(q, 10);
    Push(q, 20);
    Push(q, 30);
    Push(q, 40);
    // cout << q->front << " " << q->rear << endl;
    Elemtype e;
    Front(q, &e);
    cout << e << endl;
    Pop(q, &e);
    cout << e << endl;
    Pop(q, &e);
    cout << e << endl;
    Pop(q, &e);
    cout << e << endl;
    Pop(q, &e);
    cout << e << endl;
    return 0;
}