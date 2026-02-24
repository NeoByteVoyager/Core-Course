#include<bits/stdc++.h>
using namespace std;
struct T{
	int dist;
	int id;
}; 
int main(){
	int n,x,y,k;
	cin>>n>>x>>y>>k;
	vector<T>a;
	for(int i=0;i<n;i++){
		int p,q;
		cin>>p>>q;
		int dist=(x-p)*(x-p)+(y-q)*(y-q);
		if(dist<=k*k) a.push_back({dist,i+1});
	} 
	if(a.empty()) {
		cout<<-1<<endl;
		cout<<-1<<" "<<-1;
		return 0;
	}
	for(T t:a) cout<<t.id<<" ";
	cout<<endl;
	sort(a.begin(),a.end(),[](T&p,T&q){
		if(p.dist!=q.dist) return p.dist<q.dist;
		return p.id<q.id;
	});
	int num=a.size();
	cout<<a[0].id<<" "<<a[num-1].id;
	
	return 0;
} 
