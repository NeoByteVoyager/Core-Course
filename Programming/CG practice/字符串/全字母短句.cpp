#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	cin.ignore();
	while(T--){
		string s;
		getline(cin,s);
		vector<bool>used(26,false);
		for(char i:s) {
			if(isalpha(i)) 
				used[tolower(i)-'a']=true;
		}
		bool ok=true;
		for(int i=0;i<26;i++){
			if(!used[i]){
				ok=false;
				break;
			}
		}
		if(ok){
			cout<<"Yes"<<endl;
		} 
		else {
			cout<<"No ";
			for(int i=0;i<26;i++){
				if(!used[i]){
					char c='A'+i;
					cout<<c<<" ";
				}
			}
			cout<<endl;
		}
	}
	return 0;
} 
