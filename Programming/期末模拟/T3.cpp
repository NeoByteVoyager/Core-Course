#include<bits/stdc++.h>
using namespace std;
int a[]={1,0,0,0,0,0,1,0,2,1};
struct T{
	int val;
	int cnt;
};
int f(int  t){
	if(t==0) return 1;
	int res=0;
	while(t){
		res+=a[t%10];
		t/=10;
	}
	return res;
}
int main(){
	int n;
	cin>>n;
	vector<T>t(n);
	for(int i=0;i<n;i++){
		cin>>t[i].val;
		t[i].cnt=f(t[i].val);
	}
	sort(t.begin(),t.end(),[](T&x,T&y){
		if(x.cnt!=y.cnt) return x.cnt<y.cnt;
		return x.val<y.val;
	});
	for(int i=0;i<n;i++){
		cout<<t[i].val<<" ";
	}
	return 0;
}
