#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		string s;
		cin>>n>>s;
		int S_t=0,T_s=0;
		for(int i=0;i<n-1;i++){
			if((s[i]=='S')&&(s[i+1]=='T')) S_t++;
			else if((s[i]=='T')&&(s[i+1]=='S')) T_s++;
		} 
//		cout<<S_t<<" "<<T_s<<endl; 
		if(S_t>T_s) cout<<"YES\n";
		else cout<<"NO\n"; 
	}
	return 0;
}
