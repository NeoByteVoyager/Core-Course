#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n=s.size();
	string res;
	for(int k=n-1;k>=1;k--){
		for(int i=0;i<=n-k;i++){
			string t=s.substr(i,k);
			if(s.find(t,i+1)!=string::npos){
				cout<<t;
				return 0;
			}
		}
	}
	cout<<"No string";
	return 0;
} 
