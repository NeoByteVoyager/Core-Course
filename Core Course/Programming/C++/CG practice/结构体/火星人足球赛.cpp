#include<bits/stdc++.h>
using namespace std;
int c1[100],c2[100];
struct T{
	char d;
	int id;
	int t;
};
int main(){
	string h,p;
	cin>>h>>p;
	int n;
	cin>>n;
	vector<T>a;
	for(int i=0;i<n;i++){
		int t,m;
		char x,y;
		cin>>t>>x>>m>>y;
		if(y=='r'){
			a.push_back({x,m,t});
		}
		else{
			if(x=='h'){
				c1[m]++;
				if(c1[m]==2){
					a.push_back({x,m,t});
				}
			}
			else{
				c2[m]++;
				if(c2[m]==2){
					a.push_back({x,m,t});
				}
			}
		}
	}
	if(a.empty()){
		cout<<"No Red Card\n";
		return 0;
	} 
	sort(a.begin(),a.end(),[](T&x,T&y){
		if(x.t!=y.t) return x.t<y.t;
		else if(x.d!=y.d) return x.d>y.d;
		return x.id>y.id;
	});
	for(auto item:a){
		if(item.d=='h') cout<<h<<" ";
		else cout<<p<<" ";
		cout<<item.id<<" "<<item.t<<endl;
	}
	return 0;
} 
