#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a;
vector<vector<int>> edges;
int res = 0;
void dfs(int p, int u, int now)
{
    if (now > m)
        return;                                   // 这条路不行(连续猫个数超过m)
    if (edges[u].size() == 1 && edges[u][0] == p) // 到达叶子节点
        res++;
    for (int v : edges[u])
    {
        if (v != p) // 不能再回到父节点

            if (a[v] == 0)
                dfs(u, v, 0);
            else
                dfs(u, v, now + 1);
    }
}
}
int main()
{
    cin >> n >> m;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    edges.resize(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(-1, 1, a[1]);
    cout << res;
    return 0;
}