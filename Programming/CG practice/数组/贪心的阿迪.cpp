#include<iostream>
using namespace std;
int main(){
	int n,k,m,d;
	cin>>n>>k>>m>>d; 
	int maxm=-1;
	for(int i=1;i<=m;i++){
		if(k*i*d<n) continue;
		int cnt=n/(k*i)*i;
		int t=n%(k*i);
		if(t>=i) cnt+=i;
		else cnt+=t;
		maxm=max(cnt,maxm);
	} 
	cout<<maxm;
	return 0;
} 
