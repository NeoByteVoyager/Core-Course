#include<iostream>
using namespace std;
int a[101];
int n;
void insertSort(){
	for(int i=2;i<=n;i++){
		int t=a[i];
		int j;
		for(j=i-1;j>=1;j--){
			if(a[j]<t) a[j+1]=a[j]; //找到a[i]的位置，把比a[i]小的往后移动 
			else break;
		}	
		a[j+1]=t;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	insertSort();
	for(int i=1;i<=n;i++) {
		cout<<a[i];
		if(i<n) cout<<" ";
	}
	return 0;
} 
