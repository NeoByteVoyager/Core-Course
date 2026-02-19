#include<bits/stdc++.h>
using namespace std;
class Date{
private:
	int year,month,day;
public:
	static int count;//类内声明 
	Date(int y=0,int m=0,int d=0){
		count++;
		year=y;
		month=m;
		day=d;
		cout<<"构造函数"<<endl; 
	}
	Date(const Date &t){
		month=t.month;
		year=t.year;
		day=t.day;
		cout<<"拷贝构造函数"<<endl; 
	}
	void show() {
		cout<<year<<" "<<month<<" "<<day<<endl;
	}
	~Date(){
		cout<<"析构函数"<<endl; 
		count--;
	}
};
int Date::count=0;//类外定义 
//对象成员 
class Person{
	string name;
}; 
int main(){
	//普通对象 
	Date d1(2025,11,27);

	d1.show();
	//对象的拷贝 
//	Date d2;
//	d2=d1;
//	d2.show();
	//对象指针 
	Date *p=&d1;
	d1.show();
	p->show();
	(*p).show();
	//对象数组 
	Date q[3]={Date(1,1,1),Date(2,2,2),Date()} ;
	q[2].show();
	//对象引用 
	Date &w=d1;
	w.show();
	cout<<d1.count;
	cout<<maxm; 
	return 0;
}
