#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int tree[MAXN];
int lowbit(int x){
	return x&-x;
} 
void add(int id,int val){
	for(int i=id;i<MAXN;i+=lowbit(i)){
		tree[i]+=val;
	}
}
int query(int x){
	int res=0;
	while(x){
		res+=tree[x];
		x-=lowbit(x);
	}
	return res;
}
int main(){
	int n;
	cin>>n;
	
	unordered_map<int,int>mp;
	
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(!mp.count(x)){ //数组中还未出现该元素 
			cout<<-x<<" ";
		}
		else{
			cout<<query(i-1)-query(mp[x])<<" ";
			add(mp[x],-1); //关闭这盏灯 
		}
		add(i,1); //开启最后一盏灯 
		mp[x]=i;
	}
		
	return 0;
} 
