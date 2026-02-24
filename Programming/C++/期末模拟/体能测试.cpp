#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k;
	cin>>n>>m>>k; 
	vector<int>stu(m+1,0);
	if(m*k==n){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int id;
		cin>>id;
		stu[id]++;
	}
	for(int i=1;i<=m;i++){
		if(stu[i]==k) continue;
		cout<<i<<" "; 
		for(int j=stu[i]+1;j<=k;j++) cout<<j<<" ";
		cout<<endl;
	}
	return 0;
} 
