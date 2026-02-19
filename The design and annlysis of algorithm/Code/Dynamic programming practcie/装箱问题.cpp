#include<iostream>
using namespace std;
int dp[31][20002];
int w[31];
int main(){
	int v,n;
	cin>>v>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=v;j++){
			if(w[i]<=j) dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+w[i]);
			else dp[i][j]=dp[i-1][j];
		}
	}
	cout<<v-dp[n][v];
	return 0;
} 
