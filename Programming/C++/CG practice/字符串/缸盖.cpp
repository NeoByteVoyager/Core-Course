#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		int pos=s.find('^');
		int l=pos-1,cl=0,cwl=0;
		while(l>=0){
			cl++;
			if(s[l]!='='){
				cwl+=cl*(s[l]-'0');
			}
			l--;
		}
		int r=pos+1,cr=0,cwr=0;
		while(r<(int)s.size()){
			cr++;
			if(s[r]!='='){
				cwr+=cr*(s[r]-'0');
			}
			r++;
		}
		
		if(cwl==cwr){
			cout<<"balance\n";
		}
		else if(cwl>cwr){
			cout<<"left\n";
		}
		else cout<<"right\n";
	}
	return 0;
} 
