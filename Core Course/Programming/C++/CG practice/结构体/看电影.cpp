#include<bits/stdc++.h>
using namespace std;
struct moive{
	int id;
	int joy=0;
	int sat=0;
};
int main(){
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int m;
	cin>>m;
	vector<moive>t(m);
	for(int i=0;i<m;i++){
		int b;
		cin>>b;
		for(int j=0;j<n;j++){
			if(a[j]==b) t[i].joy++;
		}
	}
	for(int i=0;i<m;i++){
		t[i].id=i+1;
		int c;
		cin>>c;
		for(int j=0;j<n;j++){
			if(a[j]==c) t[i].sat++;
		}
	}
	sort(t.begin(),t.end(),[](moive&x,moive&y){
		if(x.joy!=y.joy) return x.joy>y.joy;
		else if(x.sat!=y.sat)return x.sat>y.sat;
		return x.id<y.id;
	});
	if(t[0].joy==0){
		cout<<"unsatisfied\n";
		return 0;
	}
	int p=t[0].joy,q=t[0].sat;
	for(int i=0;i<m;i++){
		if(t[i].joy==p&&t[i].sat==q) cout<<t[i].id<<" ";
		else return 0;
	}
	return 0;	
} 
