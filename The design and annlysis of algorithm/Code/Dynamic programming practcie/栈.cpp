#include<iostream>
using namespace std;
long long dp[19][19];//栈外i，栈内j 
int main(){
	int n;
	cin>>n;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(!i) dp[i][j]=1;//只能出栈，且顺序唯一 
			else if(!j) dp[i][j]=dp[i-1][j+1];//入栈 
			else dp[i][j]=dp[i][j-1]+dp[i-1][j+1];//出栈和入栈都可以 
		}
	}
	cout<<dp[n][0];
	return 0;
} 
