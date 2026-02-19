#include<bits/stdc++.h>
using namespace std;
int solve(int t){
	int x=0;
	for(int i=1;i<=t/2;i++){
		if(t%i==0) x+=i;
	}
	int y=0;
	for(int i=1;i<=x/2;i++){
		if(x%i==0) y+=i;
	}
	if(y==t) return x;
	else return -1;
}
int main(){
	int n;
	cin>>n;
	int i=n;
	while(true){
		int t=solve(i);
		if(t!=-1) {
			cout<<i<<" "<<t;
			break;
		}
		
		i++; 
	}
	
	return 0;
} 
