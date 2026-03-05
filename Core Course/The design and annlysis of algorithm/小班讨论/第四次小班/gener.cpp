#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <set>
#include <algorithm>

using namespace std;

// ================= 配置区域 =================
const int NUM_VERTICES = 30;   // 顶点数量 (N)
const int NUM_EDGES = 45;      // 边数量 (M)，注意 M 不能超过 N*(N-1)/2
const int MAX_WEIGHT = 100;    // 最大权值
const string FILENAME = "input.txt";
// ===========================================

int main() {
    // 初始化随机数种子
    srand(time(0));

    ofstream fout(FILENAME);
    if (!fout.is_open()) {
        cerr << "Error: Cannot open " << FILENAME << " for writing." << endl;
        return 1;
    }

    // 1. 输出 N 和 M
    int n = NUM_VERTICES;
    int m = NUM_EDGES;
    
    // 简单的防死循环检查：如果 m 超过了完全图的边数，强制截断
    long long max_possible_edges = (long long)n * (n - 1) / 2;
    if (m > max_possible_edges) {
        cout << "Warning: Edges reduced to max possible (" << max_possible_edges << ")" << endl;
        m = max_possible_edges;
    }

    fout << n << " " << m << endl;

    // 2. 生成并输出顶点权值
    cout << "Generating weights..." << endl;
    for (int i = 0; i < n; ++i) {
        // 生成 1 到 MAX_WEIGHT 之间的随机数
        int w = rand() % MAX_WEIGHT + 1;
        fout << w << (i == n - 1 ? "" : " ");
    }
    fout << endl;

    // 3. 生成并输出不重复的边
    cout << "Generating edges..." << endl;
    set<pair<int, int>> edges;
    
    while (edges.size() < m) {
        int u = rand() % n + 1; // 1 到 n
        int v = rand() % n + 1; // 1 到 n

        if (u == v) continue; // 不允许自环

        // 保证 u < v 以便去重 (无向图 1-2 和 2-1 是同一条边)
        if (u > v) swap(u, v);

        // 如果边不存在，则插入
        if (edges.find({u, v}) == edges.end()) {
            edges.insert({u, v});
            fout << u << " " << v << endl;
        }
    }

    fout.close();
    cout << "Success! Generated " << n << " vertices and " << m << " edges in " << FILENAME << endl;

    return 0;
}
