#include<bits/stdc++.h>
using namespace std;
bool isleft(char c){
	return c=='('||c=='{'||c=='[';
}
bool isright(char c){
	return c=='}'||c==']'||c==')';
}
bool match(char c,char d){
	if(c=='{'&&d=='}')return true;
	else if(c=='['&&d==']') return true;
	else if(c=='('&&d==')') return true;
	else return false;
}
int main(){
	string s;
	getline(cin,s);
	stack<char>st;
	for(char c:s){
		if(isleft(c)) {
			st.push(c);
		}
		else if(isright(c)){
			if(st.empty()){
				cout<<0;
				return 0;
			} 
			char d=st.top();
			st.pop();
			if(!match(d,c)){
				cout<<0;
				return 0;
			}
		}
	}
	if(!st.empty()){
		cout<<0;
		return 0;
	} 
	cout<<1;
	return 0;
}
