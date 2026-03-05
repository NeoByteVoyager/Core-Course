#include<iostream>
using namespace std;
int main(){
	int k,n,w;
	cin>>k>>n>>w;
	int need=k*w*(w+1)/2;
	if(need>n)
		cout<<need-n;
	else cout<<0;
	return 0; 
} 
