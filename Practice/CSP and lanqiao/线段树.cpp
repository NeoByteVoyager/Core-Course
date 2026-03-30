#include<bits/stdc++.h>
using namespace std;
const int MAXN=5;
int arr[]={1,2,3,4};
int tree[4*MAXN];
//向上走 
void pushup(int u){
	tree[u]=tree[u<<1]+tree[u<<1|1];
}
//建树 
void build(int u,int l,int r){
	if(l==r){ //区间只有一个元素 
		tree[u]=arr[l];
		return ; 
	}
	int mid=(l+r)>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u); //根据子树算根 
}
//单点修改 x处加上v 
void update(int u,int l,int r,int x,int v){
	if(l==r) {
		tree[u]+=v;
		return ;
	}
	int mid=(l+r)>>1;
	if(x<=mid){
		update(u<<1,l,mid,x,v);
	}
	else{
		update(u<<1|1,mid+1,r,x,v);
	}
	pushup(u);
}
//查询 
int query(int u,int l,int r,int L,int R){
	if(r<L||l>R) return 0;
	if(L<=l&&r<=R) return tree[u];
	int sum=0;
	int mid=(l+r)>>1;
	sum+=query(u<<1,l,mid,L,R);
	sum+=query(u<<1|1,mid+1,r,L,R);
	return sum;
}
int main(){
	build(1,0,3);
	update(1,0,3,2,2); 
	cout<<query(1,0,3,1,2);
	return 0;
} 
