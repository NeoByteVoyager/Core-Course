#include <bits/stdc++.h>
using namespace std;
int a[] = {2, 6, 3, 8, 3, 5, 7, 9};
int partition(int a[], int l, int r)
{

    int i = l, j = r - 1;
    while (true)
    {
        // 找到左侧第一个大于等于a[r]的元素
        while (a[i] < a[r])
            i++;
        // 找到右侧第一个小于等于a[r]的元素
        while (j > i && a[j] > a[r])
            j--;

        if (i >= j)
            break;
        swap(a[i], a[j]);
        i++, j--;
    }
    return i;
}
void quickSort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int i = partition(a, l, r);
    swap(a[i], a[r]);
    quickSort(a, l, i - 1);
    quickSort(a, i + 1, r);
}
int main()
{
    quickSort(a, 0, 7);
    for (int i = 0; i <= 7; i++)
        cout << a[i] << " ";
}