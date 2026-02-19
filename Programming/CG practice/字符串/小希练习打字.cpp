#include<bits/stdc++.h>
using namespace std;
char r[]={'y','u','i','o','p','h','j','k','l','n','m'};
bool isRight(char c){
	c=tolower(c);
	for(char t:r){
		if(c==t) return true;
	}
	return false;
}
int main(){
	int T;
	cin>>T;
	vector<pair<string,int>>pr;
	int res=0;
	while(T--){
		string s;
		cin>>s; 
//		//转换为小写
//		for(char &c:s){
//			c=tolower(c);
//		} 
		//检查是否练习过 
		bool pre=false;
		for(int i=0;i<pr.size();i++){
			if(pr[i].first==s){
				pre=true;
				res+=pr[i].second/2;
				break;	
			}
		}
		if(pre) continue;
		//还没有练习过 
		int last,ret=0;
		//记录第一个字母 
		ret+=2;
		last=isRight(s[0])?1:0;
		for(int i=1;i<s.size();i++){
			int now=isRight(s[i])?1:0;
			if(now==last) ret+=4;
			else ret+=2;
			last=now; 
		}
		res+=ret;
		pr.push_back({s,ret});
//		cout<<ret<<endl; 
	}
	cout<<res;
	return 0;
} 
