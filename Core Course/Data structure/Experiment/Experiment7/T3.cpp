#include <bits/stdc++.h>
using namespace std;
int n, q, s, t; // 正数下降s，负数上升t
vector<long long> a, diff;
long long f(long long x)
{
    return x >= 0 ? -x * s : -x * t;
}
int main()
{
    cin >> n >> q >> s >> t;
    a.resize(n + 1);
    for (int i = 0; i <= n; i++)
        cin >> a[i];
    diff.resize(n);
    long long res = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        diff[i] = a[i + 1] - a[i];
        res += f(diff[i]);
    }
    // cout << res;
    long long l, r, x;
    while (q--)
    {
        cin >> l >> r >> x;
        long long new_l = diff[l - 1] + x;
        res += f(new_l) - f(diff[l - 1]);
        diff[l - 1] = new_l;
        if (r <= n - 1)
        {
            long long new_r = diff[r] - x;
            res += f(new_r) - f(diff[r]);
            diff[r] = new_r;
        }
        cout << res << endl;
    }
    return 0;
}