#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	char t=s[0];
	int len=s.size();
	string res;
	int cnt=1;
	for(int i=1;i<len;i++){
		if(s[i]==t){
			cnt++;
		}
		else{
			res+=t;
			if(cnt>1) res+=to_string(cnt);
			t=s[i];
			cnt=1;
		}
	}
	res+=t;
	if(cnt>1) res+=to_string(cnt);
	cout<<res;
	return 0;
} 
