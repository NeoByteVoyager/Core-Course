#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int mod=1e9+7;
const int P=131;
const int MAXN=100005;
ULL p[MAXN];
ULL h[MAXN];
void initp(){
	p[0]=1;
	for(int i=1;i<MAXN;i++) p[i]=p[i-1]*P;
}
void inith(string &s){
	h[0]=0;
	for(int i=1;i<=s.size();i++){
		h[i]=h[i-1]*P+s[i-1];
	}
}
ULL gethash(int L,int R){
	return h[R]-h[L-1]*p[R-L+1];
}
struct Hash{
	ULL hash_val;
	int id;
};
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	
	initp();
	
	vector<Hash>a;
	
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		//初始化哈希前缀 
		inith(s);
		//得到每一个哈希值 
		for(int j=1;j<=s.size()-k+1;j++){ //长度为 k 
			a.push_back({gethash(j,j+k-1),i}) ;
		}	
	} 
	//哈希值相同的在一起的 
	sort(a.begin(),a.end(),[](auto x,auto y){
		return x.hash_val<y.hash_val;
	});
	
	long long res=0; 
	
	int sz=a.size();
	int i=0;
	while(i<sz){
		ULL val=a[i].hash_val;
		int cnt[n]{}; //统计该哈希值在每个生物中出现的次数 
		while(i<sz&&a[i].hash_val==val){
			cnt[a[i].id]++;
			i++;
		} 
		//利用位枚举 
		for(int mask=0;mask<(1<<n);mask++){
			if(__builtin_popcount(mask)==m){ //枚举到刚好m个生物 
				long long ways=1;
				for(int bit=0;bit<n;bit++){
					if((mask>>bit)&1) ways=(ways*cnt[bit])%mod; 
				}
				res=(res+ways)%mod;
			}
		}
		
	} 
	cout<<res;
	return 0;
} 
