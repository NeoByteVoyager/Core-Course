#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a;
bool check(int mid)
{
    int cnt = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > mid)
            return false;
        if (sum + a[i] > mid)
        {
            cnt++;
            sum = a[i];
        }
        else
            sum += a[i];
    }
    cnt++;
    return cnt <= m;
}
int main()
{
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 1, r = 1e9;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (check(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << l;
    return 0;
}