#include<fstream>
using namespace std;
void writefile(){
  ofstream fout("D:\\Core Course\\Programming\\OOP Learning\\test.txt");
  fout<<"hello world";
  fout.close();
}

int main(){
	writefile(); 
	return 0;
}
