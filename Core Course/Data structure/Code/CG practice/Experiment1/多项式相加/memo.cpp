#include <iostream>
#include "PolyList.h"

using namespace std;

int main() {
    int n, m;
    PolyList poly1, poly2, result;

    // 1. 读取第一个多项式
    if (cin >> n) {
        for (int i = 0; i < n; i++) {
            int c, e;
            cin >> c >> e;
            poly1.insert(c, e);
        }
    }

    // 2. 读取第二个多项式
    if (cin >> m) {
        for (int i = 0; i < m; i++) {
            int c, e;
            cin >> c >> e;
            poly2.insert(c, e);
        }
    }

    // 3. 多项式相加 (核心逻辑)
    int i = 0, j = 0;
    while (i < poly1.getLength() && j < poly2.getLength()) {
        Term t1 = poly1.getTerm(i);
        Term t2 = poly2.getTerm(j);

        if (t1.exp > t2.exp) {
            // 第一个多项式当前的指数较大，将其项直接放入结果表
            result.insert(t1.coef, t1.exp);
            i++;
        } else if (t1.exp < t2.exp) {
            // 第二个多项式当前的指数较大，将其项直接放入结果表
            result.insert(t2.coef, t2.exp);
            j++;
        } else {
            // 指数相同，系数相加
            int sumCoef = t1.coef + t2.coef;
            // 如果相加后系数不为0，则保留该项
            if (sumCoef != 0) {
                result.insert(sumCoef, t1.exp);
            }
            // 两个指针同时后移
            i++;
            j++;
        }
    }

    // 将 poly1 剩余的项追加到结果中（如果存在）
    while (i < poly1.getLength()) {
        Term t1 = poly1.getTerm(i);
        result.insert(t1.coef, t1.exp);
        i++;
    }

    // 将 poly2 剩余的项追加到结果中（如果存在）
    while (j < poly2.getLength()) {
        Term t2 = poly2.getTerm(j);
        result.insert(t2.coef, t2.exp);
        j++;
    }

    // 4. 输出计算结果
    // 遍历 result 线性表输出
    for (int k = 0; k < result.getLength(); k++) {
        Term t = result.getTerm(k);
        cout << t.coef << " " << t.exp << endl;
    }

    return 0;
}
