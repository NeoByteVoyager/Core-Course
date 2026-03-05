#include<bits/stdc++.h>
using namespace std;
class Animal{
public:
	string name;
	virtual void speak()=0;
	virtual ~Animal(){
		cout<<"Destory Animal\n";
	}
}; 
class Dog:public Animal{
public:
	void speak() override {
		cout<<"Dog speak\n";	
	} 
	~Dog(){
		cout<<"Destory Dog\n"; 
	}
};
int main(){
	Dog d;
	Animal *a=&d;
	a->speak();
	return 0;
}
