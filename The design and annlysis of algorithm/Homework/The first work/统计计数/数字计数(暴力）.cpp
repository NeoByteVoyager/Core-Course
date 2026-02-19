#include<bits/stdc++.h>
using namespace std;
int cnt[10]={0};
void Count(int i){
	while(i>0){
		cnt[i%10]++;
		i/=10;
	}
}
int main(){
	int l,r;
	cin>>l>>r;
	for(int i=l;i<=r;i++){
		Count(i);	
	}
	for(int i=0;i<10;i++) cout<<cnt[i]<<" ";
	return 0;
} 
