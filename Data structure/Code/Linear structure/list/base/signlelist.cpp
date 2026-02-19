#include <bits/stdc++.h>
using namespace std;
typedef int Elemtype;
struct Node
{
    Elemtype data;
    Node *next;
    Node() {}
    Node(int val) : data(val) {}
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
    Node *p = L->next;
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
// 找到链表倒数第三个位置的值
int findFS(Node *L, int k)
{ // 这里假设保证链表的长度大于等于k
    Node *fast = L->next, *slow = L->next;
    int i = 0;
    while (i < k)
    {
        fast = fast->next;
        i++;
    }
    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->data;
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
    Node *L = initList();
    insertHead(L, 1);
    insertHead(L, 2);
    listNode(L);

    Node *tail = get_tail(L);
    tail = insertTail(tail, 3);
    tail = insertTail(tail, 4);
    listNode(L);

    insertNode(L, 2, 5);
    insertNode(L, 3, 15);
    listNode(L);

    deleteNode(L, 2);
    listNode(L);
    deleteNode(L, 2);
    listNode(L);

    cout << "当前链表长度:" << getLength(L) << endl;

    cout << "链表倒数第三个数字为:" << findFS(L, 3) << endl;

    freeList(L);
    cout << getLength(L) << endl;
    return 0;
}