#include<bits/stdc++.h>
using namespace std;
int a[100001];
int n,m;
bool check(int t){
	int cnt=0,sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]>t) return false;
		if(sum+a[i]>t){
			cnt++;
			sum=a[i];
		} 
		else sum+=a[i];
	}
	if(sum) cnt++;
	return cnt<=m;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=0,r=1e9;
	int res=-1;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(check(mid)){
			res=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	cout<<res;
	return 0;
} 
/*
5 3
4 2 4 5 1
*/


