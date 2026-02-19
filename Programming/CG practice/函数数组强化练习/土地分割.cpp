#include<iostream>
using namespace std;
int f(int n,int m){
	if(n==m)
		return n;
	else if(n>m)
		return f(m,n-m);
	else return f(m-n,n);
}
int main(){
	int n,m;
	cin>>n>>m;
	int l=f(n,m);
	int cnt=n/l*(m/l);
	cout<<cnt<<" "<<l; 
	return 0;
} 
