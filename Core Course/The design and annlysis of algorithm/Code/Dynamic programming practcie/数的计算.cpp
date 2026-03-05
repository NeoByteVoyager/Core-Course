#include<iostream>
using namespace std;
int dp[1005];
int main(){
	int n;
	cin>>n;
	dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]=1;
		for(int j=1;j<=i/2;j++){
			dp[i]+=dp[j];
		}
	}
	cout<<dp[n];
	return 0;
} 
