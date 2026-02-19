#include<bits/stdc++.h>
using namespace std;
long long cnt1[10],cnt2[10];
long long pow(int n){
	long long res=1;
	for(int i=1;i<=n;i++) res*=10;
	return res;
}
void Count(long long n,long long cnt[]){
	//计算n的位数 
	string s=to_string(n);
	int len=(int)s.size();
	//统计每一位上各数字出现的个数
	for(int i=0;i<len;i++){
		int t=len-i-1;//该数字右边的位数 
		long long w=pow(t);//该位数字的权重 
		long long cur=n/w%10;//该位数字 
		long long high=n/w/10;//高位数字 
		long long low=n%w;//低位数字 
//		cout<<high<<" "<<cur<<" "<<low<<endl;
		for(int j=0;j<10;j++){
			if(j<cur){
				cnt[j]+=(high+1)*w;
			}
			else if(j==cur){
				cnt[j]+=high*w+low+1;
			}
			else{
				cnt[j]+=high*w;
			}
		}
		cnt[0]-=w;
	} 
}
int main(){
	freopen("input1.txt","r",stdin);
	long long l,r;
	cin>>l>>r;
	
	clock_t start=clock(); 
	Count(r,cnt1);
	if(l>1) Count(l-1,cnt2);//如果左边界不是1，要减去1~l-1的数字个数（本题不需要） 
	clock_t end=clock();
	
	for(int i=0;i<10;i++){
		cnt1[i]-=cnt2[i];
		cout<<cnt1[i]<<" ";
	}
	
	cout<<fixed<<setprecision(12)<<
		"运行时间："<<double(end-start)/CLOCKS_PER_SEC<<endl; 
	return 0;
} 
