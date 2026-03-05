#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	int x=1;
	const int *p=&x;//指向常量的指针,不能修改指针指向的值 
	int*const m=&x; //指针常量，m存的地址不能修改 
	const int y=2;
//	int *q=&y;//ERROR 变量指针不能指向常量,常量指针可以指向变量 
	const int *const t=&y;
	return 0;
} 
