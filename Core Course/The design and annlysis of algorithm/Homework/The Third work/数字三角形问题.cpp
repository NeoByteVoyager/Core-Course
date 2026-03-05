#include<bits/stdc++.h>
using namespace std;
int a[101][101];
int dp[101][101];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>a[i][j];
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=i;j++){
			dp[i][j]=max(dp[i+1][j]+a[i][j],dp[i+1][j+1]+a[i][j]);
		} 
	}
	cout<<dp[1][1];
	return 0;
} 

