#include<iostream>
#include<climits> 
using namespace std;
int a[202][202];
int dp[202];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	dp[1]=0; 
	for(int i=2;i<=n;i++){
		dp[i]=INT_MAX;
		for(int j=1;j<=i-1;j++){
			dp[i]=min(dp[j]+a[j][i],dp[i]);
		}
	}
	cout<<dp[n];
	return 0;
} 
