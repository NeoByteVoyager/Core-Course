#include <bits/stdc++.h>
using namespace std;
const int n = 10;
int a[] = {2, 6, 3, 8, 3, 5, 7, 6, 2, 5};
void selectSort(int a[], int l, int r)
{
    for (int i = l; i < r; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j <= r; j++)
        {
            if (a[j] < a[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(a[i], a[min_idx]);
    }
}

int main()
{
    selectSort(a, 0, n - 1);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
}