#include <bits/stdc++.h>
using namespace std;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
struct P{
	int x,y;
	char c;
};
bool ok(char c1,char c2){
	if(c1=='A'||c2=='B') return true; //
	if(c1=='+'&&c2=='-') return true;
	if(c1=='-'&&c2=='+') return true;
	return false; 
}
int main()
{
    // 请在此输入您的代码
    int n;
    cin>>n;
    vector<vector<char>>a(n,vector<char>(n));
    vector<vector<bool>>vis(n,vector<bool>(n,false));
    
    int si,sj;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(a[i][j]=='A') {
                si=i,sj=j;
            }
        }
    }
    
    queue<P>q;
    P p;
    p.x=si,p.y=sj,p.c='A';
    q.push(p);
    vis[si][sj]=true;
    
    bool found=false;
    int step=0;
    while(!q.empty()){
    	int sz=q.size();
    	for(int i=0;i<sz;i++){
    		P p=q.front();
    		if(a[p.x][p.y]=='B') {
    			cout<<step<<endl;
				return 0;
			}
    		q.pop();
    		for(int j=0;j<4;j++){
    			int x=p.x+dx[j],y=p.y+dy[j];
    			if(x<0||x>=n||y<0||y>=n||vis[x][y]||!ok(p.c,a[x][y])) continue;
				P t;
				t.x=x,t.y=y;
				t.c=a[x][y];
				q.push(t);
				vis[x][y]=true; 
			}
		}
		step++;
	}
    if(found) cout<<step;
    else cout<<-1;
    
    return 0;
}
