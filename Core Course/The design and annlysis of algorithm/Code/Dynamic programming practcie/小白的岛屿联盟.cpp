#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=1001;
string s[maxn];
bool vis[maxn][maxn];
int cnt=0,res=INT_MIN;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
void dfs(int i,int j,int &t){
	vis[i][j]=true;
	t++;
	for(int k=0;k<4;k++){
		int nx=i+dx[k];
		int ny=j+dy[k];
		if(nx<1||ny<1||nx>n||ny>m) continue; 
		if(s[nx][ny]=='1'&&!vis[nx][ny]) dfs(nx,ny,t);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>s[i];
		s[i]=" "+s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='1'&&!vis[i][j]){
				int t=0;
				dfs(i,j,t);
				res=max(res,t);
				cnt++;
			}
		}
	}
	cout<<cnt<<" "<<res; 
	return 0;
} 
