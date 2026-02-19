#include <iostream>

using namespace std;

// 打印 num 个空格
void PrintBlank(int num) {
    for (int i = 0; i < num; ++i) {
        cout << " ";
    }
}

// 打印第 n 行的二项式系数（即杨辉三角的第 n 行）
void PrintCombine(int n) {
    int coef = 1; // 第一个系数总是 1
    for (int i = 1; i <= n; ++i) {
        cout << coef << " ";
        // 计算下一个系数：C(n-1, k+1) = C(n-1, k) * (n - k) / (k + 1)
        coef = coef * (n - i) / i;
    }
}
