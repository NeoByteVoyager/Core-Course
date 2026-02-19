#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int cnt,n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x%4==0||x%7==0) cnt+=x;
	} 
	cout<<cnt;
	return 0;
}
