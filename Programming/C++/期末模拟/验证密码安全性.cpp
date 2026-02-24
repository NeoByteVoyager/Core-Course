#include<bits/stdc++.h>
using namespace std;
int solve(string s){
	vector<bool>up(26,false);	
	vector<bool>low(26,false);
	vector<bool>num(10,false);
	vector<bool>ch(2,false);
	vector<bool>ok(4,false);
	
	for(char c:s){
		if(c>='A'&&c<='Z'){
			if(up[c-'A']) return 0;
			else {
				ok[0]=true;
				up[c-'A']=true;
			}
		} 
		else if(c>='a'&&c<='z'){
			if(low[c-'a']) return 0;
			else{
				ok[1]=true;
				low[c-'a']=true;
			}
		}
		else if(c>='0'&&c<='9'){
			if(num[c-'0']) return 0;
			else{
				ok[2]=true;
				num[c-'0']=true; 
			}
		}
		else if(c=='_'){
			if(ch[0]) return 0;
			else{
				ch[0]=true;
				ok[3]=true;
			}
		}
		else if(c=='@'){
			if(ch[1]) return 0;
			else{
				ch[1]=true;
				ok[3]=true;
			}
		}
		else {
			return 0;
		}
	}
	int cnt =0;
	for(int i=0;i<4;i++) cnt+=ok[i];
	int n=s.size();
	if(n>=12) {
		if(cnt==4) return 3;
		else return 0;
	}
	else if(n>=8) {
		if(cnt ==3) return 2;
		else return 0;
	}
	else if(n>=6){
		if(cnt==2) return 1;
		else return 0;
	}
	else return 0;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		cout<<solve(s)<<endl;
	}
	
	return 0;
} 
