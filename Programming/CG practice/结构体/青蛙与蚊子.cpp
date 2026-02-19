#include<bits/stdc++.h>
using namespace std;
struct wa{
	int p;
	int l;
	int c=0;
};
int main(){
	int n,m;
	cin>>n>>m;
	vector<wa>w(n);
	for(int i=0;i<n;i++) cin>>w[i].p>>w[i].l;
	vector<int>p(n),b(n); 
	vector<bool>vis(n,true);
	for(int i=0;i<m;i++){
		int x,t;
		cin>>x>>t;
		p[i]=x,b[i]=t;
		//判断能不能被吃 
		int id=-1,pos=INT_MAX;		
		for(int j=0;j<n;j++){
			if(x>=w[j].p&&x<=w[j].p+w[j].l){
				if(w[j].p<pos){
					id=j;
					pos=w[j].p;
				}
			}
		}
		//能被吃掉，看能不能吃原来没被吃的 
		if(id!=-1){
			w[id].c++;
			w[id].l+=t;
			while(true){
				bool ok=false;
				for(int k=0;k<i;k++){
					if(!vis[k]&&p[k]>=w[id].p&&p[k]<=w[id].p+w[id].l){
						ok=true;
						vis[k]=true;
						w[id].c++;
						w[id].l+=b[k];
					}
				}
				if(!ok) break;
			}	
		}
		//不能吃掉做标记 
		else vis[i]=false;
	}
	for(int i=0;i<n;i++){
		cout<<w[i].c<<" "<<w[i].l<<endl;
	}
	return 0;
} 
