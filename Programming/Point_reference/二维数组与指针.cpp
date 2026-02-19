#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[2][3];
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			a[i][j]=i+j;
		}
	}
	int (*p)[3]=a;
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			cout<<*(*(p+i)+j)<<" ";
		}
		cout<<endl;
	}
	 
	return 0;
}
