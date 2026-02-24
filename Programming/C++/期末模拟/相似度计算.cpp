#include<bits/stdc++.h>
using namespace std;
void tolow(string &s){
	for(char &c:s) c=tolower(c);
}
void f(int n,unordered_map<string,int>&mp){
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		tolow(s);
		if(mp.find(s)==mp.end()){
			mp[s]=1;
		}
	}
} 
int main(){
	int n,m;
	cin>>n>>m;
	unordered_map<string,int>mp1;
	unordered_map<string,int>mp2;
	f(n,mp1);
	f(m,mp2);
	int s1=mp1.size(),s2=mp2.size(); 
	int t;
	for(auto tmp:mp1){
		string s=tmp.first;
		if(mp2.find(s)!=mp2.end()) t++;
	}
	cout<<t<<endl;
	cout<<s1+s2-t<<endl;
	return 0;
} 
