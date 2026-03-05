#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib> // rand, srand
#include <ctime>   // time
#include <algorithm> // random_shuffle

using namespace std;

// --- 配置区域 ---
const int MIN_N = 5;   // 最小顶点数
const int MAX_N = 20;  // 最大顶点数（分支限界法建议不要超过30）
// ----------------

int main() {
    // 1. 初始化随机种子
    srand((unsigned)time(NULL));

    // 2. 打开文件
    ofstream outfile("input.txt");
    if (!outfile.is_open()) {
        cerr << "无法打开文件 input.txt" << endl;
        return 1;
    }

    // 3. 随机生成 N
    int n = 15;

    // 4. 生成所有可能的边 (完全图)
    // 这样做是为了方便从中随机抽取 m 条边，避免生成重复边
    vector<pair<int, int>> all_edges;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            all_edges.push_back({i, j});
        }
    }

    // 5. 随机决定边数 m
    // 范围：[1, 所有可能边数]
    // 为了让图稍微稠密一点，通常题目不会给太稀疏的图
    long long max_edges = all_edges.size();
    if (max_edges == 0) max_edges = 1; // 防止 n=1 时崩溃
    
    // 这里生成 1 到 max_edges 之间的随机数
    int m = rand() % max_edges + 1;

    // 6. 打乱所有可能的边，取前 m 条
    // random_shuffle 在 C++14 后被标记为过时，但为了兼容老编译器和简单起见这里依然使用
    // 如果是 C++17 及以上，建议用 shuffle 和 mt19937
    random_shuffle(all_edges.begin(), all_edges.end());

    cout << "生成测试用例: N=" << n << ", M=" << m << endl;

    // 7. 写入文件
    outfile << n << " " << m << endl;
    for (int i = 0; i < m; i++) {
        outfile << all_edges[i].first << " " << all_edges[i].second << endl;
    }

    outfile.close();
    cout << "已写入 input.txt" << endl;

    return 0;
}
