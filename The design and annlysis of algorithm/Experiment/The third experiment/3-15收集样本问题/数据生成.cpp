#include <bits/stdc++.h>
using namespace std;

// 生成随机整数 [min, max]
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// 写入单个测试用例到文件
void writeTestCase(const string& filename, int n, const vector<tuple<int, int, int>>& cells) {
    ofstream outFile(filename);
    outFile << n << endl;
    // C++14兼容：不使用结构化绑定
    for (auto& cell : cells) {
        int x, y, v;
        tie(x, y, v) = cell;
        outFile << x << " " << y << " " << v << endl;
    }
    outFile << "0 0 0" << endl;
    outFile.close();
}

// 生成小规模测试用例 (n=5-10, 10-20个价值点)
void generateSmall(int count = 5) {
    cout << "【生成小规模测试用例】n∈[5,10], 价值点10-20个" << endl;
    for (int t = 1; t <= count; t++) {
        int n = randInt(5, 10);
        int numValues = randInt(10, 20);  // 价值点数量
        
        // 确保起点和终点有价值
        vector<tuple<int, int, int>> cells;
        cells.push_back(make_tuple(1, 1, randInt(1, 10)));  // 起点
        cells.push_back(make_tuple(n, n, randInt(1, 10)));  // 终点
        
        // 随机生成其他价值点
        for (int i = 0; i < numValues - 2; i++) {
            int x = randInt(1, n);
            int y = randInt(1, n);
            int v = randInt(1, 20);
            // 避免覆盖起点终点
            if (x == 1 && y == 1) continue;
            if (x == n && y == n) continue;
            cells.push_back(make_tuple(x, y, v));
        }
        
        writeTestCase("input_small_" + to_string(t) + ".txt", n, cells);
        cout << "  ? input_small_" << t << ".txt  (n=" << n << ")" << endl;
    }
}

// 生成中规模测试用例 (n=15-30, 50-100个价值点)
void generateMedium(int count = 3) {
    cout << "\n【生成中规模测试用例】n∈[15,30], 价值点50-100个" << endl;
    for (int t = 1; t <= count; t++) {
        int n = randInt(15, 30);
        int numValues = randInt(50, 100);
        
        vector<tuple<int, int, int>> cells;
        cells.push_back(make_tuple(1, 1, randInt(5, 20)));
        cells.push_back(make_tuple(n, n, randInt(5, 20)));
        
        for (int i = 0; i < numValues - 2; i++) {
            int x = randInt(1, n);
            int y = randInt(1, n);
            int v = randInt(5, 50);
            if (x == 1 && y == 1) continue;
            if (x == n && y == n) continue;
            cells.push_back(make_tuple(x, y, v));
        }
        
        writeTestCase("input_medium_" + to_string(t) + ".txt", n, cells);
        cout << "  ? input_medium_" << t << ".txt  (n=" << n << ")" << endl;
    }
}

// 生成大规模测试用例 (n=50-100, 200-500个价值点)
void generateLarge(int count = 2) {
    cout << "\n【生成大规模测试用例】n∈[50,100], 价值点200-500个" << endl;
    for (int t = 1; t <= count; t++) {
        int n = randInt(50, 100);
        int numValues = randInt(200, min(500, n * n));  // 不超过总格子数
        
        vector<tuple<int, int, int>> cells;
        cells.push_back(make_tuple(1, 1, randInt(10, 30)));
        cells.push_back(make_tuple(n, n, randInt(10, 30)));
        
        // 使用set避免重复坐标
        set<pair<int, int>> visited;
        visited.insert(make_pair(1, 1));
        visited.insert(make_pair(n, n));
        
        for (int i = 0; i < numValues - 2; i++) {
            int x = randInt(1, n);
            int y = randInt(1, n);
            if (visited.count(make_pair(x, y))) {
                i--;
                continue;
            }
            visited.insert(make_pair(x, y));
            int v = randInt(10, 100);
            cells.push_back(make_tuple(x, y, v));
        }
        
        writeTestCase("input_large_" + to_string(t) + ".txt", n, cells);
        cout << "  ? input_large_" << t << ".txt  (n=" << n << ")" << endl;
    }
}

int main() {
    srand(time(0));
    
    cout << "========== 方格取数问题测试用例生成器 ==========" << endl;
    
    // 生成三种规模的测试用例
    generateSmall(5);      // 生成5个小规模
    generateMedium(3);     // 生成3个中规模
    generateLarge(2);      // 生成2个大规模
    
    cout << "\n生成完成！共10个测试文件："<< endl;
    cout << "  - 小规模: input_small_1.txt ~ input_small_5.txt" << endl;
    cout << "  - 中规模: input_medium_1.txt ~ input_medium_3.txt" << endl;
    cout << "  - 大规模: input_large_1.txt ~ input_large_2.txt" << endl;
    cout << "===============================================" << endl;
    
    return 0;
}
