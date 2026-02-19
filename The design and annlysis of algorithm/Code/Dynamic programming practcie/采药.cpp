#include<iostream>
using namespace std;
int dp[101][1002]; 
int t[101],w[101];
int main(){
	int T,m;
	cin>>T>>m;
	for(int i=1;i<=m;i++){
		cin>>t[i]>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=T;j++){
			if(j>=t[i]) dp[i][j]=max(dp[i-1][j],dp[i-1][j-t[i]]+w[i]);
			else dp[i][j]=dp[i-1][j]; 
		}
	} 
	cout<<dp[m][T];
	return 0;
} 
