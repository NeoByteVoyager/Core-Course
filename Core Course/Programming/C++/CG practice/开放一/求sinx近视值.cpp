#include<bits/stdc++.h>
using namespace std;
const long double pi=3.1415926535;
long double f(long double x){
	if(x>0){
		while(abs(x-2*pi)<abs(x)) x-=2*pi;
	}
	else if(x==0){
		return 0; 
	}
	else {
		while(abs(x+2*pi)<abs(x)) x+=2*pi;
	}
	long double res=0,t=1;
	int s=1;
	while(true){
		long double tmp=1; 
		for(int i=1;i<=s;i++){
			tmp*=x/(long double)i;
		}
		res+=tmp*t;
		if(fabsl(tmp)<0.5e-13L) break;   // ←只改这一行
		s+=2;
		t*=-1;
	}
	return res;
}
int main(){
	long double x;
	cin>>x;
	long double res=f(x);
	cout << fixed << setprecision(13) << res;
	return 0;
} 
