#include<bits/stdc++.h>
using namespace std;
class Counter{
	private:
		int val;
	public:
		Counter(int v=0):val(v){};
		Counter& operator++() {
			val++;
			return *this;
		}
		const Counter operator++(int ){
			Counter temp=*this;
			++(*this);
			return temp; 
		}
		Counter &operator=(const Counter&c){
			val=c.val;
			return *this;
		} 
	friend ostream& operator<<(ostream&os,const Counter &c);	
};
ostream& operator<<(ostream&os,const Counter&c){
	os<<c.val<<endl;
	return os;
} 
int main(){
	Counter c;
	cout<<c;
	c++;
	cout<<c;
	++(++c);
	cout<<c;
	Counter d=c++;
	cout<<d;
	cout<<c; 
	Counter e,f;
	f=e=c;
	cout<<e<<f;
	return 0;
} 
