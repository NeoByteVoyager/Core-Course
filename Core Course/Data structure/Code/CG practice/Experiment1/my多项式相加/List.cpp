#include<iostream>
#include "List.h"
using namespace std;

List::List(){
	len=0;
}
bool List::insert(int cof,int exp){
	Term t;
	t.exp=exp,t.cof=cof;
	data[len++]=t;
	return true;
}
int List::getLen() const{
	return len;
} 
Term List::getTerm(int index){
	return data[index];
}
 
