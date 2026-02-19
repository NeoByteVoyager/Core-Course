#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	stack<char>st;
	for(char c:s){
		if(c=='*'){
			if(!st.empty()) st.pop();
		}
		else{
			st.push(c);
		}
	}
	string res;
	while(!st.empty()){
		res+=st.top();
		st.pop();
	}
	reverse(res.begin(),res.end());
	cout<<res;
	return 0;
} 
