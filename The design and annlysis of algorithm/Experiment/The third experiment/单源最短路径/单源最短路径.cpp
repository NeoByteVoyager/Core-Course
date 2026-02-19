#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

struct Edge {
    int to;     // 目标节点
    int weight; // 边权重
};

vector<int> dijkstra(const vector<vector<Edge>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INF);      // 距离数组
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int curDist = cur.first;
        int u = cur.second;
        
        // 跳过过时数据（已找到更优路径）
        if (curDist > dist[u]) continue;
        
        // 松弛操作
        for (const auto& edge : graph[u]) {
            int v = edge.to;
            int newDist = curDist + edge.weight;
            
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }
    
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("large_star.txt");
	ofstream fout("output.txt"); 
    int n, m, s;
    if (!(fin >> n >> m >> s)) return 0;
    
    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        fin >> u >> v >> w;
        graph[u].push_back({v, w});
        // 无向图需添加：graph[v].push_back({u, w});
    }
    
    clock_t st = clock();
    vector<int> distances = dijkstra(graph, s);
    clock_t ed = clock();
    
    // 输出距离
    fout << "从节点" << s << "到各点的最短距离:\n";
    for (int i = 1; i <= n; i++) {
        if (distances[i] == INF) fout << i << ": INF\n";
        else fout << i << ": " << distances[i] << "\n";
    }
    
    // 程序运行时间
    cout<<"数据规模:"<< n<<endl;
    cout << fixed << setprecision(12);
    cout << "程序运行时间: " << (double)(ed - st) / CLOCKS_PER_SEC << "秒\n";
    
    return 0;
}
