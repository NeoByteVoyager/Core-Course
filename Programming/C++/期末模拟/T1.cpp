#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	if(n==m*k){
		cout<<0;
		return 0;
	}
	vector<int>a(m+1,0);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a[x]++;
	} 
	for(int i=1;i<=m;i++){
		if(a[i]!=k) {
			cout<<i<<" ";
			for(int j=a[i]+1;j<=k;j++){
				cout<<j<<" ";
			}
			cout<<endl; 
		}
		
	}
	return 0;
}
