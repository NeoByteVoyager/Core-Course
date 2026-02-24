#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void output(string s,string t){
	ll fz=stoll(s);
	ll fm=stoll(t);
	int m=__gcd(fz,fm);
	fz/=m;
	fm/=m;
	cout<<fz<<"/"<<fm<<endl;
}
void solve0(string s){
	s=s.substr(2);
	int n=s.size();
	string t="1";
	for(int i=1;i<=n;i++){
		t+='0';
	}
	output(s,t);
} 
void solve1(string s){
	int n=s.size();
	s=s.substr(3,n-4);
	string t(n-4,'9');
	output(s,t);
}
void solve2(string s,size_t pos){
	int n=s.size();
	string s1=s.substr(2,pos-2);
	string s2=s.substr(pos+1,n-pos-2);
	string s3=s1+s2;
	int tmp=stoll(s3)-stoll(s1);
	s=to_string(tmp);
	string t((int)s2.size(),'9'); 
	for(int i=0;i<s1.size();i++) t+='0';
	output(s,t);
}
int main(){
	int n;
	cin>>n;
	string s;
	while(n--){
		cin>>s;
		size_t pos;
		if((pos=s.find('('))==string::npos){
			solve0(s);
		}
		else {
			if(pos==2){
				solve1(s);
			}
			else{
				solve2(s,pos);
			}
		}
	}
	return 0;
} 
