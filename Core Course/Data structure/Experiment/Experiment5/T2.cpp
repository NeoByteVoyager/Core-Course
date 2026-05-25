#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<unordered_map<int, int>> edges(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u][v] = 1;
        edges[v][u] = 1;
    }
    vector<int> seq(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> seq[i];

    queue<int> q;
    q.push(seq[1]);
    int p = 2; // 下一个要匹配的序列位置

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        int child_cnt = edges[u].size(); // 当前度数
        if (u != seq[1])
            child_cnt--; // BUG:非根节点要减去父节点
        for (int i = 0; i < child_cnt; i++)
        {

            int now = seq[p];
            if (!edges[u].count(now))
            {
                cout << "No";
                return 0;
            }
            edges[u].erase(now); // 直接在原始存储上删除，不用再copy一个副本
            q.push(now);
            p++;
        }
    }

    cout << "Yes";
    return 0;
}