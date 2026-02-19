#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<bool>>t(n+1,vector<bool>(m+1,false));
	vector<int>tot(m+1,0);
	for(int i=1;i<=n;i++){
		int sum;
		cin>>sum;
		for(int j=1;j<=sum;j++){
			int id;
			cin>>id;
			tot[id]++;
			t[i][id]=true;
		}
	} 
	vector<int>cnt(m+1,0);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cnt[i]+=t[j][i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" "<<tot[i]<<endl;
	}
	return 0;
} 
