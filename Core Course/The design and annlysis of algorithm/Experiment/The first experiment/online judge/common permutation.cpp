#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;
int cnta[26],cntb[26];
string find_longestx(string a,string b){
	memset(cnta,0,sizeof(cnta));
	memset(cntb,0,sizeof(cntb));
	for(int i=0;i<(int)a.size();i++){
		if(isalpha(a[i]))cnta[a[i]-'a']++;
	}
		
	for(int i=0;i<(int)b.size();i++){
		if(isalpha(b[i]))cntb[b[i]-'a']++;
	}
	string res;
	for(int i=0;i<26;i++){
		int m=min(cnta[i],cntb[i]);
		if(m){
			for(int j=0;j<m;j++)res+=char('a'+i);
		}
	}
	return res;
}
int main(){
	string a,b;
	while(getline(cin, a) && getline(cin, b)){
		string res=find_longestx(a,b);
		cout<<res<<"\n";
	}
	return 0;
} 
