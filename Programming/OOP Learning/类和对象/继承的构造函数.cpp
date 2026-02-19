#include<bits/stdc++.h>
using namespace std;
class Base{
	int x;
	public:
		Base(int x){
			cout<<"调用Base无参构造函数\n";
		}	
		~Base(){
			cout<<"~Base()\n"; //析构与构造相反 
		} 
};
class Derived :public Base{
	int y;
	public:
//	1.如果Base 类内有默认构造函数，在派生类内可以不用声明base的构造 
//	2.如果Base 类内只有有参构造函数,在派生类内必须声明base的构造 
		Derived():Base(1){ 
			cout<<"调用Derived无参构造函数\n";
		}
		~Derived(){
			cout<<"~Derived()\n";
		}

};
int main(){
	Derived d;
	return 0;
} 
