#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int target=3; 
	int l=0,r=n-1;//查找最后一个<=3 
	while(l<r){
		int mid=(l+r+1)>>1;
		if(a[mid]>target) r=mid-1;
		else l=mid;
	} 
	cout<<l<<" "<<r;
	return 0; 
} 
/* 
5
1 3 3 5 7
*/
