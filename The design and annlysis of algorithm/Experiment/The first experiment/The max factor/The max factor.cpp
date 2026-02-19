#include<bits/stdc++.h>
using namespace std;
vector<int>primes;

void Getprime(int maxn){//线性筛筛出sqrt(maxn)范围内的质数 
	int n=sqrt(maxn);
	vector<bool>isprime(n+1,true);
	for(int i=2;i<=n;i++){
		if(isprime[i]) primes.push_back(i);
		for(int p:primes){
			if(p*i>n) break;
			isprime[p*i]=false;
			if(i%p==0)break;
		}
	}
}
pair<int,long long> getMaxfactor(int l,int r){//用质数筛取l~r的质因数 
	int maxfactor_idx=1;
	long long max_factor=1;
	int len=r-l+1;
	vector<int>a(len);
	vector<long long>res(len,1);
	for(int i=0;i<len;i++) a[i]=l+i;
	for(int i=0;i<(int)primes.size();i++){
		int p=primes[i];
		if(p>r) break;
		int s=(l-1+p)/p*p;
		for(int j=s;j<=r;j+=p){
			int idx=j-l;
			int cnt=0;
			while(a[idx]%p==0){
				cnt++;
				a[idx]/=p;
			}
			if(cnt) res[idx]*=cnt+1;
		}
	}
	
	for(int i=0;i<len;i++){
		if(a[i]>1) res[i]*=2; 
		if(res[i]>max_factor)max_factor=res[i],maxfactor_idx=i+l;
	}
	
	return {maxfactor_idx,max_factor};
} 
int main(){
	freopen("3.txt","r",stdin);
	int l,r;
	cin>>l>>r;
	clock_t start = clock();
	if(l==1&&r==1){
		cout<<"Between "<<l<<" and "<<r<<", "<<1<<" has a maximum of "<<1<<" divisors.\n" ;
		return 0;
	}
	Getprime(r);
	auto it=getMaxfactor(l,r);
	clock_t end = clock();
	cout<<"Between "<<l<<" and "<<r<<", "<<it.first<<" has a maximum of "<<it.second<<" divisors.\n" ;
	cout << fixed << setprecision(12)
         << "运行时间: " << double(end - start) / CLOCKS_PER_SEC << " 秒" << endl;
	return 0;
} 
