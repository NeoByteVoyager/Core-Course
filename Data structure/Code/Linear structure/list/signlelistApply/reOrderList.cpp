#include <bits/stdc++.h>
using namespace std;
typedef int Elemtype;
struct Node
{
    Elemtype data;
    Node *next;
    Node() {}
    Node(int val) : data(val), next(nullptr) {}
    Node(int val, Node *nxt) : data(val), next(nxt) {}
};
// 初始化
Node *initList()
{
    Node *head = new Node(0, nullptr);
    return head;
}
// 头插法
int insertHead(Node *L, Elemtype e)
{
    // 先连接后面，不然链表直接断裂
    Node *p = new Node(e, L->next);
    L->next = p;
    return 1;
}
Node *get_tail(Node *L)
{
    if (!L)
        return L;
    Node *p = L;
    while (p->next)
    {
        p = p->next;
    }
    return p;
}
// 尾插法
Node *insertTail(Node *p, Elemtype e)
{
    Node *newtail = new Node(e, nullptr);
    p->next = newtail;
    return newtail;
}

// 遍历
void listNode(Node *L)
{
    Node *p = L->next;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 在指定位置插入节点
int insertNode(Node *L, int pos, Elemtype e)
{
    // 先找到前驱节点
    Node *p = L;
    int i = 0;
    while (i < pos - 1)
    {
        p = p->next;
        i++;
    }
    Node *q = new Node(e, p->next);
    p->next = q;
    return 1;
}
// 删除节点
int deleteNode(Node *L, int pos)
{
    // 先找到要删除节点的前驱
    Node *p = L;
    int i = 0;
    while (i < pos - 1)
    {
        p = p->next;
        i++;
    }
    Node *toDel = p->next;
    p->next = toDel->next;
    delete toDel;
    return 1;
}
// 获取链表长度
int getLength(Node *L)
{
    int i = 0;
    Node *p = L->next;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}

// 重排链表
void reOrderList(Node *L)
{
    if (!L || !L->next || !L->next->next)
        return;
    // 用slow找到中间节点的前一个节点
    Node *fast = L->next, *slow = L;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *prev = nullptr, *cur = slow->next;
    slow->next = nullptr;
    while (cur)
    {
        Node *nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    Node *p1 = L->next, *q1 = prev;
    Node *p2, *q2;
    while (p1 && q1)
    {
        p2 = p1->next;
        q2 = q1->next;
        p1->next = q1;
        if (!p2) // 如果是奇数的话多出来的一个在反转部分,q1不再指向p2（nullptr）
            break;
        q1->next = p2;
        p1 = p2;
        q1 = q2;
    }
}

// 释放链表
void freeList(Node *L)
{
    Node *p = L->next;
    Node *q;
    while (p)
    {
        q = p->next;
        delete p;
        p = q;
    }
    L->next = nullptr;
}
int main()
{
    Node *head = new Node(0);
    Node *tail = get_tail(head);
    tail = insertTail(tail, 1);
    tail = insertTail(tail, 2);
    tail = insertTail(tail, 3);
    tail = insertTail(tail, 4);
    tail = insertTail(tail, 5);
    tail = insertTail(tail, 6);

    listNode(head);
    reOrderList(head);
    listNode(head);

    return 0;
}