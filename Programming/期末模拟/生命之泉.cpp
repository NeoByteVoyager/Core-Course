#include<bits/stdc++.h>
using namespace std;
bool solve(string t,string sub){
	unordered_map<char,int>mp;
	for(char c:sub) mp[c]++;
	for(char c:t){
		if(--mp[c]<0) return false;
	}
	return true;
}
string f1(string t,string s){
	int n=s.size();
	string res="";
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			string sub=s.substr(i,j-i+1);
			if(solve(t,sub)){
				if(res==""||j-i+1<res.size())res=sub;
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
	vector<T>a(26);
	for(int i=0;i<26;i++){
		a[i].cnt=0;
		a[i].c='a'+i;
	}
	for(char c:s) a[c-'a'].cnt++;
	sort(a.begin(),a.end(),[](T&x,T&y){
		if(x.cnt!=y.cnt) return x.cnt>y.cnt;
		return x.c<y.c;
	});
	string res="";
	for(int i=0;i<26;i++) {
		if(a[i].cnt){
			for(int j=0;j<a[i].cnt;j++) res+=a[i].c; 
		}
		else break;
	}
	return res;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string t,s;
		cin>>t>>s;
		string tmp=f1(t,s); 
		if(tmp!="") {
			cout<<tmp<<endl;
		}
		else{
			cout<<f2(s)<<endl;
		}
	}
	return 0;
}
