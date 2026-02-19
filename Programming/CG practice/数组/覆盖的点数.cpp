#include<iostream>
using namespace std;
const int maxn=6e5+2,maxm=2e5;
int c[maxn];
int cnt[maxm];
int main(){
	int n;
	cin>>n;
	int m=-1;
	int l,r;
	for(int i=1;i<=n;i++){
		cin>>l>>r;
		c[l]++;
		c[r+1]--;
		m=max(m,r);
	}
	int t=0;
	for(int i=0;i<=m;i++){
		t+=c[i];
		cnt[t]++;
	}
	for(int i=1;i<=n;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
