#include<bits/stdc++.h>
using namespace std;
class Node{
	friend class Solver;
	private:
		int cn,level,bound;
		vector<int>x;
	public:
		bool operator>(const Node&other)const{
			return bound>other.bound; 
		} 
}; 
class Solver{
	friend int MinCover(int n,int m,vector<int>&w,vector<pair<int,int>>&,vector<int>&x);
	
	private:
		int n,m;
		vector<int>w;
		vector<pair<int,int>>e;
		vector<int>x;
		int bestcn;
	public:
		void solve(){
			bestcn=INT_MAX;//
			Node node;
			node.cn=0;
			node.level=0;
			node.bound=0;
			node.x.assign(n+1,0);
			priority_queue<Node,vector<Node>,greater<Node>>pq;		
			pq.push(node);
			while(!pq.empty()){
				Node u=pq.top();
				pq.pop();
				if(u.bound>bestcn) continue;
				if(u.level==n){
					if(cover(u)&&u.cn<bestcn){
						x=u.x;
						bestcn=u.cn;
						break;
					}
					continue; //
				}
				//进入左子树
				Node v=u;
				v.level++;
				pq.push(v);
				
				//进入右子树
				v=u;
				v.level++;
				v.x[v.level]=1;
				v.cn+=w[v.level];
				v.bound+=w[v.level];
				pq.push(v); //
			}
		}
		bool cover(const Node&node){//
			for(auto it:e){
				int u=it.first;
				int v=it.second;
				if(!node.x[u]&&!node.x[v]){
					return false;
				}
			}
			return true;
		}
		
};
int MinCover(int n,int m,vector<int>&w,vector<pair<int,int>>&e,vector<int>&x){
	int bestcn=INT_MAX;
	Solver solver;
	solver.n=n;
	solver.m=m;
	solver.w=w;
	solver.e=e;
	solver.solve();
	bestcn=solver.bestcn;
	x=solver.x;
	return bestcn;
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<int>w(n+1);//
	vector<pair<int,int>>e; 
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		e.push_back({u,v}); 
//		edge[u].push_back(v);
//		edge[v].push_back(u);
	}
	vector<int>x; 
	int res=MinCover(n,m,w,e,x);
	cout<<res<<endl;
	for(int i=1;i<=n;i++) cout<<x[i]<<" "; 
	return 0;
} 
