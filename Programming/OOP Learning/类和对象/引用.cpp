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
	friend MinCover(int n,int m,vector<int>&w,vector<vector<int>>&edge);
	
	
};
int MinCover(int n,int m,vector<int>&w,vector<vector<int>>&edge);
int main(){
	int n,m;
	cin>>n>>m;
	vector<int>w(n);
	vector<vector<int>>edge(n);
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	int res=MinCover(n,m,w,edge);
	cout<<res;
	return 0;
} 
