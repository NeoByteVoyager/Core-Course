#include<fstream>
#include<iostream> 
using namespace std;
typedef long long ll;
int memo[1001]; 

ll getNum(int n){
	if(memo[n])return memo[n];
	ll res=1;
	for(int i=1;i<=n/2;i++)
		res+=getNum(i);
	memo[n]=res;
	return res;
}

int main(){
	int n;
//	ifstream fin("input1.txt");
//	ofstream fout("res.txt");
	cin>>n;
	ll res=getNum(n);
	cout<<res;
	return 0;
} 
