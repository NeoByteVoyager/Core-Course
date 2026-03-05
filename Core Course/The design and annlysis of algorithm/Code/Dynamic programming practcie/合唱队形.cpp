#include<iostream>
#include<climits>
using namespace std;
int a[101],b[101];
int h[102];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>h[i];
	h[n+1]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			if(h[j]<h[i]) a[i]=max(a[i],a[j]+1);
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=n+1;j>i;j--){
			if(h[j]<h[i]) b[i]=max(b[i],b[j]+1);
		}
	}
	int res=INT_MIN;
	for(int i=1;i<=n;i++){
	
		res=max(res,a[i]+b[i]-1);
	}
	cout<<n-res;
	return 0;
} 
