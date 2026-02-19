#include<bits/stdc++.h>
using namespace std;
struct train{
	int r,tot,u;//tot表示车上现存 
	bool block;
	int cnt;//总共运输成员 
};
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	vector<train>v(a+1);
	for(int i=1;i<=a;i++){
		v[i].r=i;
		v[i].tot=0;
		v[i].u=-1;
		v[i].block=false;
		v[i].cnt=0;
	}
	while(c--){
		int op;
		cin>>op;
		if(op==1){
			int r,s,t,u;
			cin>>r>>s>>t>>u;
			v[r].tot=t-s+1;
			v[r].u=u;
			v[r].cnt+=t-s+1;
		}
		else if(op==2){
			int r,s,t;
			cin>>r>>s>>t;
			for(int i=r;i<=s;i++){
				v[i].block=true;
				v[i].cnt-=v[i].tot;
				if(v[i].u==v[t].u) {
					v[t].tot+=v[i].tot;
					v[i].tot=0;
					v[t].cnt+=v[i].tot;
				} 
			}
		}
		else if(op==3){
			int u,V,w;
			cin>>u>>V>>w;
			if(v[w].tot==0){//还是空车 
				v[w].tot=V-u+1;
				v[w].u=1;
				v[w].cnt+=V-u+1;
			}
			else{
				v[w].tot+=V-u+1;
				v[w].cnt+=V-u+1;
			}
		}
		else if(op==4){
			int c;
			cin>>c;
			if(v[c].cnt)
				cout<<v[c].cnt;
			else{
				int res=0;
				for(int i=0;i<a;i++){
					if(v[i].u==1) res+=v[i].cnt;
				}
				cout<<res;
			}
		}
	}
	return 0;
} 
