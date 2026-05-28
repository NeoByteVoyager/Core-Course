#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> edges(n + 1); // 邻接表
vector<int> vis(n + 1);           // 记录状态
vector<int> ans(n + 1);           // 记录答案
void dfs1(int u)
{
    vis[u] = 1; // 从u出发能访问的到的点设置为1,不妨看作入栈
    ans[u] = 1;
    for (int v : edges[u])
    {
        if (!vis[v])
            dfs1(v);
        else if (vis[v] == 1)
        { // 再次回到v，说明有环
            ans[v] = -1;
        }
    }
    vis[u] = 2; // 不妨看作出栈
}
void dfs2(int u)
{
    vis[u] = 1;
    ans[u] = -1;
    for (int v : edges[u])
    {
        if (!vis[v])
            dfs2(v);
    }
}
void dfs3(int u)
{
    vis[u] = 1;
    for (int v : edges[u])
    {
        if (ans[v] == -1)
            continue;
        else if (!vis[v])
        {
            dfs3(v);
        }
        else if (vis[v] == 1)
        {
            if (ans[v] != 2)
            {
                ans[v] = 2;
                dfs3(v);
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    edges.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);
    ans.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
    }
    // 第一次判断是否有环和可达性
    dfs1(1);
    vis.assign(n + 1, 0);
    // 如果有环，那么环起点的下游都有无限条路径
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == -1 && !vis[i])
        {
            dfs2(i);
        }
    }
    // 判断节点是否有多条路径
    vis.assign(n + 1, 0);
    dfs3(1);

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}