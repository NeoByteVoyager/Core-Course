#include<bits/stdc++.h>
using namespace std;
int main(){
	string a,b;
	cin>>a>>b;
	
	int n=a.size(),m=b.size();
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	
	vector<int>res(m+n,0); 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			res[i+j]+=(int)(a[i]-'0')*(int)(b[j]-'0');
		}
	} 
	int car=0;
	for(int i=0;i<m+n;i++){
		res[i]+=car;
		car=res[i]/10;
		res[i]%=10;
//		cout<<res[i]<<endl;
	}

	bool f=false;
	for(int i=m+n-1;i>=0;i--){
		if(!f&&!res[i]) continue;
		else{
			f=true;
			cout<<res[i];
		}
	}
	return 0;
} 
