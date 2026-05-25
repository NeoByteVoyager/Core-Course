#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> child;
vector<int> p, c;
vector<bool> d; // 节点是否要删除
int n, root;
void dfs(int u)
{
    bool ok = true;
    for (int v : child[u])
    {
        if (!c[v])
            ok = false;
        dfs(v);
    }
    if (ok && c[u])
        d[u] = true;
}
// void update(int u){ //把u删除了,同时要更新u的父母节点的状态

// }
int main()
{
    cin >> n;
    child.resize(n + 1);
    p.resize(n + 1);
    d.resize(n + 1);
    c.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i] >> c[i];
        if (p[i] == -1)
            root = i;
        else
        {
            child[p[i]].push_back(i);
        }
    }
    // cout << "root:" << root << endl;
    dfs(root);
    bool ok = false;
    for (int i = 1; i <= n; i++)
    {
        if (d[i])
        {
            ok = true;
            cout << i << " ";
            // update(i);
        }
    }
    if (!ok)
        cout << -1;
    return 0;
}