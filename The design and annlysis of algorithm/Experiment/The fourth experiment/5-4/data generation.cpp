#include <iostream>
#include <fstream>  // 用于文件操作
#include <cstdlib>  // 用于rand()
#include <ctime>    // 用于time()

using namespace std;

// 配置项
const int MIN_N = 3;   // N的最小值
const int MAX_N = 20;  // N的最大值（题目限制为20）
const int MAX_VAL = 50; // 矩阵中数值的最大值（建议不要太大，防止溢出，虽然int很难溢出）

int main() {
    // 1. 初始化随机数种子
    srand((unsigned)time(NULL));

    // 2. 打开（或创建）文件
    ofstream outfile("input.txt");
    if (!outfile.is_open()) {
        cerr << "无法创建或打开 input.txt 文件！" << endl;
        return 1;
    }

    // 3. 随机生成 N (在 MIN_N 和 MAX_N 之间)
    // 如果你想测试特定的 N，可以直接写 int n = 20;
    int n = 10;
    
    cout << "正在生成测试用例..." << endl;
    cout << "N = " << n << endl;

    // 写入 N
    outfile << n << endl;

    // 4. 生成矩阵 P
    // P[i][j] 表示男 i 和女 j 配对的优势
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 生成 1 到 MAX_VAL 之间的随机数
            int val = rand() % MAX_VAL + 1;
            outfile << val << (j == n - 1 ? "" : " ");
        }
        outfile << endl;
    }

    // 5. 生成矩阵 Q
    // Q[i][j] 表示女 i 和男 j 配对的优势
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val = rand() % MAX_VAL + 1;
            outfile << val << (j == n - 1 ? "" : " ");
        }
        outfile << endl;
    }

    // 6. 关闭文件
    outfile.close();
    cout << "生成完毕！数据已写入 input.txt" << endl;

    return 0;
}
