#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> p, sz;
// 并查集
void init()
{
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        sz[i] = 1;
    }
}
int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}
void Union(int fu, int fv)
{
    if (sz[fu] > sz[fv])
    {
        p[fv] = fu;
    }
    else if (sz[fu] < sz[fv])
    {
        p[fu] = fv;
    }
    else
    {
        p[fu] = fv;
        sz[fv]++;
    }
}
struct Edges
{
    int u, v, w;
};
int main()
{
    cin >> n >> m;
    vector<Edges> e(m);
    for (int i = 0; i < m; i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    p.resize(n + 1), sz.resize(n + 1);
    sort(e.begin(), e.end(), [](auto &x, auto &y)
         { return x.w < y.w; });
    init();
    int cnt = 0, cost = 0;
    for (int i = 0; i < m; i++)
    {

        int u = e[i].u, v = e[i].v;
        int fu = find(u), fv = find(v);
        if (fu == fv)
            continue;
        else
        {
            cnt++;
            cost += e[i].w;
            Union(fu, fv);
        }
        if (cnt == n - 1)
            break;
    }
    cout << cost;
    return 0;
}