#include<bits/stdc++.h>
using namespace std;
bool vis[26]={false};
bool solve(string s,string t){
	if(s.size()!=t.size()) return false;
	unordered_map<char,char>mp1;
	for(int i=0;i<s.size();i++){
		char c=s[i];
		if(mp1.find(c)!=mp1.end()){
			if(mp1[c]!=t[i]) return false;
		}
		else{
			if(vis[t[i]-'a']) return false;
			else{
				vis[t[i]-'a']=true;
				mp1[c]=t[i];
			}
		}
	}
	return true;
}
int main(){
	string s,t;
	cin>>s>>t;
	if(solve(s,t)) cout<<"true";
	else{
		cout<<"false";
	} 
	return 0;
}
