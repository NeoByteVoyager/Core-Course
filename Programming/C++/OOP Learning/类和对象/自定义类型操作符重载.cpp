#include<bits/stdc++.h>
using namespace std;
class A{
	int x,y;
	public:
		A(int a=1,int b=0):x(a),y(b){}
		operator int(){
			return x+y;
		}
};
int main(){
 	int i=0;
 	A a;
 	cout<<a+i<<endl; 
 	cout<<i+a<<endl;
	return 0;
 }
