#include <iostream>
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    // 1. 判断是否合法
    if (c != a + 1)
    {
        cout << -1 << "\n";
        return;
    }

    // 2. 特殊情况：如果没有度为2的节点
    if (a == 0)
    {
        // 全是 1 个孩子的节点连成一条直线，高度就是 b
        cout << b << "\n";
        return;
    }

    // 3. 计算 a 构成的完全二叉树的深度
    int d = 0;
    int temp = a + 1;
    while (temp > 1)
    {
        temp >>= 1; // 相当于除以 2
        d++;
    }

    // 4. 计算深度为 d 和 d+1 的可用空位数量
    // 满二叉树前 d 层（深度 0 到 d-1）容纳了 (2^d - 1) 个 a 节点
    int a_in_full_levels = (1 << d) - 1;
    // 剩余的 a 节点落在了深度为 d 的那一层
    int rem_a = a - a_in_full_levels;

    // 深度为 d 的空位数量 = 理论满位 - 被占用位
    int U_d = (1 << d) - rem_a;
    // 落在 d 层的 a 会在 d+1 层衍生出双倍的空位
    int U_dp1 = 2 * rem_a;

    // 5. 分配 b 节点进行填坑
    if (b <= U_d)
    {
        // b 不足以让所有空位平齐
        if (U_dp1 > 0 || b > 0)
        {
            cout << d + 1 << "\n";
        }
        else
        {
            cout << d << "\n";
        }
    }
    else
    {
        // b 足够让所有空位达到 d+1 的深度，然后均摊剩下的 b
        int b_rem = b - U_d; // 填平后剩下的 b
        int S = a + 1;       // 此时所有的空位数量就是 c 的数量

        // 向上取整公式：(分子 + 分母 - 1) / 分母
        int extra_levels = (b_rem + S - 1) / S;

        cout << d + 1 + extra_levels << "\n";
    }
}

int main()
{
    // 优化 C++ 输入输出流速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}