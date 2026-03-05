#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a1[]={0,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
int a2[]={0,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
int a3[]={0,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
int a[25];
int n;
bool f(int b[]){
	for(int i=1;i<=24-n+1;i++){
		bool ok=true;
		for(int j=1;j<=n;j++){
			if(a[j]!=b[i+j-1]){
				ok=false;
				break;
			} 
		}
		if(ok)return true;
	}
	return false;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool ok=f(a1)||f(a2)||f(a3);
	if(ok) cout<<"Yes";
	else cout<<"No";	
	return 0;
} 
