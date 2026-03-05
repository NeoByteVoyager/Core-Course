#include<iostream>
#include<climits> 
using namespace std;
int a[2003][2003];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int j=2;j<=n;j++){
		a[1][j]=min(a[m][j-1]+a[1][j],a[1][j-1]+a[1][j]);//
		for(int i=2;i<=m;i++){
			a[i][j]=min(a[i-1][j-1]+a[i][j],a[i][j-1]+a[i][j]);//
		}
		
	}
	int res=INT_MAX;
	for(int i=1;i<=m;i++) res=min(res,a[i][n]);//
	cout<<res;
	return 0;
} 
