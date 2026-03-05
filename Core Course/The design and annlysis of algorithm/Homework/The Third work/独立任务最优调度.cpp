#include<bits/stdc++.h>
using namespace std;
struct T{
	int a,b;
};
int n;
bool cmp1(T x,T y){
	return x.a<y.a;
}
bool cmp2(T x,T y){
	return x.b>y.b;
}
vector<T> John(vector<T>&t){
	vector<T>s1,s2;//a<b,a>b;
	for(int i=1;i<=n;i++){
		if(t[i].a<t[i].b) s1.push_back({t[i].a,t[i].b});
		else s2.push_back({t[i].a,t[i].b});
	}
	sort(s1.begin(),s1.end(),cmp1);
	sort(s2.begin(),s2.end(),cmp2);
	s1.insert(s1.end(),s2.begin(),s2.end());
	return s1;
}
int main(){
	cin>>n;
	
	vector<T>t(n+1);
	
	for(int i=1;i<=n;i++) cin>>t[i].a;
	for(int j=1;j<=n;j++) cin>>t[j].b;
	//进行John不等式排序 
	vector<T>s=John(t);
	for(auto t:s) cout<<t.a<<" "<<t .b<<endl; 
	
//	int wait=0;
//	int res=0;
//	for(int i=0;i<n;i++){
//		res+=s[i].a;
//		wait=max(0,wait-s[i].a)+s[i].b;
//	} 
//	res+=wait;
//	cout<<res;
	
	return 0;
} 
/*
6
2 5 7 10 5 2 
3 8 4 11 3 4
*/
