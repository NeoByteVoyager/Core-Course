#include <bits/stdc++.h>

using namespace std;

const int MAXN = 25;
int P[MAXN][MAXN], Q[MAXN][MAXN];
int perm[MAXN]; // 排列数组
int best = 0;   // 全局最优解
int now = 0;    // 当前路径的得分
int n;

// 估价函数：计算剩余男运动员（k+1 到 n）可能贡献的最大理论值
int Bound(int k, int n) {
    int bound = 0;
    // 遍历剩下的每一个男运动员
    for (int i = k + 1; i <= n; i++) {
        int max_val = 0;
        // 查找该男运动员与任意女运动员配对的最大可能值
        for (int j = 1; j <= n; j++) {
            max_val = max(max_val, P[i][j] * Q[j][i]);
        }
        bound += max_val;
    }
    return bound;
}

void backtrack(int k, int n) {
    // 到达叶子节点，更新最优解
    if (k > n) {
        best = max(best, now);
        return;
    }

    // 遍历当前位置 k 可能的所有选择
    for (int i = k; i <= n; i++) {
        // 1. 交换：决定让 perm[i] 号女生与 k 号男生配对
        swap(perm[i], perm[k]);
        
        // 2. 计算当前增量
        int current_pair_val = P[k][perm[k]] * Q[perm[k]][k];
        now += current_pair_val;

        // 3. 剪枝判断：当前得分 + 剩余理论最大值 > 历史最优解，才有必要继续
        if (now + Bound(k, n) > best) {
            backtrack(k + 1, n);
        }

        // 4. 回溯：恢复状态
        now -= current_pair_val;
        swap(perm[i], perm[k]);
    }
}

int main() {

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!(fin >> n)) return 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> P[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> Q[i][j];
        }
    }

    // 初始化排列
    for (int i = 1; i <= n; i++) perm[i] = i;

    // --- 开始计时 ---
    clock_t start_time = clock();

    backtrack(1, n);

    // --- 结束计时 ---
    clock_t end_time = clock();

    cout <<"res:"<< best << endl;

    // 输出运行时间（毫秒）
    cout<<"datasize:"<<n<<endl;
    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;
    cout << "Running Time: " << duration << " ms" << endl; 

    return 0;
}
