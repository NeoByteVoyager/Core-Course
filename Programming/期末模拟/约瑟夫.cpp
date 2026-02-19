#include<bits/stdc++.h>
using namespace std;
class Person{
	int id;
	Person *next;
public:
	Person(int i):id(i),next(nullptr){}
	Person* getNext(){
		return next;
	}
	void setNext(Person *p){
		next=p;
	}
	int getID(){
		return id;
	}
};
class circle{
	int inQueue;
	int out;
	Person *start;
public:
	circle(int n,int s,int k){
		inQueue=n;
		out=k;
		Person* prv,* head;
		for(int i=1;i<=n;i++){
			Person*cur=new Person(i);
			if(i==1){
				head=cur;
			}
			else{
				prv->setNext(cur);
			}
			if(i==s){
				start=cur;
			}
			prv=cur;
		}
		prv->setNext(head);
	}
	void show(){
		Person *head=start;  
		for(int i=0;i<=inQueue;i++){
			cout<<head->getID()<<" ";
			head=head->getNext();
		}
	} 
	
};

int main(){
	circle c(10,1,3);
	c.show();
	return 0;
}
