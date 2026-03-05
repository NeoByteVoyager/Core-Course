#include<bits/stdc++.h>
using namespace std;
const int maxn=5001;
typedef long long ll; 
ll t[maxn],f[maxn];
ll st[maxn],sf[maxn];
ll dp[maxn];
int main() {
	int n,s;
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>f[i];
		st[i]=st[i-1]+t[i];
		sf[i]=sf[i-1]+f[i];
		dp[i]=LLONG_MAX; 
	}
	dp[0]=0; 
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			dp[i]=min(dp[i],dp[j]+st[i]*(sf[i]-sf[j])+s*(sf[n]-sf[j]));
		}
	}
	cout<<dp[n];
	return 0;
}
