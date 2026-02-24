#include<bits/stdc++.h>
using namespace std;
string f(string s){
	int i=0;
	while(s[i]=='0'){
		i++;
		if(i>1)break;
	}
	if(i>1) return "0";
	else return s.substr(i);
}
int main(){
	int n;
	cin>>n;
	vector<int>a(n+1);
	string s;
	for(int i=1;i<=n;i++) {
		cin>>s;
		string s1=s.substr(0,2);
		string s2=s.substr(3);
		int h=0,m=0;
		if(s1=="00"&&s2=="00"){
			h=23,m=60;
			a[i]=h*60+m;
			continue;
		}
		s1=f(s1),s2=f(s2);
		h=stoi(s1),m=stoi(s2);
		a[i]=h*60+m;
	}
	int m=INT_MAX;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			m=min(m,abs(a[i]-a[j]));
		}
	}
	cout<<m;
	return 0;
}
