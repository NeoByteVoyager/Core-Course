#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		
		int lr=-1;
		int n=s.size();
		bool ok=true; 
		for(int i=0;i<n;i++){
			if(s[i]=='.') continue;
			int nowl=i-(s[i]-'0')>=0?i-(s[i]-'0'):0;
			int nowr=i+(s[i]-'0')<n?i+(s[i]-'0'):n-1;
//			cout<<nowl<<" "<<nowr<<endl; 
			if(nowl<=lr) {
				ok=false;
				cout<<"unsafe\n";
				break; 
			}	
			lr=nowr;
		}
		if(ok)
			cout<<"safe\n";
		
	}
	return 0;
} 
