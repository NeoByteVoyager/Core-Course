#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=20;
int p[maxn],A[maxn];
bool vis[maxn]={false};
void getA(int n){
	A[1]=1;
	for(int i=2;i<=n-1;i++)
		A[i]=A[i-1]*i;
}
ll getIndex(int n){
	ll res=0;
	for(int now=1;now<=n;now++){
		for(int i=1;i<p[now];i++){
			if(!vis[i]){
				res+=A[n-now]; 
			} 	
		}
		vis[p[now]]=true;
	}
	return res;
}
void get_next_permutation(int p[],int n){
	int i=n,j=n+1;
	while(p[i-1]>p[i]){
		i--;	
	}
	while(p[--j]<p[i-1]);
	swap(p[i-1],p[j]);
	reverse(p+i,p+n+1);
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	getA(n);
	ll res=getIndex(n);
	cout<<res<<endl; 
	get_next_permutation(p,n); 
	for(int i=1;i<=n;i++) cout<<p[i]<<" "; 
	return 0;
}
/*
8
2 6 4 5 8 1 7 3
*/
