#include <bits/stdc++.h>
using namespace std;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int n;
vector<vector<bool>>vis;
vector<int>x,y;
vector<int>now,res;
bool found=false;
void dfs(int i,int j){
	if(found) return;
    if(i==n-1&&j==n-1) {
        for(int k:x) if(k) return;
        for(int k:y) if(k) return;
        //所有位置都符合,保存结果
        res=now;
        found=true;
        return ;
    }
    for(int k=0;k<4;k++){
        int xi=i+dx[k],yi=j+dy[k];
        if(xi<0||xi>=n||yi<0||yi>=n||vis[xi][yi]) continue;
        if(x[xi]<=0||y[yi]<=0) continue;
        x[xi]--,y[yi]--;
        now.push_back(xi*n+yi);
        vis[xi][yi]=true;
        dfs(xi,yi);
        vis[xi][yi]=false;
        x[xi]++,y[yi]++;
        now.pop_back();
    }
}
int main()
{
    // 请在此输入您的代码
    cin>>n;
    x.resize(n);
	y.resize(n); 
    for(int i=0;i<n;i++) cin>>y[i];
    for(int i=0;i<n;i++) cin>>x[i];
    vis.resize(n,vector<bool>(n,false));

	vis[0][0]=true;
	x[0]--,y[0]--;
	now.push_back(0);
    dfs(0,0);

    for(int i:res) cout<<i<<" ";

    return 0;
}
