#include<bits/stdc++.h>
using namespace std;
int main(){
	string a;
	string b;
	cin>>a>>b;
	int r1=a.size()-1,r2=b.size()-1;
	while(a[r1]==b[r2]){
		r1--,r2--;
	}
	cout<<r1+r2+2;
	return 0;
} 
