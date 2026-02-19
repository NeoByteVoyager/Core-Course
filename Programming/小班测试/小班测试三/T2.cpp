#include<bits/stdc++.h>
using namespace std;
int a[100][100];
void f(int i,int j,int s,int level){
	if(level<=0){
		return ;
	}
	int k=s;
	for(int m=1;m<=level;m++){
		a[i][i+m-1]=k;
		k++;
	}
	for(int m=2;m<=level;m++){
		a[i+m-1][i+level-1]=k;
		k++;
	}
	for(int m=level-1;m>=1;m--){
		a[i+level-1][i+m-1]=k;
		k++;
	}
	for(int m=level-1;m>=2;m--){
		a[i+m-1][j]=k;
		k++;
	}
	f(i+1,j+1,k,level-2);
}
int main(){
	int n;
	cin>>n;
	f(1,1,1,n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" ";
		} 
		cout<<endl;
	}
	return 0;
} 
