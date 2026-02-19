#include<bits/stdc++.h>
using namespace std;
int a[]={1,0,0,0,0,0,1,0,2,1};
struct num{
	int val;
	int tot;
}; 
int fix(int x){
	int res=0;
	if(x==0) return a[0]; ///
	while(x){
		res+=a[x%10];
		x/=10;
	}
	return res;
}
bool cmp(num&x,num &y){
	if(x.tot!=y.tot)return x.tot<y.tot;
	return x.val<y.val;
}
int main(){
	int n;
	cin>>n;
	vector<num>t(n);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		t[i].val=x;
		t[i].tot=fix(x);
	} 
	sort(t.begin(),t.end(),cmp);
	for(int i=0;i<n;i++){
		cout<<t[i].val<<" ";
 
	}
	return 0;
} 
