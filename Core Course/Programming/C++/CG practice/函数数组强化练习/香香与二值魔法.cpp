#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>a(n,vector<int>(m));
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			sum+=a[i][j];
		}
	}	
	double t=sum/(1.0*m*n);

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]<t) cout<<0<<" ";
			else cout<<1<<" ";
		}
		cout<<endl;
	}
	return 0;
	
} 
