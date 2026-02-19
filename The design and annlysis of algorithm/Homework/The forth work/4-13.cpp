#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e15;

struct Task {
    int t; // 执行时间
    int d; // 截止时间
    ll w;  // 误时罚值
};

int main() {
        ifstream fin("D:\\Core Course\\The design and annlysis of algorithm\\Homework\\The forth work\\input4-13.txt");
    ofstream fout("D:\\Core Course\\The design and annlysis of algorithm\\Homework\\The forth work\\output4-13.txt");

    if (!fin.is_open()) return 0;

    int n;
    fin >> n;
    vector<Task> a(n + 1);
    int Dmax = 0;

    for (int i = 1; i <= n; i++) {
        fin >> a[i].t >> a[i].d >> a[i].w;
        Dmax = max(Dmax, a[i].d);
    }

    // 按截止时间非减序排列 —— 题目要求递推式的必要前提
    sort(a.begin() + 1, a.end(), [](const Task &A, const Task &B) {
        return A.d < B.d;
    });

    // dp[i][d] 对应 p(i,d) —— 前 i 个任务，当前允许结束时间 = d 的最小罚值
    vector<vector<ll>> dp(n + 1, vector<ll>(Dmax + 1, INF));

    // 初始化：p(0, d) = 0
    for (int d = 0; d <= Dmax; d++) dp[0][d] = 0;

    // 按题目公式严格转移
    for (int i = 1; i <= n; i++) {
        int ti = a[i].t;
        int di = a[i].d;
        ll wi = a[i].w;
        for (int d = 0; d <= Dmax; d++) {
            // 项1：p(i-1, d) + w_i   (任务 i 不按时完成)
            if (dp[i - 1][d] != INF) {
                dp[i][d] = min(dp[i][d], dp[i - 1][d] + wi);
            }

            // 项2：p(i-1, min(d, d_i) - t_i)   (任务 i 按时完成)
            int finish = min(d, di);
            int prev = finish - ti;
            if (prev >= 0 && dp[i - 1][prev] != INF) {
                dp[i][d] = min(dp[i][d], dp[i - 1][prev]);
            }
        }
    }

    // 最优答案 = min_{0 ≤ d ≤ Dmax} p(n, d)
    ll ans = INF;
    for (int d = 0; d <= Dmax; d++) ans = min(ans, dp[n][d]);

    if (ans == INF)
        fout << "NoSolution";
    else
        fout << ans;
//	for(int i=0;i<=n;i++){
//		for(int j=0;j<=Dmax;j++){
//			fout<<dp[i][j]<<" ";
//		}
//		fout<<endl;
//	}
    fin.close();
    fout.close();
    return 0;
}

