#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7;
bool is_prime[maxn+5];
void sliver(){
	// 初始化都为质数 
	for(int i=2;i<=maxn;i++) is_prime[i]=true;
	// 开始筛选
	for(int i=2;i*i<=maxn;i++){
		if(is_prime[i]){
			for(int j=i*i;j<=maxn;j+=i) is_prime[j]=false;
		}
	} 
}
int main(){
	sliver();
	for(int i=0;i<100;i++){
		if(is_prime[i]) cout<<i<<endl;
	}	
	return 0;
} 
