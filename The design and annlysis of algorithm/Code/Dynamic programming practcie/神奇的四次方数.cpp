#include<bits/stdc++.h>
using namespace std;
int main(){
	int m;
	cin>>m;
	vector<int>t;
	for(int i=1;i*i*i*i<=m;i++) t.push_back(i*i*i*i);
	int n=t.size();
	vector<int>dp(m+1,INT_MAX);
	dp[0]=0;
	for(int i=0;i<n;i++){
		for(int j=t[i];j<=m;j++){
			if(dp[j-t[i]]!=INT_MAX) dp[j]=min(dp[j-t[i]]+1,dp[j]);
		}
	}
	cout<<dp[m];
	return 0;
}
