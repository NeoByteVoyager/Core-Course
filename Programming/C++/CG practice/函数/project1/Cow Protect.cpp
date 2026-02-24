#include<bits/stdc++.h>
using namespace std;
int a[1001];
long long prefix[1001];
long long dp[1001];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		prefix[i]=prefix[i-1]+a[i];
	}
	if(prefix[n]<0){
		cout<<"Impossible\n";
		return 0;
	}
	for(int i=1;i<=n;i++){
		dp[i]=LLONG_MIN;
		for(int j=0;j<i;j++){
			if(prefix[i]-prefix[j]>=0) dp[i]=max(dp[j]+1,dp[i]);
		}
	}
	cout<<dp[n];
	return 0;
}
