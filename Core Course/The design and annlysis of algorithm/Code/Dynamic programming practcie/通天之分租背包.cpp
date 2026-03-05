#include<bits/stdc++.h>
using namespace std;
int w[1001],v[1001],d[101];
int g[101][1001];
int dp[1001];
int main(){
	int m,n;
	cin>>m>>n;
	int M=0,x;
	for(int i=1;i<=n;i++){
		cin>>v[i]>>w[i]>>x;
		M=max(M,x);
		d[x]++;
		g[x][d[x]]=i;
	}
	for(int i=1;i<=M;i++){ 
		for(int j=m;j>=0;j--){
			for(int k=1;k<=d[i];k++){
				if(j>=v[g[i][k]])dp[j]=max(dp[j-v[g[i][k]]]+w[g[i][k]],dp[j]);
			}
		}
	}
	cout<<dp[m];
	return 0;
}
