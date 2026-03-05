#include<bits/stdc++.h>
using namespace std;
class Base {
    int* data;
public:
    Base(int v=0) { data = new int(v); cout << "Base构造 "; }
    
    // 问题：下面这个拷贝构造有什么问题？
    Base(const Base& other) { 
	data = new int;
	*data=*other.data; 
	cout << "Base拷贝 "; }
    
    ~Base() { delete data; cout << "~Base "; }
    Base&  operator=(const Base&other){
    	data=new int(*other.data);cout<<"Base=\n";
    	return *this;
    	
	}
};

class Derived : public Base {
	int derv; 
public:
    Derived(int v=0,int u=0) : Base(v),derv(u) { cout << "Derived构造 "; }
    Derived(const Derived&other):Base(other){
    	derv=other.derv;
    	cout<<"Derived拷贝 "; 
	} 
	Derived& operator=(const Derived&other){
		Base::operator=(other);
		derv=other.derv;cout<<"Derived=\n"; 
		return *this;
		
	} 
    ~Derived() { cout << "~Derived "; }
};

int main() {
    Derived d1(10,11);
    Derived d2;  // 问题：程序会出现什么问题？为什么？
    d2=d1;
}
