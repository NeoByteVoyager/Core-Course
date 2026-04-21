#include <bits/stdc++.h>
using namespace std;
# define int long long
const int maxn=1e5+5;
int parent[maxn]; 
//查找
int find(int x){
    return parent[x]==x?x:parent[x]=find(parent[x]);
}

struct Node{
    int u,v,w;
}; 

signed main()
{
    // 请在此输入您的代码
    int n,m;
    cin>>n>>m;
    vector<Node>edge(m);
    
    for(int i=1;i<=n;i++) parent[i]=i;
    
    for(int i=0;i<m;i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }
    sort(edge.begin(),edge.end(),[](auto &x,auto &y){
    	return x.w<y.w;
	}) ;
    
    long long res=0,cnt=0;
    for(int i=0;i<m;i++){
        int u=edge[i].u,v=edge[i].v;
        int fu=find(u),fv=find(v);
        if(fu==fv) continue;
        else {
            res+=edge[i].w;
            cnt++;
            if(cnt==n-1) break;
            parent[fu]=fv;
        }
    }
    if(cnt==n-1) cout<<res;
    else cout<<-1;
    return 0;
}
