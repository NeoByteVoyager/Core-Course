#include<bits/stdc++.h>
using namespace std;
string res=0;
int dfs(int i,string s,int lower){
	if(i==s.size()) {
		res++;
		return ;
	}
	
}  
int main(){
	string s;
	cin>>s;
	dfs(0,s,9);
	cout<<res-1; //¼õÈ¥0 
	return 0;
} 
