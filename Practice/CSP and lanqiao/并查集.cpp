#include<bits/stdc++.h>
using namespace std;
class DSU{
	private:
		int num;
		vector<int>fa;
		vector<int>sz;
	public:
		DSU(int n):num(n){
			fa.resize(n);  
			sz.resize(n,1);
			//初始化每个节点的父亲节点都是自己 
			for(int i=0;i<n;i++) fa[i]=i;
		}
		int find(int x){
			if(fa[x]==x) return x; //搜索到该树的根节点 
			else return fa[x]=find(fa[x]); //路径压缩 
		} 
		void Union(int u,int v){
			int fu=find(u); //
			int fv=find(v); //
			if(fu==fv) return ; //已经在同一个集合中 
			if(sz[fu]>sz[fv]){
				fa[fv]=fu;
			}
			else if(sz[fu]<sz[fv]){
				fa[fu]=fv;
			}
			else {
				fa[fu]=fv;
				sz[fv]++;
			}
		}
		int gettotal(){
			int res=0;
			for(int i=0;i<num;i++){
				if(fa[i]==i) res++;
			}
			return res;
		}
};
int main(){
	int m,n;
	cin>>m>>n;
	DSU a(m*n);
	int k;
	cin>>k;
	while(k--){
		int u,v;
		cin>>u>>v;
		a.Union(u,v);
	}
	cout<<a.gettotal();
	return 0;
} 
