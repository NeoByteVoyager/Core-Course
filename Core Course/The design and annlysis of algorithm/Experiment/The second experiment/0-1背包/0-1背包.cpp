#include <bits/stdc++.h>
using namespace std;

// 01背包：返回最大价值
int knapsack01(vector<int>& w, vector<int>& v, int W) {
    int n = w.size();
    vector<int> dp(W+1, 0);

    for(int i = 0; i < n; i++) {
        for(int j = W; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    return dp[W];
}

int main() {
    int n, W;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
    fin >> n >> W;

    vector<int> w(n), v(n);

    for(int &x : w) fin >> x;


    for(int &x : v) fin >> x;

    clock_t st = clock();
    int ans = knapsack01(w, v, W);
    clock_t ed = clock();

    fout << "最大价值为：" << ans << endl;
    cout<<"n:"<<n<<" w:"<<W<<endl; 
    cout << fixed << setprecision(12) 
         << "程序运行时间：" << (double)(ed - st) / CLOCKS_PER_SEC << " 秒" << endl;
    return 0;
}

