#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int fa[maxn];
void init(int n){
	for(int i=1;i<=n;i++) fa[i]=i;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

void Union(int u,int v){
	int fu=find(u);
	int fv=find(v);
	if(fu==fv) return ;
	else fa[fu]=fv;
}

int main(){
	int n,m;
	cin>>n>>m;
	int k;
	cin>>k;
	init(n*m);
	while(k--){
		int u,v;
		cin>>u>>v;
		Union(u,v);
	}
	int res=0; 
	for(int i=1;i<=m*n;i++){
		res+=(fa[i]==i);
	}
	cout<<res;
	return 0;
} 
