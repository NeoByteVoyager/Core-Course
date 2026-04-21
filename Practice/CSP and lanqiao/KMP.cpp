#include<bits/stdc++.h>
using namespace std;
int kmp(const string &s,const string &t){
	//处理next表
	int res=-1;
	int n=s.size(),m=t.size();
	vector<int>next(m,-1);
	for(int i=1;i<m;i++){
		int j=next[i-1];
		while(t[j+1]!=t[i]&&j!=-1){
			j=next[j];
		} 
		if(t[j+1]==t[i]) j++;
		next[i]=j;
		cout<<next[i]<<" ";
	} 
	
	//匹配
	int i=0,j=0;
	while(i<n&&j<m){
		if(s[i]==t[j]){	//当前能匹配 
			i++,j++;
			res=max(res,j);  
		}
		else if(j!=0){	//如果不是第一个字符，也就是说问题不出在s 
			j=next[j-1]+1;
		}
		else i++;		//问题出在s
	} 
	return res;
}
int main(){
	string s,t;
	cin>>s>>t;
	int res=kmp(s,t);
	cout<<res;
	return 0;
} 
