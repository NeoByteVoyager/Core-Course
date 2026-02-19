#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char a[60];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n - 1; i++)
    {
        int maxPos = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] > a[maxPos])
                maxPos = j;

        if (maxPos != i)
        {
            char t = a[i];
            a[i] = a[maxPos];
            a[maxPos] = t;
        }
    }

    for (int i = 0; i < n; i++)
        cout << a[i];

    return 0;
}

