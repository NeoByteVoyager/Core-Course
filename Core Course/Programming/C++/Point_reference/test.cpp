#include<iostream>
using namespace std;
int main(){
/*	取整型变量的地址 
	int a;
	int *p=&a;
	cout<<*p;
	return 0;
	
*/	

/*	数组的地址既是首元素的地址 
	int a[]={0};
	int *p=a,*q=&a[0];
	cout<<p<<" "<<q;	
*/	

//	如何输出字符串的地址 
	char a[]="hello";
	char *p=a;
	//输出的是字符串首元素 
	cout<<*p<<endl;
	//输出字符串 
	cout<<p<<endl;
	//输出字符串地址 
	cout<<(void*)p<<endl;
	


	return 0;
} 
