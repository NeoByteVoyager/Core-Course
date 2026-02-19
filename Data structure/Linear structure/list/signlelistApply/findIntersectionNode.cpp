#include <bits/stdc++.h>
using namespace std;
typedef char Elemtype;
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
// 获取后缀的代码
char findIntersectionNode(Node *listA, Node *listB)
{
    if (!listA->next || !listB->next)
        return 'N';
    // 获取listA的长度
    Node *p = listA->next;
    int m = 0;
    while (p)
    {
        m++;
        p = p->next;
    }
    // 获取listB的长度
    Node *q = listB->next;
    int n = 0;
    while (q)
    {
        n++;
        q = q->next;
    }
    // 声明快慢指针
    Node *fast;
    Node *slow;
    int step;
    if (m >= n)
    {
        fast = listA->next;
        slow = listB->next;
        step = m - n;
    }
    else
    {
        fast = listB->next;
        slow = listA->next;
        step = n - m;
    }
    // 先让快指针走step步
    for (int i = 0; i < step; i++)
    {
        fast = fast->next;
    }
    while (fast && slow && fast->data != slow->data)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast->data;
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
    // 先建立链表loading,being
    Node *listA = new Node('0'), *listB = new Node('0');
    Node *tailA = listA;
    Node *tailB = listB;

    tailA = insertTail(tailA, 'l');
    tailA = insertTail(tailA, 'o');
    tailA = insertTail(tailA, 'a');
    tailA = insertTail(tailA, 'd');

    tailB = insertTail(tailB, 'b');
    tailB = insertTail(tailB, 'e');

    Node *t = new Node('i');
    tailA->next = t;
    tailB->next = t;
    tailA = tailB = t;
    Node *m = new Node('n');
    tailA->next = m;
    tailB->next = m;
    tailA = tailB = m;
    Node *n = new Node('g');
    tailA->next = n;
    tailB->next = n;
    tailA = tailB = n;

    listNode(listA);
    listNode(listB);

    cout << "两个单词的共同后缀起始字母是:" << findIntersectionNode(listA, listB) << endl;
    cout << "两个单词的共同后缀起始字母是:" << findIntersectionNode(listB, listA) << endl;

    return 0;
}