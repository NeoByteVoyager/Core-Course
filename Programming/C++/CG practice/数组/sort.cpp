#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	vector<int>a(101);
	for(int i=1;i<=100;i++) cin>>a[i];
	sort(a.begin()+1,a.end(),greater<int>());
	for(int i=1;i<=100;i++){
		cout<<a[i];
		if(i<100) cout<<" ";
	}
	return 0;
}
