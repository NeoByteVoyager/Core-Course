#include<bits/stdc++.h>
using namespace std;
const int MAXN=9;
int tree[MAXN];
//得到二进制中1最低位 
int lowbit(int x){
	return x&-x; //补码求法的特性 
}
//单点修改，要进行维护，所有包含该点的区间都要进行更新 
void add(int id,int val){
	for(int i=id;i<MAXN;i+=lowbit()) {
		tree[i]+=val;
	}
}
//查询   每次加上二进制最后一个1的长度 
int query(int x){
	int res=0;
	while(x){
		res+=tree[x];
		x-=lowbit(x);
	}
	return res;
}

int main(){
	add(3,5);
	cout<<query(8)<<endl;
	cout<<query(5)<<endl;
	cout<<query(4)<<endl;
	return 0;
} 
