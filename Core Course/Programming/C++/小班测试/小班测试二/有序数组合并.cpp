#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m*n;i++){
		cin>>a[i];
	}
	sort(a,a+m*n);
	for(int i=0;i<m*n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
} 
