#include <bits/stdc++.h>
using namespace std;

struct Node {
    vector<char> x;      // 解向量，0/1表示顶点是否在覆盖中
    int level;           // 当前已决策的顶点数
    int weight;          // 已选顶点的权值和
    int bound;           // 下界（用于剪枝）
    
    // 用于priority_queue小根堆（greater需要>）
    bool operator>(const Node& other) const {
        return bound > other.bound;  // bound越小优先级越高
    }
};

class MinWeightVertexCover {
private:
    int n, m;
    vector<int> weights;              // 顶点权值（1-indexed）
    vector<pair<int, int>> edges;     // 边列表
    vector<vector<int>> adjList;      // 邻接表
    
    int bestWeight;
    vector<char> bestSolution;
    
    // 检查是否覆盖所有边
    bool isAllCovered(const vector<char>& x) {
        for (size_t i = 0; i < edges.size(); i++) {
            int u = edges[i].first;
            int v = edges[i].second;
            if (!x[u] && !x[v]) return false;
        }
        return true;
    }
    
    // 计算下界：当前权值 + 启发式估计剩余代价
    int calcBound(const Node& node) {
        int bound = node.weight;
        
        // 标记已覆盖顶点
        vector<char> covered = node.x;
        for (int i = 1; i <= node.level; i++) {
            if (node.x[i]) {
                for (size_t j = 0; j < adjList[i].size(); j++) {
                    covered[adjList[i][j]] = 1;
                }
            }
        }
        
        // 对每条未覆盖边，必须选至少一个端点
        for (size_t i = 0; i < edges.size(); i++) {
            int u = edges[i].first;
            int v = edges[i].second;
            if (!covered[u] && !covered[v]) {
                bound += min(weights[u], weights[v]);
                covered[u] = covered[v] = 1;  // 贪心假设
            }
        }
        return bound;
    }
    
    // 检查是否可能得到更优解
    bool isPromising(const Node& node) {
        return node.weight < bestWeight && node.bound < bestWeight;
    }
    
public:
    MinWeightVertexCover(const string& inputFile) {
        ifstream fin(inputFile);
        if (!fin) {
            cerr << "错误：无法打开输入文件！" << endl;
            exit(1);
        }
        
        fin >> n >> m;
        weights.resize(n + 1);
        adjList.resize(n + 1);
        
        for (int i = 1; i <= n; i++) {
            fin >> weights[i];
        }
        
        for (int i = 0; i < m; i++) {
            int u, v;
            fin >> u >> v;
            edges.push_back(make_pair(u, v));
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        fin.close();
    }
    
    void solve(const string& outputFile) {
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        
        Node root;
        root.x.assign(n + 1, 0);
        root.level = 0;
        root.weight = 0;
        root.bound = calcBound(root);
        
        pq.push(root);
        bestWeight = INT_MAX;
        
        while (!pq.empty()) {
            Node node = pq.top(); pq.pop();
            
            if (node.bound >= bestWeight) continue;
            
            // 所有顶点已决策
            if (node.level == n) {
                if (isAllCovered(node.x) && node.weight < bestWeight) {
                    bestWeight = node.weight;
                    bestSolution = node.x;
                    break; 
                }
                continue;
            }
            
            int v = node.level + 1;  // 当前决策顶点
            
            // 分支1：选择顶点v
            if (node.weight + weights[v] < bestWeight) {
                Node left = node;
                left.x[v] = 1;
                left.weight += weights[v];
                left.level = v;
                left.bound = calcBound(left);
                if (left.bound < bestWeight) {
                    pq.push(left);
                }
            }
            
            // 分支2：不选顶点v
            Node right = node;
            right.level = v;
            right.bound = calcBound(right);
            if (isPromising(right)) {
                pq.push(right);
            }
        }
        
        // 输出结果
        ofstream fout(outputFile);
        fout << bestWeight << endl;
        for (int i = 1; i <= n; i++) {
            fout << (int)bestSolution[i];
        }
        fout << endl;
        fout.close();
    }
    
    void printSolution() {
        cout << "最小权值和: " << bestWeight << endl;
        cout << "解向量: ";
        for (int i = 1; i <= n; i++) {
            cout << (int)bestSolution[i]<<" ";
        }
        cout << endl;
    }
};

int main() {
    MinWeightVertexCover solver("input.txt");
    solver.solve("output.txt");
    solver.printSolution();
    return 0;
}
