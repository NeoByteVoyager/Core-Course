#include<bits/stdc++.h>
using namespace std;
int solve(string s){
	int n=s.size();
	if(n<=1) return 1;
	vector<vector<bool>>dp(n,vector<bool>(n,false));
	int res=1;
	for(int len=2;len<=n;len++){
		for(int i=0;i<=n-len;i++){
			int j=i+len-1; 
			if(s[i]==s[j]){
				if(len<=3) dp[i][j]=true;
				if(dp[i+1][j-1]) dp[i][j]=true;
			}
			if(dp[i][j]&&len>res) res=len;
		}
	}
	return res;
}
int main(){
	string t;
	cin>>t;
	cout<<solve(t); 
	return 0;
} 
