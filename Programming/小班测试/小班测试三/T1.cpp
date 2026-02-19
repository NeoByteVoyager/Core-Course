#include<bits/stdc++.h>
using namespace std;
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>a(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	} 
	
	
	vector<vector<bool>>vis(n,vector<bool>(m,false));
	vis[0][0]=true;
	queue<pair<int,int>>q;
	q.push({0,0});
	
	int step=1;
	while(!q.empty()){
		int k=q.size();
		step++;
		for(int j=0;j<k;j++){
			auto it=q.front();
			q.pop();
			int u=it.first,v=it.second;
			int x,y;
			for(int i=0;i<4;i++){
				x=u+dx[i];
				y=v+dy[i];
				if(x<0||x>=n||y<0||y>=m) continue;
				if(a[x][y]) continue; 
				if(vis[x][y]) continue;
				
				if(x==n-1&&y==m-1){
					cout<<step;
					return 0;
				}
				else {
					vis[x][y]=true;
					q.push({x,y});
				}
			}
		}	
	}
	cout<<"No";
	return 0;
} 

/*
9 8
 0	 0	 1	 0	 0	 0	 1	 0
 0	 0	 1	 0	 0	 0	 1	 0
 0	 0	 0	0	1	1	 0	 1
 0	 1	 1	 1	 0	 0	 1	 0
 0	 0	 0	 1	 0	 0	 0	 0
 0	 1	 0	 0	 0	 1	 0	 1
 0	 1	 1	 1	 1	 0	 0	 1
 1	 1	 0	 0	 0	 1	 0	 1
 1	 1	 0	 0	 0	 0	 0	 0
*/
