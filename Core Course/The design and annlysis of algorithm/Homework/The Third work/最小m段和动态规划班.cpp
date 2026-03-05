#include<bits/stdc++.h>
using namespace std;

int a[101], pre[101];
int dp[101][101];
int n, m;

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }

    memset(dp, 0x3f, sizeof(dp));

    // k = 1£¬Ö»ÄÜÒ»¶Î
    for(int i=1;i<=n;i++){
        dp[i][1] = pre[i];
    }

    for(int k=2; k<=m; k++){
        for(int i=k; i<=n; i++){
            for(int j=k-1; j<i; j++){
                int sum = pre[i] - pre[j];
                dp[i][k] = min(dp[i][k], max(dp[j][k-1], sum));
            }
        }
    }

    cout << dp[n][m];
    return 0;
}

