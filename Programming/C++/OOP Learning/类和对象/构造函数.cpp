#include<bits/stdc++.h>
using namespace std;
class Car{
private://不能在类外访问 
	string brand;
	int speed;
	
public:
	Car(){ //构造函数不能有返回值 
		brand="unknown";
		speed=0;
		cout<<"默认构造函数被构造\n"; 
	} 
/*	Car(string b,int s){
		brand=b;
		speed=s;
		cout<<"有参构造函数被调用\n";
	} 
*/
	
	//初始化列表来初始化成员变量	
	Car(string b,int s):brand(b),speed(s){
		cout<<"有参构造函数被调用\n";
	}

	
	void show(){
		cout<<"brand:"<<brand<<",speed"<<speed<<endl;
	}
	~Car(){
		cout<<"销毁汽车"<<brand<<endl;
	}
	
};
int main(){
	Car c1;
	c1.show();
	Car c2("byd",132);
	c2.show();
	cout<<"main函数已销毁\n";
	return 0;
}
