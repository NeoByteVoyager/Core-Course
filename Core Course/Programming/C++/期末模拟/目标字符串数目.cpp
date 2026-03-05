#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<string>nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	} 
	string tar=nums[n-1];
	int res=0;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			if(j==i) continue;
			string t=nums[i]+nums[j];
			res+=(t==tar)?1:0;
		}
	}
	cout<<res;
	return 0;
} 
