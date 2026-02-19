#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long dp[10][10];

int main(){
	int n;
	cin>>n;
	dp[1][1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i][j]=dp[i-1][j-1]%mod+j*dp[i-1][j]%mod ;
		}
	}
	int res=0;
	for(int i=1;i<=n;i++) res=(res+dp[n][i])%mod;
	cout<<res;
	return 0;
} 
