#include <bits/stdc++.h>
using namespace std;
int a[] = {2, 6, 3, 8, 3, 5, 7, 6};
void insertSort(int a[], int l, int r)
{
    for (int i = l + 1; i <= r; i++)
    {
        // 选择第一个无序的元素在有序序列的位置
        int t = a[i]; // 保存当前元素
        int j;
        for (j = i; j >= l + 1; j--)
        {
            if (a[j - 1] > t) // 保证j左边的元素都要小于等于t，可以保持稳定性
                a[j] = a[j - 1];
            else
                break;
        }
        a[j] = t;
    }
}

int main()
{
    insertSort(a, 2, 6);
    for (int i = 2; i <= 6; i++)
        cout << a[i] << " ";
}