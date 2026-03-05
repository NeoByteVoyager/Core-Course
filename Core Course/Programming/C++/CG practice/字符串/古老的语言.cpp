#include<bits/stdc++.h>
using namespace std;
bool isYuan(char a){
	return a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='n';
}
int main(){
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n-1;i++){
		if(isYuan(s[i])) continue;
		else{
			if(isYuan(s[i+1])) continue;
			else{
				cout<<"NO\n";
				return 0;
			} 
		}
	} 
	//最后一个字母要是元音或者为n; 
	if(!isYuan(s[n-1])){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n"; 
	return 0;
}
