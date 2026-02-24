#include<fstream>
#include<iostream>
using namespace std;
void readfile(){
  ifstream fin("D:\\Core Course\\Programming\\OOP Learning\\File solution\\test.txt");
  int a,b;
  string t;
  fin>>a>>b>>t;
  cout<<a<<" "<<b<<" "<<t;
  fin.close();
}


int main(){
	readfile(); 
	return 0;
}
