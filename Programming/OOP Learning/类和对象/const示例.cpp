#include<bits/stdc++.h>
using namespace std;
class Complex{
private:
	double real,imag;
public:
	Complex(double r=0.0,double i=0.0):real(r),imag(i){
		cout<<"有参构造\n";
	}

	Complex operator+(const  Complex &c) const{
		return Complex(real+c.real,imag+c.imag);
	}
	void display()const {
		cout<<real<<"+"<<imag<<"i"<<endl;
	}
	//单目操作符
	Complex operator-()const {
		return Complex(-real,-imag);
	} 
	Complex operator++(){
		this->real+=1;
		this->imag+=1;
		return *this;
	}
};
int main(){
	Complex a(2.0,3.0);
	a.display();
	Complex d=-a;
	d.display();
	Complex b=a+33.0;
	b.display();
	++b;
	b.display();
	return 0; 
} 
