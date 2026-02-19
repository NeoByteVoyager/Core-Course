/*
和数组相类似,但是删除和修改数据时不方便，需要移动所有数据
*/
#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 100
typedef int ElemType;
struct SeqList
{
    ElemType data[MAXSIZE];
    int length;
};

// Initialize the sequential list
void InitList(SeqList *L)
{
    L->length = 0;
}

// Append an element to the end of the list
int appendElem(SeqList *L, ElemType e)
{
    if (L->length >= MAXSIZE)
        return -1; // List is full
    L->data[L->length] = e;
    L->length++;
    return 0; // Success
}

// 遍历
void listElem(SeqList *L)
{
    cout << "顺序表的长度:" << L->length << endl;
    cout << "顺序表中的元素：" << endl;
    for (int i = 0; i < L->length; i++)
        cout << L->data[i] << " ";
    cout << endl;
}

// 插入元素
int intsertElem(SeqList *L, int pos, ElemType e)
{
    if (pos <= L->length)
    {
        for (int i = L->length; i >= pos - 1; i--)
        {
            L->data[i + 1] = L->data[i];
        }
        L->data[pos - 1] = e;
        L->length++;
    }
    return 1;
}
// 删除元素
int deleteElem(SeqList *L, int pos, ElemType *e)
{
    *e = L->data[pos - 1];
    if (L->length)
    {
        for (int i = pos; i < L->length; i++)
        {
            L->data[i - 1] = L->data[i];
        }
    }
    L->length--;
    return 1;
}
// 查找
int findElem(SeqList *L, ElemType e)
{
    for (int i = 0; i < L->length; i++)
    {
        if (e == L->data[i])
        {
            return i + 1;
        }
    }
    return -1;
}

int main()
{
    SeqList L;
    InitList(&L);
    cout << "L.size():" << L.length << endl;
    cout << "L占用的内存:" << sizeof(L) << endl;
    appendElem(&L, 5);
    appendElem(&L, 10);
    appendElem(&L, 15);
    listElem(&L);
    intsertElem(&L, 2, 8);
    listElem(&L);
    ElemType del;
    deleteElem(&L, 2, &del);
    cout << "删除的元素值:" << del << endl;
    listElem(&L);
    cout << 15 << "在顺序表中的位置为:" << findElem(&L, 15) << endl;

    return 0;
}