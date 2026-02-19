#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,d;
	cin>>n>>d;
	vector<int>a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int cnt=2;
	for(int i=0;i<n-1;i++){
		if(a[i+1]-a[i]==2*d) cnt+=1;
		else if(a[i+1]-a[i]>2*d) cnt+=2;
	}
	cout<<cnt;
	return 0;
} 
