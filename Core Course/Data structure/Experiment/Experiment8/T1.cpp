#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
int n, x;
bool check(long long h)
{
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        long long d = h - a[i];
        if (d > 0)
            sum += d;
    }
    return sum <= x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long l = 0, r = 1e10;
        while (l <= r)
        {
            long long mid = (l + r) >> 1;
            if (check(mid))
                l = mid + 1;
            else
                r = mid - 1;
        }
        cout << r << "\n";
    }
    return 0;
}