#include<bits/stdc++.h>
using namespace std;
class Retangle{
	int width,length;
	public:
		Retangle(int w=1,int l=1):width(w),length(l){};
		int area() const{
			return width*length;
		}
		bool isSquare() const{
			return width==length;
		}
		
};
int main(){
	Retangle r(2,3);
	cout<<r.area();
	return 0;
} 
