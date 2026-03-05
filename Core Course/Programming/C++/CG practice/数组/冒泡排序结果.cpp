#include<iostream>
using namespace std;
int a[101];
int n,m;
void bubbleSort(){
	if(m==0) return ;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n-i;j++){
			if(a[j]>a[j+1]) swap(a[j],a[j+1]);
		}
	} 
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	bubbleSort();
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	return 0;
} 
