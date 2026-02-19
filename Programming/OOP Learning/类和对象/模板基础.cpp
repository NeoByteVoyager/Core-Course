#include<bits/stdc++.h>
using namespace std;


template <typename T>
T add(T a,T b){ 
	cout<<"模板函数\n";
	return a+b;
}
int add(int a,int b){
	cout<<"普通函数\n";
	return a+b;
}
int main() {
	int a=1,b=2;
	cout<<add(a,b)<<endl;
	int c=2.0,d=3.0;
	cout<<add<double>(c,d)<<endl;
	return 0;
}
