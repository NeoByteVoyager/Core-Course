#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1);
	vector<vector<int>>t(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	while(m--){
		int x,y;
		cin>>x>>y;
		t[x].push_back(y);
		t[y].push_back(x);
	}
	vector<int>cnt(n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j==i) continue;
			if(a[i]>a[j]){
				bool ok=true;
				for(int k:t[i]){
					if(k==j){
						ok=false;
						break;
					}
				}
				if(ok) cnt[i]++;
			}
		}
		cout<<cnt[i]<<" ";
	} 
	return 0;
} 
