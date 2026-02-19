#include<bits/stdc++.h>
using namespace std;
vector<int>a;
void qsort(int l,int r){
	if(l>=r) return ;
	int x=a[l];
	int i=l,j=r+1;
	while(true){
		while(i<r&&a[++i]<x);
		while(j>l&&a[--j]>x);
		if(i>=j) break;
		swap(a[i],a[j]);
	}
	swap(a[j],a[l]);
	qsort(l,j-1);
	qsort(j+1,r);
}
int main(){
	int n;
	cin>>n;
	
	a.resize(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	qsort(0,n-1);
	
	for(int i:a) cout<<i<<" ";
	return 0;
} 
