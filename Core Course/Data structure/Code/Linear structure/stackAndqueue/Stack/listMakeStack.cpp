#include <bits/stdc++.h>
using namespace std;
typedef int Elemtype;
struct Stack
{
    Elemtype data;
    Stack *next;
    Stack(int val) : data(val), next(nullptr) {}
    Stack(int val, Stack *n) : data(val), next(n) {}
};

// 初始化
Stack *initStack()
{
    return new Stack(0);
}

// 压栈(为便于操作把头当作顶)
void Push(Stack *s, int val)
{
    Stack *t = new Stack(val, s->next);
    s->next = t;
}

// 出栈
void Pop(Stack *s, Elemtype *e)
{
    if (!s->next)
    {
        cout << "栈为空\n";
        return;
    }
    *e = s->next->data;
    Stack *t = s->next;
    s->next = t->next;
    delete t;
}

// 得到栈顶元素
void getTop(Stack *s, Elemtype *e)
{
    if (!s->next)
    {
        cout << "栈为空\n";
    }
    *e = s->next->data;
}

// 得到栈的大小
int getLength(Stack *s)
{
    Stack *p = s;
    int i = 0;
    while (p->next)
    {
        p = p->next;
        i++;
    }
    return i;
}

int main()
{
    Stack *st = initStack();
    Push(st, 1);
    Push(st, 2);
    Push(st, 3);

    cout << "栈的大小：" << getLength(st) << endl;

    Elemtype t;
    Pop(st, &t);
    cout << "出栈元素为：" << t << endl;

    getTop(st, &t);
    cout << "栈顶元素为：" << t << endl;

    return 0;
}