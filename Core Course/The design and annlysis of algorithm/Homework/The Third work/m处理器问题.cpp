#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
double dp[MAXN][MAXN];        // dp[i][k] = 前 i 个数据包划分成 k 段后的最优最大负载
double sqsum[MAXN];           // 前缀平方和

int main() {
	ifstream fin("D:\\Core Course\\The design and annlysis of algorithm\\Homework\\The Third work\\input1.txt");
	ofstream fout("D:\\Core Course\\The design and annlysis of algorithm\\Homework\\The Third work\\output1.txt");
    int n, m;
    fin >> n >> m;
    
    vector<double> a(n + 1);
    for (int i = 1; i <= n; i++) {
        fin >> a[i];
        sqsum[i] = sqsum[i - 1] + a[i] * a[i];   // 构建平方和前缀数组
    }

    // 初始化：1 段情况下，所有前 i 个包给第 1 个处理器
    for (int i = 1; i <= n; i++)
        dp[i][1] = sqrt(sqsum[i]);               // √(a12 + a22 + ... + ai2)

    // 动态规划
    for (int k = 2; k <= m; k++) {
        for (int i = k; i <= n; i++) {
            dp[i][k] = 1e18; // 初始为很大的数
            for (int j = k - 1; j < i; j++) {
                // 第 k 段负责 j+1 到 i
                double load = sqrt(sqsum[i] - sqsum[j]);
                double worst = max(dp[j][k - 1], load);
                dp[i][k] = min(dp[i][k], worst);
            }
        }
    }

    fout << fixed << setprecision(2) << dp[n][m] << endl;
    return 0;
}

