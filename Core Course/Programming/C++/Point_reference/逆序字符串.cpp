 #include<iostream>
 #include<bits/stdc++.h>
using namespace std;
void f(char *a){
	char *p=a,*q=a+strlen(a)-1;
	while(p<=q){
		char t=*p;
		*p=*q;
		*q=t;
		p++;
		q--;
	}
}
int main(){
	char a[]="hello";
	f(a);
	cout<<a;
	return 0;
} 
