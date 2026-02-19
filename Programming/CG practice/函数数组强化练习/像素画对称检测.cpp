#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<vector<int>>a(n+1,vector<int>(n+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n/2;j++){
			if(a[i][j]!=a[i][n-j+1]){
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<"YES";
	return 0;
} 
