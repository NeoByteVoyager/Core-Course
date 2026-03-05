#include<iostream>
#include<string>
using namespace std;
string s[2001];
int dp[2002];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	int res=-1; 

	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			size_t pos;
			if((pos=s[i].find(s[j]))==0) dp[i]=max(dp[i],dp[j]+1);
		}
		res=max(res,dp[i]);
	}
	cout<<res;
	return 0;
} 
