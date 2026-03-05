#include<bits/stdc++.h>
using namespace std;
class Student{
	string name;
	int id;
	static int total;
	public:
		Student(string n="",int i=0):name(n),id(i){
			total++;
		};
		static int getToal(){
			return total;
		}
		~Student(){
			total--;
		}
		void print()const{
			cout<<name<<" "<<id<<endl;
		}
};
int Student::total=0;
int main(){
	Student s("John",2024);
	s.print();
	Student *s1=new Student(); 
	s1->print(); 
	cout<<Student::getToal(); 
	delete s1; 
	return 0;
} 
