#include <bits/stdc++.h>
using namespace std;

// 生成随机整数 [l, r]
int randInt(int l, int r) {
    return rand() % (r - l + 1) + l;
}

// 将测试用例写入文件
void writeTestToFile(const string& filename, int n, int m, int s, 
                     const vector<tuple<int,int,int>>& edges) {
    ofstream fout(filename);
    if (!fout) {
        cerr << "错误：无法创建文件 " << filename << endl;
        return;
    }
    
    // 写入第一行：节点数 边数 起点
    fout << n << " " << m << " " << s << endl;
    
    // 写入所有边（C++14兼容写法）
    for (auto it = edges.begin(); it != edges.end(); ++it) {
        int u, v, w;
        tie(u, v, w) = *it;  // C++14使用tie解包tuple
        fout << u << " " << v << " " << w << endl;
    }
    
    fout.close();
    cout << "已生成: " << filename << " (n=" << n << ", m=" << m << ")" << endl;
}

// 生成稀疏图（m ≈ 2n）
void genSparse(int n, int maxW, const string& prefix) {
    int m = min(2 * n, n * (n - 1) / 2);
    set<pair<int,int>> es;
    while(es.size() < m) {
        int u = randInt(1, n), v = randInt(1, n);
        if(u != v) es.insert({u, v});
    }
    
    vector<tuple<int,int,int>> e;
    // C++14兼容遍历
    for (auto it = es.begin(); it != es.end(); ++it) {
        int u = it->first;
        int v = it->second;
        e.push_back(make_tuple(u, v, randInt(1, maxW)));
    }
    
    writeTestToFile(prefix + "_sparse.txt", n, m, 1, e);
}

// 生成链式图
void genChain(int n, int maxW, const string& prefix) {
    vector<tuple<int,int,int>> e;
    for(int i = 1; i < n; i++) {
        e.push_back(make_tuple(i, i+1, randInt(1, maxW)));
    }
    
    writeTestToFile(prefix + "_chain.txt", n, n-1, 1, e);
}

// 生成星形图
void genStar(int n, int maxW, const string& prefix) {
    vector<tuple<int,int,int>> e;
    for(int i = 2; i <= n; i++) {
        e.push_back(make_tuple(1, i, randInt(1, maxW)));
    }
    
    writeTestToFile(prefix + "_star.txt", n, n-1, 1, e);
}

// 生成稠密图
void genDense(int n, int maxW, const string& prefix) {
    int m = min(n * n / 4, n * (n - 1) / 2);
    vector<tuple<int,int,int>> e;
    
    for(int i = 0; i < m; i++) {
        int u = randInt(1, n);
        int v = randInt(1, n);
        while(u == v) v = randInt(1, n);
        e.push_back(make_tuple(u, v, randInt(1, maxW)));
    }
    
    writeTestToFile(prefix + "_dense.txt", n, m, 1, e);
}

// 生成大中小三套测试集
void genSuite() {
    srand(time(0));
    
    cout << "【生成小规模测试集】\n";
    genSparse(10, 50, "small");
    genChain(15, 20, "small");
    genStar(8, 40, "small");
    genDense(12, 30, "small");
    
    cout << "\n【生成中规模测试集】\n";
    genSparse(100, 1000, "medium");
    genChain(300, 100, "medium");
    genStar(1500, 200, "medium");
    genDense(200, 500, "medium");
    
    cout << "\n【生成大规模测试集】\n";
    genSparse(2000, 10000, "large");
    genChain(5000, 50, "large");
    genStar(30000, 100, "large");
    genDense(1000, 5000, "large");
    
    cout << "\n【生成边界测试】\n";
    // 单节点
    writeTestToFile("boundary_single.txt", 1, 0, 1, {});
    // 完全图
    vector<tuple<int,int,int>> e;
    int n = 5;
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            e.push_back(make_tuple(i, j, randInt(1, 10)));
        }
    }
    writeTestToFile("boundary_complete.txt", n, e.size(), 1, e);
}

int main() {
    genSuite();
    cout << "\n? 所有测试集已生成完毕！" << endl;
    cout << "?? 文件命名格式: {small|medium|large}_{graph_type}.txt" << endl;
    cout << "?? 使用说明: 将对应文件重命名为 input.txt 后运行主程序" << endl;
    return 0;
}
