#include <bits/stdc++.h>
using namespace std;
int a[] = {2, 6, 3, 8, 3, 5, 7, 9};
int t[8];
void merge(int a[], int t[], int l1, int r1, int l2, int r2)
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
}
// 自底向上
void mergeSort(int a[], int l, int r)
{
    int len = r - l + 1;
    int sortedLen = 1;
    int count = 1;
    while (sortedLen < len)
    {
        int l1 = l;
        while (l1 <= r - sortedLen)
        {
            int r1 = l1 + sortedLen - 1;
            int l2 = r1 + 1;
            int r2 = min(r, l2 + sortedLen - 1);
            if (count % 2)
            {
                merge(a, t, l1, r1, l2, r2);
            }
            else
            {
                merge(t, a, l1, r1, l2, r2);
            }
            l1 = r2 + 1; // bug
        }
        // bug
        if (l1 <= r)
        {
            for (int i = l1; i <= r; i++)
            {
                if (count % 2)
                    t[i] = a[i];
                else
                    a[i] = t[i];
            }
        }
        count++;
        sortedLen <<= 1;
    }
    // error
    if (count % 2 == 0)
    {
        for (int i = l; i <= r; i++)
            a[i] = t[i];
    }
}
int main()
{
    mergeSort(a, 0, 7);
    for (int i = 0; i <= 7; i++)
        cout << a[i] << " ";
    return 0;
}