#include<bits/stdc++.h>
using namespace std;

const int MAXN = 25;
int P[MAXN][MAXN], Q[MAXN][MAXN];
int perm[MAXN]; // 记录每位男运动员匹配的女运动员编号
int best = 0;   // 全局最大值
int n;

// 预处理数组：suffix_max[i] 表示从第 i 个男运动员到第 n 个男运动员，
// 理论上能获得的最大贡献之和（用于剪枝）
int suffix_max[MAXN]; 

void backtrack(int k, int current_score){
    if(k > n){
        best = max(best, current_score);
        return;
    } 

    for(int i = k; i <= n; i++){
        // 交换，尝试将perm[i]号女生分配给第k号男生
        swap(perm[i], perm[k]);
        
        // 计算当前这一对的得分
        int cost = P[k][perm[k]] * Q[perm[k]][k];
        if( current_score +cost + suffix_max[k] > best)
        backtrack(k + 1, current_score + cost);
        
        // 回溯
        swap(perm[i], perm[k]);
    }
}

int main(){

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    if(!(cin >> n)) return 0; // 防止读取失败

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> P[i][j];
        }
    }   
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> Q[i][j];
        }
    }

    // 初始化排列数组
    for(int i = 1; i <= n; i++) perm[i] = i;

    // --- 预处理剪枝辅助数组 ---
    // 计算每个男运动员i可能产生的最大乘积值
    int max_val_per_male[MAXN] = {0};
    for(int i = 1; i <= n; i++){
        int row_max = 0;
        for(int j = 1; j <= n; j++){
            // 找出男i与所有女j配对中，乘积最大的那个值
            row_max = max(row_max, P[i][j] * Q[j][i]);
        }
        max_val_per_male[i] = row_max;
    }

    // 计算后缀和：suffix_max[k] = max_val[k] + ... + max_val[n]
    // 意思是从第k个人开始，哪怕运气最好，后面最多也就只能拿这么多分
    suffix_max[n + 1] = 0;
    for(int i = n; i >= 1; i--){
        suffix_max[i] = suffix_max[i + 1] + max_val_per_male[i];
    }
    // -------------------------

    backtrack(1, 0);
    
    cout << best << endl;
    
    return 0;
}
