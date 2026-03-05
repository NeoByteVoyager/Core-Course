#include<iostream>
using namespace std;
const int mod=1e6+7;
int dp[101][101];
int v[100];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>v[i];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(!i&&!j) {
				dp[i][j]=1;
				continue; 
			}
			else if(!i){
				dp[i][j]=0;
				continue;
			}
			for(int k=0;k<=min(j,v[i]);k++){
				dp[i][j]=(dp[i][j]%mod+dp[i-1][j-k]%mod)%mod;
			}
		}
	}
	cout<<dp[n][m];
	return 0;
} 
