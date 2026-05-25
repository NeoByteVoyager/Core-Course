#include <bits/stdc++.h>
using namespace std;

const int maxn = 2005;
const long long INF = 1e18;
int graph[maxn][maxn];
long long dist1[maxn][maxn], dist2[maxn][maxn];
int n, m, w;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void dijkstra(int sx, int sy, long long dist[][maxn])
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dist[i][j] = INF;
    dist[sx][sy] = 0;
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;
    pq.emplace(0, sx, sy);
    while (!pq.empty())
    {
        auto [d, x, y] = pq.top();
        pq.pop();
        if (d > dist[x][y])
            continue;
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 1 || nx > n || ny < 1 || ny > m)
                continue;
            if (graph[nx][ny] == -1)
                continue;
            long long nd = d + w;
            if (nd < dist[nx][ny])
            {
                dist[nx][ny] = nd;
                pq.emplace(nd, nx, ny);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> w;
    vector<pair<int, int>> portals;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] > 0)
                portals.emplace_back(i, j);
        }
    }

    dijkstra(1, 1, dist1);
    dijkstra(n, m, dist2);

    long long ans = dist1[n][m]; // 不使用传送

    // 传送门部分：计算 min(start_cost) 和 min(end_cost)
    long long min1_start = INF, min2_start = INF;
    int idx1_start = -1, idx2_start = -1;
    long long min1_end = INF, min2_end = INF;
    int idx1_end = -1, idx2_end = -1;

    for (int i = 0; i < portals.size(); i++)
    {
        auto [x, y] = portals[i];
        if (dist1[x][y] != INF)
        {
            long long val = dist1[x][y] + graph[x][y];
            // 更新 start 侧的最小和次小
            if (val < min1_start)
            {
                min2_start = min1_start;
                idx2_start = idx1_start;
                min1_start = val;
                idx1_start = i;
            }
            else if (val < min2_start)
            {
                min2_start = val;
                idx2_start = i;
            }
        }
        if (dist2[x][y] != INF)
        {
            long long val = dist2[x][y] + graph[x][y];
            if (val < min1_end)
            {
                min2_end = min1_end;
                idx2_end = idx1_end;
                min1_end = val;
                idx1_end = i;
            }
            else if (val < min2_end)
            {
                min2_end = val;
                idx2_end = i;
            }
        }
    }

    // 尝试组合
    if (idx1_start != -1 && idx1_end != -1)
    {
        if (idx1_start != idx1_end)
        {
            ans = min(ans, min1_start + min1_end);
        }
        else
        {
            // 尝试用次小组合
            if (idx2_start != -1)
                ans = min(ans, min2_start + min1_end);
            if (idx2_end != -1)
                ans = min(ans, min1_start + min2_end);
        }
    }

    if (ans >= INF)
        cout << -1 << '\n';
    else
        cout << ans << '\n';

    return 0;
}