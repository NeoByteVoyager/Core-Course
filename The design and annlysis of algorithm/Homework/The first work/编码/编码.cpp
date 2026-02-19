#include<bits/stdc++.h>
using namespace std;
long long c(int n,int m){//组合数计算 
	long long res=1;
	for(int i=1;i<=m;i++){
		res=1ll*res*(n-i+1)/i;
	}
	return res;
}
long long to_num(string s){
	int len=s.size();
	long long res=0;
	//比该字典序小的字典序个数 
	for(int i=1;i<len;i++){
		if(s[i]<=s[i-1]) return 0;
		res+=c(26,i);	
	}
	//与该字典序相等长度但小于该字典序的字典序个数 
	for(int i=0;i<len;i++){
		char j=i==0?'a':s[i-1]+1;
		while(j<s[i]){
			res+=c('z'-j,len-i-1);
			j++;
		}
	}
	return ++res;
}
int main(){
	freopen("word100000.txt","r",stdin);
	freopen("res.txt","w",stdout);
	int k;
	cin>>k;
	string s;
	
	clock_t start=clock();
	for(int i=0;i<k;i++){
		cin>>s;
		cout<<to_num(s)<<"\n";
	}
	clock_t end=clock();
	
	fclose(stdin);
	fclose(stdout);
	
   	freopen("CON", "w", stdout); // 恢复控制台输出
   	cout<<"data size:"<<100000<<endl;
	cout<<fixed<<setprecision(12)
		<<"运行时间："<<double(end-start)/CLOCKS_PER_SEC<<endl; 
	return 0;
} 
