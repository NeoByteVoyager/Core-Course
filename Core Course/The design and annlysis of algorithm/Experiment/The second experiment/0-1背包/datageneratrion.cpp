#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));

    int n = 1000;                 // 物品数，可调整
    int W = 5000;                // 背包容量，可调整
    int maxWeight = 50;         // 单个物品最大重量
    int maxValue  = 200;        // 单个物品最大价值

    ofstream fout("input.txt");

    fout << n << " " << W << "\n";

    // 生成权重
    for (int i = 0; i < n; i++) {
        fout << (rand() % maxWeight + 1) << " ";
    }
    fout << "\n";

    // 生成价值
    for (int i = 0; i < n; i++) {
        fout << (rand() % maxValue + 1) << " ";
    }
    fout << "\n";

    fout.close();
    cout << "测试数据已生成：input.txt\n";
    return 0;
}

