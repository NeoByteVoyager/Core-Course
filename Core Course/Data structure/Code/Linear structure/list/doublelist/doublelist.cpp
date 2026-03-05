#include <bits/stdc++.h>
using namespace std;
typedef int Elemtype;
struct Node
{
    Elemtype data;
    Node *prev, *next;
    Node(Elemtype val) : data(val), prev(nullptr), next(nullptr) {}
    Node(Elemtype val, Node *p, Node *n) : data(val), prev(p), next(n) {}
};

// 头插法
void insertHead(Node *L, Elemtype e)
{
    Node *p = new Node(e, L, L->next);
    if (L->next)
    {
        L->next->prev = p;
    }
    L->next = p;
}

// 找到尾节点
Node *get_tail(Node *L)
{
    if (!L->next)
        return L;
    Node *p = L->next;
    while (p->next)
    {
        p = p->next;
    }
    return p;
}

// 尾插法
Node *insertTail(Node *tail, Elemtype e)
{
    Node *p = new Node(e);
    p->prev = tail;
    tail->next = p;
    return p;
}

// 在指定位置插入节点
void insertNode(Node *L, int pos, Elemtype e)
{
    // 先找前置节点
    Node *p = L;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
    }

    Node *t = new Node(e, p, p->next);
    p->next->prev = t;
    p->next = t;
}

// 删除特定节点
void deleteNode(Node *L, int pos)
{
    Node *p = L;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
    }
    Node *q = p->next;
    p->next = q->next;
    q->next->prev = p;
}

// 遍历链表
void ListNode(Node *L)
{
    Node *p = L;
    while (p->next)
    {
        cout << p->next->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    Node *L = new Node(0);
    insertHead(L, 1);
    insertHead(L, 2);
    insertHead(L, 3);
    ListNode(L);

    Node *tail = get_tail(L);
    tail = insertTail(tail, 4);
    tail = insertTail(tail, 5);
    ListNode(L);

    insertNode(L, 2, 15);
    ListNode(L);

    deleteNode(L, 2);
    ListNode(L);
}
