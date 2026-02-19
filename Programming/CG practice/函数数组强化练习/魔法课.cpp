#include<bits/stdc++.h>
using namespace std;
bool isprime(int n){
//	if(n<2) return false; 
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
} 
int main(){
	int n,m;
	cin>>n>>m;
	int t=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int x;
			cin>>x;
			if(isprime(x)) t++;
		}
	}
	cout<<t;
	return 0;
	
} 
