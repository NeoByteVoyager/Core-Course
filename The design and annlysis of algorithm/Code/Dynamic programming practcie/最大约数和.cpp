#include<bits/stdc++.h>
using namespace std;
int w[1001],dp[1001];
void generate(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(i%j==0) w[i]+=j;
		}
	}
}
int main(){
	int n;
	cin>>n;
	generate(n);
	for(int i=1;i<=n;i++){
		for(int j=n;j>=i;j--){
			dp[j]=max(dp[j-i]+w[i],dp[j]);
		}
	}
	cout<<dp[n];
	return 0;
} 
