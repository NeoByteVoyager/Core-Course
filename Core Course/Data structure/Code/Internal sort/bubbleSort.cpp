#include <bits/stdc++.h>
using namespace std;
int a[] = {2, 6, 3, 8, 3, 5, 7, 6};
void bubbleSort(int a[], int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        for (int j = r - 1; j >= l; j--)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

int main()
{
    bubbleSort(a, 0, 7);
    for (int i = 0; i <= 7; i++)
        cout << a[i] << " ";
}