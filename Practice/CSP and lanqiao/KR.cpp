#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int MAXN=1e4+5;
const int P=131;
ULL p[MAXN],h[MAXN];
void init(string haystack){
	h[0]=0;
	p[0]=1;//p的0次方是1 
	for(int i=1;i<=haystack.size();i++){
		p[i]=p[i-1]*P;
		h[i]=h[i-1]*P+haystack[i-1];// 这里的i-1,字符串下标从0开始 
	}
} 
ULL gethash(int L,int R){
	return h[R]-h[L-1]*p[R-L+1];// 十进制1234得到34 ：1234-12*10^2 
}
int strStr(string haystack, string needle) {
    init(haystack);
    int n=haystack.size(),m=needle.size();
	
	//算出子串的哈希值    
	ULL t=0;
	for(int i=0;i<m;i++) t=t*P+needle[i];
    //遍历主串的每一个子串比对 
    for(int i=1;i<=n-m+1;i++){
    	ULL s=gethash(i,i+m-1);
		if(s!=t) continue;
		else{
			int j=0;
			while(j<m) {
				if(haystack[i-1+j]==needle[j]) j++; //注意下标 
				else break;
			}
			if(j==m) return i-1; //注意下标 
		} 
	}
	return -1;
}
int main(){
	string s,p;
	cin>>s>>p;
	cout<<strStr(s,p);		
	return 0;
} 
