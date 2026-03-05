#include <bits/stdc++.h>
using namespace std;
typedef int Elemtype;
struct Node
{
    Elemtype data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};
struct Queue
{
    Node *front;
    Node *rear;
};
// 判断是否为非空
bool isEmpty(Queue *q)
{
    return q->front == q->rear;
}
// 初始化
Queue *init()
{
    Node *dummy = new Node(0);
    Queue *q = new Queue;
    q->front = q->rear = dummy;
    return q;
}
// 添加节点
void Push(Queue *q, Elemtype e)
{
    q->rear->next = new Node(e);
    q->rear = q->rear->next;
}
// 删除节点
bool Pop(Queue *q, Elemtype *e)
{
    if (isEmpty(q))
    {
        cout << "队列为空队列\n";
        return false;
    }
    Node *node = q->front->next;
    *e = node->data;
    q->front->next = node->next;
    if (q->rear == node)
    {
        q->rear = q->front;
    }
    delete node;
    return true;
}
// 取队头元素
bool Front(Queue *q, Elemtype *e)
{
    if (isEmpty(q))
    {
        cout << "队列为空队列\n";
        return false;
    }
    *e = q->front->data;
    return true;
}
int main()
{
    Queue *q = init();
    Elemtype e = 0;
    Front(q, &e);
    cout << e << endl;
    Push(q, 10);
    Push(q, 20);
    Push(q, 30);

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