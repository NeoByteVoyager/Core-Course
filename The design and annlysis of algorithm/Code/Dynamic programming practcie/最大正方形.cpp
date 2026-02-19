#include<iostream>
using namespace std;
int n,m;
int a[101][101];
int prefix[101][101];
bool check(int mid){
	for(int i=1;i<=n-mid+1;i++){
		for(int j=1;j<=m-mid+1;j++){
			int t=prefix[i+mid-1][j+mid-1]-prefix[i+mid-1][j-1]-prefix[i-1][j+mid-1]+prefix[i-1][j-1];
			if(t==mid*mid)return true;
		}
	}
	return false;
}
int main(){
	
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=m;j++){
			sum+=a[i][j];
			prefix[i][j]=prefix[i-1][j]+sum;
//			cout<<prefix[i][j]<<" ";
		}
//		cout<<endl;
	}
	int res=-1;
	int l=0,r=min(n,m);
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			res=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	} 
	cout<<res;
	return 0;
} 
