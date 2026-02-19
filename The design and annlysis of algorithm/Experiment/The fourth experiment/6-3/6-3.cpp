#include<bits/stdc++.h>
using namespace std;
struct Node{
	int bound;
	int level;
	vector<bool>x;	
	bool operator<(const Node&other)const {
		return bound<other.bound;
	}
};
int n,m;
vector<vector<int>>Edge;//边 
vector<pair<int,int>>e;
int getnow(Node &u){
	int res=0;
	for(int i=0;i<m;i++){
		int p=e[i].first,q=e[i].second;
		if((u.x[p]&&!u.x[q])||(!u.x[p]&&u.x[q])){
			res++;
		} 
	}
	return res;
}
int calBound(Node& u){
	int res=0;
	for(int i=0;i<m;i++){
		int p=e[i].first,q=e[i].second;
		if(p<=u.level&&q<=u.level){
			if(u.x[p]==u.x[q]) res++;
		}
	}
	return m-res;
}
int main(){
	
	cin>>n>>m;
	
	Edge.resize(n+1);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		Edge[u].push_back(v);
		Edge[v].push_back(u);
		e.push_back({u,v});
	}
	
	Node root;
	root.bound=0;
	root.level=0;
	root.x.resize(n+1,false);
	priority_queue<Node>pq;
	pq.push(root);
	
	int res=0;
	vector<bool>bestx;
	
	while(!pq.empty()){
		Node u=pq.top();
		pq.pop();
//		if(u.bound<=res) continue;
		if(u.level==n){
			//计算割边
			int tmp=getnow(u);
			if(tmp>res){
				res=tmp;
				bestx=u.x;
				if(!pq.empty()&&tmp>pq.top().bound)break;
			} 
			continue;
		}	
		Node v;	
		v.level=u.level+1;
		v.x=u.x;
		 
		//不选该节点
		v.x[v.level]=false;
		int t=calBound(v);
		if(t>res){
			v.bound=t;	
			pq.push(v); 
		}
		//选该节点 
		
		v.x[v.level]=true;
		t=calBound(v);
		if(t>res){
			v.bound=t;
			pq.push(v);
		}
	
		
	}
	
	cout<<res<<endl;
	for(int i=1;i<=n;i++) cout<<bestx[i]<<" ";
	
	return 0;
}
