#include<iostream>
using namespace std;
int a[1000001];
bool in(int l,int r){
	for(int i=l;i<r;i++)
		if(a[i]>a[i+1]) return false;
	return true;
}
bool de(int l,int r){
	for(int i=l;i<r;i++)
		if(a[i]<a[i+1]) return false;
	return true;
}
bool inOrder(int l,int r){
	return in(l,r)||de(l,r); 
}
int main() {
	int n;
	cin>>n;
	if(n<=1){
		cout<<"No";
		return 0;
	} 
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		bool left=inOrder(1,i);
		bool right=inOrder(i+1,n);
		if(left&&right) {
			cout<<"Yes";
			return 0;
		} 
	} 
	cout<<"No";
	return 0;
}
