#include<bits/stdc++.h>
using namespace std;
class A{
	private:
		int a;
	protected:
		int b;
		
	public:	
	int c;
	A(){
		cout<<"A constructed\n";
	} 

	
	virtual ~A(){
		cout<<"A destructed\n";
	}
};

class B:public A{
	
	
	
	public:
		
		B(){
			cout<<"B constructed\n";
		}
		
		
		~B(){
			cout<<"B destructed\n";
		}
};

int main(){
//	A a;
	B b;
	return 0;
} 
