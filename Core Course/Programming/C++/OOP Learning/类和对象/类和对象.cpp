#include<bits/stdc++.h>
using namespace std;
class Car{
public:
	string brand;
	int speed;
	
	void introduce(){
		cout<<brand<<"以"<<speed<<"的速度在公路上运行\n"; 
	}
};
int main(){
	Car c1;
	c1.brand="xiaomi";
	c1.speed=123;
	c1.introduce();
	return 0;
}
