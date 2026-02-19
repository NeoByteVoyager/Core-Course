#include<bits/stdc++.h>
using namespace std;
class Array{
	size_t n;
	int *data;
	public:
	Array(size_t t=0):n(t),data(new int[t]){};
	~Array(){
		delete []data;
	}
	void set(int idx,int val){
		if(idx>=n) {
			cout<<"Out of range"<<endl;
			return ;
		}
		data[idx]=val;
		return ;
	} 
	int get(int idx){
		if(idx>=n) {
			cout<<"Out of range"<<endl;
			return -1;
		}
		return data[idx];
	}
};
int main(){
	Array s(100);
	s.set(2,20);
	cout<<s.get(2);
	return 0;
} 
