#include <bits/stdc++.h>
using namespace std;
const int n = 10;
int a[] = {2, 6, 3, 8, 3, 5, 7, 6, 2, 5};
const int dn = 3;
int d[] = {5, 3, 1};
void insertSort(int a[], int l, int r, int d)
{
    // 插入排序的1全部变成d
    for (int i = l + d; i <= r; i++) // 这里每次走一步
    {
        // 选择第一个无序的元素在有序序列的位置
        int t = a[i]; // 保存当前元素
        int j;
        for (j = i; j >= l + d; j -= d) // 这里每次走d步
        {
            if (a[j - d] > t)
                a[j] = a[j - d];
            else
                break;
        }
        a[j] = t;
    }
}
void shellSort(int a[], int l, int r)
{
    for (int i = 0; i < dn; i++)
    {
        insertSort(a, l, r, d[i]);
    }
}

int main()
{
    shellSort(a, 0, 9);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
}