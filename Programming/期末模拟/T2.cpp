#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int res=0;
	for(int i=1;i<=n;i++){
		if(n%i==0) res+=i;
	}
	cout<<res;
	return 0;
}
