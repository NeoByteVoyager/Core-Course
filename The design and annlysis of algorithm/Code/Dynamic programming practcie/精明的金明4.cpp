#include<iostream>
using namespace std;
int dp[26][30001];
int v[26],p[26];
int main(){
	int t,n;
	cin>>t>>n;
	for(int i=1;i<=n;i++) cin>>v[i]>>p[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=t;j++){
			if(v[i]<=j) dp[i][j]=max(dp[i-1][j-v[i]]+v[i]*p[i],dp[i-1][j]);
			else dp[i][j]=dp[i-1][j];
		}
	}
	cout<<dp[n][t];
	return 0;
} 
