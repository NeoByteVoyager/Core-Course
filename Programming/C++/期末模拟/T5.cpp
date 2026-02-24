#include<bits/stdc++.h>
using namespace std;
bool solve(string t,string tmp){
	unordered_map<char,int>mp;
	for(char c:tmp) mp[c]++;
	for(char c:t){
		if(--mp[c]<0) return false;
	} 
	return true;
}
string f1(string t,string s){
	string res="";
	int n=s.size();
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			string tmp=s.substr(i,j-i+1);
			if(solve(t,tmp)){
				if(res==""||j-i+1<res.size()) {
					res=tmp;
				}
			} 
		} 
	}
	return res;
}
struct T{
	int cnt;
	char c;
};
string f2(string s){
	vector<T>t(26);
	for(char c:s){
		t[c-'a'].cnt++;
		t[c-'a'].c=c;
	}
	sort(t.begin(),t.end(),[](T&x,T&y){
		if(x.cnt!=y.cnt) return x.cnt>y.cnt;
		return x.c<y.c; 
	});
	string res;
	for(int i=0;i<26;i++){
		if(t[i].cnt!=0) {
			for(int j=0;j<t[i].cnt;j++) res+=t[i].c;
		}
		else break;
	}
	return res;
}
int main(){
	int n;
	cin>>n;
	while(n--){
		string t,s;
		cin>>t>>s;
		string res=f1(t,s);
		if(res!=""){
			cout<<res<<endl;
		}
		else {
			cout<<f2(s)<<endl;
		}
	}
	return 0;
}
