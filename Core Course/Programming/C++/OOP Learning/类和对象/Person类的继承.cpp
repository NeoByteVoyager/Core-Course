#include<bits/stdc++.h>
using namespace std;
class Person{
private:
	int id;
protected:
	int age;
public:
	string name;
public:
	Person(int i=0,int a=0,string n=""):id(i),age(a),name(n){}
	
	void showID(){
		cout<<"ID£º"<<id<<endl;
	} 
	
};
class Student:public Person{
	int score;
	
public:
	Student(int i=0,int a=0,string n="",int s=0):Person(i,a,n),score(s){}
	
	void showInfo(){
		cout<<id;
		cout<<"name:"<<name<<endl;
		cout<<"age:"<<age<<endl;
		cout<<"score:"<<score<<endl;
	}
	
};
int main(){
	Person p;
	p.showID();
	Student s;
//	cout<<s.age; 
//	s.showInfo();
} 
