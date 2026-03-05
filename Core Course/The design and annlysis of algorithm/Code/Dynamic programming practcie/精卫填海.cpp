#include<iostream>
using namespace std;
const int maxn=1e4+2;
int dp[maxn];
int v[maxn],c[maxn];
int main(){
	int V,n,C;
	cin>>V>>n>>C;
	for(int i=1;i<=n;i++) cin>>v[i]>>c[i];
	for(int i=1;i<=n;i++){
		for(int j=C;j>=c[i];j--){
			dp[j]=max(dp[j],dp[j-c[i]]+v[i]);
						
		}
	}
	for(int j=1;j<=C;j++){
		if(dp[j]>=V){
			cout<<C-j;
			return 0;
		}
	}
	cout<<"Impossible";
	return 0;
} 
