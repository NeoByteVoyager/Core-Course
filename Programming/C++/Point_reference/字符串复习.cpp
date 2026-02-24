#include<bits/stdc++.h>
using namespace std;
vector<string>spl(string s){
	vector<string>out;
	int pos=0,t;
	while((t=s.find(' ',pos))!=string::npos){
		out.push_back(s.substr(pos,t-pos));
		pos=t+1;
	}
	if (pos < s.size()) {
        out.push_back(s.substr(pos));
    }
	return out;
}
int main(){
	int n;
	cin>>n;
	cin.ignore();
	string s;
	while(n--){
		getline(cin,s);
		vector<string>t=spl(s);
		for(string i:t) cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}
