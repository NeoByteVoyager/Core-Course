#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y;
	for(int i=1;i<=6;i++){
		string s;
		cin>>s;
		for(int j=0;j<3;j++){
			if(s[j]=='*') x=i,y=j+1;
		} 
	}

	cout<<x<<" "<<y;
	return 0;
	
} 
