#include<fstream>
#include<iostream> 
using namespace std;
typedef long long ll;

ll getNum(int n){
	ll res=1;
	for(int i=1;i<=n/2;i++)
		res+=getNum(i);
	return res;
}

int main(){
	int n;
//	ifstream fin("input.txt");
	cin>>n;
	ll res=getNum(n);
	cout<<res;
	return 0;
} 
