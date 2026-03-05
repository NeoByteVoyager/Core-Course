#include<bits/stdc++.h>
using namespace std;
struct Take{
	int t;
	bool take;
	int w;
};
int main(){
	int n,k;
	cin>>n>>k;
	vector<Take>time(2*k);
	
	for(int i=0;i<k;i++){
		int w,s,c;
		cin>>w>>s>>c;
		time[2*i].w=time[2*i+1].w=w;
		time[2*i].t=s;time[2*i].take=true;//ÄÃ 
		time[2*i+1].t=s+c;time[2*i+1].take=false;//»¹ 
	}
	
	sort(time.begin(),time.end(),[](Take &x,Take&y){
		if(x.t!=y.t)return x.t<y.t;
		 if(x.take!=y.take) return x.take<y.take;
		 return x.w<y.w; 
	}) ;
	

	vector<int>hook(n+1);
	for(int i=1;i<=n;i++) hook[i]=i;
	
	for(int i=0;i<2*k;i++){
		if(time[i].take){
			for(int j=1;j<=n;j++){
				if(hook[j]==time[i].w){
					hook[j]=-1;
					break;
				}
			}
		}
		else {
			for(int j=1;j<=n;j++){
				if(hook[j]==-1){
					hook[j]=time[i].w;
					break; 
				}
			}
		}
	}
	for(int i=1;i<=n;i++) cout<<hook[i]<<" ";
	return 0;
} 
