#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	string res;
	int n=s.size();
	int i=0;
	while(i<n){
		if(i+2<n&&s.substr(i,3)=="WUB"){//要调过的字符窜 
			i+=3;
		}
		else{
			string t;
			while(i+2<n&&s.substr(i,3)!="WUB"){//要保留的字符串 
				t+=s[i];
				i++; 
			}
			if(i+2>=n){//最后的字符串小于3直接保留 
				t+=s.substr(i);
				i=n;
			} 
			res+=t+" ";
		}
	}
	cout<<res;
	return 0;
} 
