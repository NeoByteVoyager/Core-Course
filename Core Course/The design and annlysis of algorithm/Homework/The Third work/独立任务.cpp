#include<bits/stdc++.h>
using namespace std;
const int maxn=1001;
int a[maxn],b[maxn];
int main(){
	ifstream fin("D:\\Core Course\\The design and annlysis of algorithm\\Homework\\The Third work\\input.txt");
	ofstream fout("D:\\Core Course\\The design and annlysis of algorithm\\Homework\\The Third work\\output.txt");
	int n;
	fin>>n;
	int s=0;
	for(int i=1;i<=n;i++) {
		fin>>a[i];
		s+=a[i];
	}
	for(int i=1;i<=n;i++) fin>>b[i];
	vector<vector<int>>dp(n+1,vector<int>(s+1));
	dp[0][0]=0;
	for(int j=1;j<=s;j++) dp[0][j]=2e8;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=s;j++){
			if(j>=a[i]) dp[i][j]=min(dp[i-1][j-a[i]],dp[i-1][j]+b[i]);
			else dp[i][j]=dp[i-1][j]+b[i];
		}
	} 
	int res=INT_MAX;
	for(int j=0;j<=s;j++){
//		cout<<dp[n][j]<<" "<<j<<endl;
		res=min(res,max(dp[n][j],j));
	}
	fout<<res;
	return 0;
} 
