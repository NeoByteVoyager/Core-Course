#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T; 
	while(T--){
		int n,m;
		cin>>n>>m;
		vector<string>s(n); 
		for(int i=0;i<n;i++){
			cin>>s[i];
		} 
		vector<pair<int,int>>p;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(s[i][j]=='*') 
					p.push_back({i,j});
			}
		}	
		bool ok=false;
		for(int i=0;i<n;i++){ 
			for(int k=0;k<m;k++){
				int x=i,y=k;

				bool yes=true;
				for(int j=0;j<p.size();j++){
					if(p[j].first==x||p[j].second==y){
						continue;
					}
					else{
						yes=false;
						break;
					}
				}
				if(yes){
					cout<<"YES\n";
					ok=true;
					break; 
				}
			}
			if(ok){
				break;
			} 
		}
		if(!ok) cout<<"NO\n";
	}
	return 0;
} 
