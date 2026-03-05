#include<bits/stdc++.h>
using namespace std;
struct s{
	int id;
	int c1[26];
	int c2[26];
};
s b[13];
double a[13][3];
int main(){
	int p,q,d;
	cin>>p>>q>>d;
	for(int i=1;i<=p;i++){
		int t=0;
		for(int j=1;j<=q;j++) {
			cin>>b[i].c1[j];
			t+=b[i].c1[j];
		}
		a[i][1]=1.0*t/q;
		t=0;
		for(int j=1;j<=q;j++){
			cin>>b[i].c2[j];
			t+=b[i].c2[j];
		} 
		a[i][2]=1.0*t/q;
	}
	bool flag=false;
	for(int i=1;i<=p;i++){
		for(int j=1;j<=q;j++){
			bool v1=((b[i].c1[j]<a[i][1])&&(b[i].c2[j]<a[i][2]));
			bool v2=(abs(b[i].c1[j]-b[i].c2[j])>d);
			if(v1||v2) {
				cout<<i<<" "<<j<<endl;
				flag=true;
			}
		}
	}
	if(!flag) cout<<0;
	return 0;
} 
