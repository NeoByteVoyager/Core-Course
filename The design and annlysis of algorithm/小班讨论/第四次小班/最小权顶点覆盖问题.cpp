#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>
#include <chrono> // 用于计时
#include <iomanip> // 用于格式化输出

using namespace std;
using namespace std::chrono; // 使用时间库命名空间

// ================= 全局变量 =================
int n, m;                   
vector<int> w;              
vector<vector<int>> adj;    
struct Edge { int u, v; };
vector<Edge> all_edges;     

// 统计变量 (用于PPT展示)
long long nodes_generated = 0; // 生成的节点总数

// ================= 节点定义 =================
struct Node {
    int i;              
    int cn;             
    int lb;             
    vector<int> x;      

    Node(int _i, int _cn, int _lb) : i(_i), cn(_cn), lb(_lb) {
        x.resize(n + 1, 0); 
    }

    bool operator>(const Node& other) const {
        if (lb != other.lb)
            return lb > other.lb;
        return i < other.i; 
    }
};

// ================= 下界函数 =================
int get_bound(int k, int current_cost) {
    int potential_cost = 0;
    vector<bool> covered(n + 1, false); 

    for (const auto& edge : all_edges) {
        int u = edge.u;
        int v = edge.v;
        if (u > k && v > k) {
            if (!covered[u] && !covered[v]) {
                potential_cost += min(w[u], w[v]);
                covered[u] = true;
                covered[v] = true;
            }
        }
    }
    return current_cost + potential_cost;
}

int main() {
    // 1. 读取输入
    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cerr << "Error: Cannot open input.txt" << endl;
        return 1;
    }
    fin >> n >> m;
    w.resize(n + 1);
    adj.resize(n + 1);
    for (int i = 1; i <= n; i++) fin >> w[i];
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        all_edges.push_back({u, v});
    }
    fin.close();

    cout << "    算法开始运行 (Branch & Bound)       " << endl;
    cout << "图规模: " << n << " 顶点, " << m << " 边" << endl;

    // --- 计时开始 ---
    auto start_time = high_resolution_clock::now();

    // 2. 初始化优先队列
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    Node root(0, 0, 0);
    root.lb = get_bound(0, 0);
    pq.push(root);
    nodes_generated++;

    Node bestNode(0, 0, 0); 
    int min_weight = -1;    

    // 3. 搜索循环
    while (!pq.empty()) {
        Node E = pq.top();
        pq.pop();

        if (E.i == n) {
            min_weight = E.cn;
            bestNode = E;
            break; // 找到最优解
        }

        int next_i = E.i + 1;

        // 分支 1：左孩子（选）
        {
            int next_cn = E.cn + w[next_i];
            int next_lb = get_bound(next_i, next_cn);
            Node leftChild = E;
            leftChild.i = next_i;
            leftChild.cn = next_cn;
            leftChild.lb = next_lb;
            leftChild.x[next_i] = 1;
            pq.push(leftChild);
            nodes_generated++;
        }

        // 分支 2：右孩子（不选）
        {
            bool feasible = true;
            for (int neighbor : adj[next_i]) {
                if (neighbor < next_i) {
                    if (E.x[neighbor] == 0) {
                        feasible = false;
                        break; 
                    }
                }
            }

            if (feasible) {
                int next_cn = E.cn;
                int next_lb = get_bound(next_i, next_cn);
                Node rightChild = E;
                rightChild.i = next_i;
                rightChild.cn = next_cn;
                rightChild.lb = next_lb;
                rightChild.x[next_i] = 0; 
                pq.push(rightChild);
                nodes_generated++;
            }
        }
    }

    // --- 计时结束 ---
    auto end_time = high_resolution_clock::now();
    // 计算耗时 (微秒)
    auto duration = duration_cast<microseconds>(end_time - start_time); 
    // 或者毫秒
    auto duration_ms = duration_cast<milliseconds>(end_time - start_time);

    // 4. 统计结果数据大小
    int selected_count = 0;
    if (min_weight != -1) {
        for (int i = 1; i <= n; i++) {
            if (bestNode.x[i] == 1) selected_count++;
        }
    }

    // 5. 屏幕输出统计信息 (适合截图放PPT)
    cout << "\n------------ 运行结果统计 ------------" << endl;
    if (min_weight != -1) {
        cout << "最优权值 (Min Weight) : " << min_weight << endl;
        cout << "选中顶点数 (Count)    : " << selected_count << " / " << n << endl;
        cout << "搜索空间 (Generated)  : " << nodes_generated << " 个节点" << endl;
        cout << "运行时间 (Time)       : " << duration.count() << " us (" 
             << duration_ms.count() << " ms)" << endl;
        cout << "--------------------------------------" << endl;
    } else {
        cout << "未找到解！" << endl;
    }

    // 6. 写入文件 output.txt
    ofstream fout("output.txt");
    if (min_weight != -1) {
        fout << min_weight << endl;
        for (int i = 1; i <= n; i++) {
            fout << bestNode.x[i] << (i == n ? "" : " ");
        }
        fout << endl;
    } else {
        fout << "No Solution" << endl;
    }
    fout.close();
    cout << "结果已保存至 output.txt" << endl;

    return 0;
}
