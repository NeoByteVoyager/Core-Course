#include<bits/stdc++.h>
using namespace std;
bool has(int i){
	while(i){
		if(i%10==7){
			return true;
		}
		i/=10;
	}
	return false;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		if(i%7==0){
			cout<<i<<"\n";
		}
		else if(has(i)){
			cout<<i<<"\n";
		}
		else continue;
	}
	return 0;
} 
