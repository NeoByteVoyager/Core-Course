#include<bits/stdc++.h>
using namespace std;
class SegTree{
private:
	vector<int>tree;
	int n;
	
	//构建树
	void buildTree(vector<int>&arr,int node,int start,int end){
		if(start==end){
			tree[node]=arr[start];
			return ;
		}
		int mid=start+(end-start)/2;
		buildTree(arr,2*node+1,start,mid);
		buildTree(arr,2*node+2,mid+1,end);
		tree[node]=min(tree[node*2+1],tree[node*2+2]);
	}
	//查询
	int query_(int node,int start,int end,int l,int r){
		if(r<start||l>end)return INT_MAX;//
		if(l<=start&&r>=end) return tree[node];//当要查找的区间包含树的节点的区间
		int mid=start+(end-start)/2;
		int lmin=query_(2*node+1,start,mid,l,r);
		int rmin=query_(2*node+2,mid+1,end,l,r);
		return min(lmin,rmin); 
	}
	//修改 
	void update(int node,int start,int end,int idx,int val){
		if(start==end) {
			tree[node]=val;
			return ;
		}
		int mid=start+(end-start)/2;
		if(idx<=mid) update(node*2+1,start,mid,idx,val);
		else update(node*2+2,mid+1,end,idx,val);
		tree[node]=min(tree[node*2+1],tree[node*2+2]);
	} 
	
public:
	SegTree(vector<int>&arr){
		n=arr.size();
		tree.resize(4*n);
		buildTree(arr,0,0,n-1);
	} 
	int query(int l,int r){
		return query_(0,0,n-1,l,r);
	}
	void update(int idx,int val){
		update(0,0,n-1,idx,val);
	}
	
};
int main(){
	int m,n;
	cin>>m>>n;
	vector<int>arr(m);
	for(int i=0;i<m;i++)cin>>arr[i];
	SegTree st(arr);
	while(n--){
		int l,r;
		cin>>l>>r;
		cout<<st.query(l-1,r-1)<<" ";
	}
	return 0;
} 
