#include<bits/stdc++.h>
using namespace std;
int main(){
	string a,b;
	cin>>a>>b;
	string res;
	for(char c:b){
		if(isalpha(c)) res+=tolower(c);
	}
	for(char c:a){
		if(isalpha(c)) res+=tolower(c);
	}
	cout<<res;
	return 0;
} 
