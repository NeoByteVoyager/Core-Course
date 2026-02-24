#include<bits/stdc++.h>
using namespace std;
void Reverse(string &s,int n){
	int l=0,r=n-1;
	while(l<=r){
		swap(s[l],s[r]);
		l++,r--;
	} 
} 
int main(){
	string s;
	getline(cin,s);
	int n=s.size();

	for(int i=1;i<=n;i++){
		if(n%i==0) 
			Reverse(s,i);
//		cout<<s<<endl;
	}
	
	cout<<s;
	return 0;
} 
