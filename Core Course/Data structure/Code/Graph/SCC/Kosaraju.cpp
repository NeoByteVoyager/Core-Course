#include <bits/stdc++.h>
using namespace std;

// edges  存储原图 G
// edges_r 存储逆向图 Gr（Kosaraju 算法的核心）
vector<vector<int>> edges;
vector<vector<int>> edges_r;
vector<bool> visited;

// 用来存储第一步“后序遍历”结果的序列（也可以用 stack<int>）
vector<int> post_order;
// 第一次后序遍历获取后序遍历序列
void dfs1(int u)
{
    for (int v : edges[u])
    {
        if (!visited[v])
        {
            visited[v] = true;
            dfs1(v);
        }
    }
    post_order.push_back(u);
}
void dfs2(int u)
{
    cout << u << " ";
    for (int v : edges_r[u])
    {
        if (!visited[v])
        {
            visited[v] = true;
            dfs2(v);
        }
    }
}
int main()
{
    // 初始化节点数量，0号不用，使用 1 ~ 6 号节点
    int n = 6;
    edges.resize(n + 1);
    edges_r.resize(n + 1);
    visited.resize(n + 1, false);

    // ==========================================
    // 构造一个包含 3 个强连通分量的图：
    // 分量 1: {1, 2, 3} 形成一个环
    // 分量 2: {4, 5} 形成一个双向通道
    // 分量 3: {6} 孤立点
    // 桥梁: 1->4, 4->6 (只能单向过去)
    // ==========================================

    // 分量 1 内部的边
    edges[1].push_back(2);
    edges_r[2].push_back(1);
    edges[2].push_back(3);
    edges_r[3].push_back(2);
    edges[3].push_back(1);
    edges_r[1].push_back(3);

    // 连接分量 1 和分量 2 的桥梁
    edges[1].push_back(4);
    edges_r[4].push_back(1);

    // 分量 2 内部的边
    edges[4].push_back(5);
    edges_r[5].push_back(4);
    edges[5].push_back(4);
    edges_r[4].push_back(5);

    // 连接分量 2 和分量 3 的桥梁
    edges[4].push_back(6);
    edges_r[6].push_back(4);

    // 此时图已经建好了！
    // 正确的 SCC 结果应该是：{1, 2, 3}、{4, 5}、{6}

    // 先dfs1一次获取每个节点的顺序
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs1(i);
        }
    }
    // for (int i : post_order)
    //     cout << i << " ";
    // 重置visted函数
    for (int i = 1; i <= n; i++)
        visited[i] = false;
    for (int i = n - 1; i >= 0; i--)
    {
        int u = post_order[i];
        if (!visited[u])
        {
            cout << "连通分量：";
            visited[u] = true;
            dfs2(u);
            cout << endl;
        }
    }
    return 0;
}