#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int p[maxn];
int n, m;
void init()
{
    for (int i = 1; i <= n; i++)
        p[i] = i;
}
int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}
void Union(int u, int v)
{
    int fu = find(u), fv = find(v);
    if (fu != fv)
        p[fu] = fv;
}
int main()
{
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        init();
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            Union(u, v);
        }
        int pa = find(1);
        bool ok = true;
        for (int i = 2; i <= n; i++)
        {

            if (find(i) != pa)
            {
                ok = false;
                break;
            }
        }

        if (ok)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}