#include<iostream>
#include<algorithm>
using namespace std;
int n,m,x,y;
long long dp[21][21]={0};
bool ok[21][21]={false};

int dx[]={0,-2,-2,-1,-1,1,1,2,2};
int dy[]={0,1,-1,2,-2,2,-2,1,-1};

void init(int x,int y){
	for(int i=0;i<9;i++){
		if(x+dx[i]>=0&&x+dx[i]<=n&&y+dy[i]>=0&&y+dy[i]<=m)
			ok[x+dx[i]][y+dy[i]]=true; //代表不能走 
	}
}

int main(){
	cin>>n>>m>>x>>y;
	init(x,y);
	dp[0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(ok[i][j]) continue;
			if(i-1>=0) dp[i][j]+=dp[i-1][j];
			if(j-1>=0) dp[i][j]+=dp[i][j-1];
		}
	} 
	cout<<dp[n][m];
	return 0;
} 
