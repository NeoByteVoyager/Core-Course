#include <bits/stdc++.h>
using namespace std;
int a[] = {2, 6, 3, 8, 3, 5, 7, 9};
int t[8];
void merge(int a[], int l1, int r1, int l2, int r2)
{
    int i = l1, j = l2, k = l1;
    while (i <= r1 || j <= r2)
    {
        if (j > r2 || (i <= r1 && a[i] <= a[j]))
        {
            t[k] = a[i];
            i++, k++;
        }
        else
        {
            t[k] = a[j];
            j++, k++;
        }
    }
    for (int i = l1; i <= r2; i++)
    {
        a[i] = t[i];
    }
}
// 自上朝下
void mergeSort(int a[], int l, int r)
{
    if (r > l)
    {
        int m = (l + r) >> 1;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, m + 1, r);
    }
}
int main()
{
    mergeSort(a, 0, 7);
    for (int i = 0; i <= 7; i++)
        cout << a[i] << " ";
    return 0;
}