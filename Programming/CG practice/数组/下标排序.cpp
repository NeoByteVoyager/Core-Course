#include<iostream>
using namespace std;
int a[101];
int n;
void bubbleSort(){
	for(int i=1;i<n;i++){
		bool flag=false;
		for(int j=1;j<=n-i;j++){
			if(a[j]<=a[j+1]) {
				swap(a[j],a[j+1]);
				flag=true; 
			}
		}
		if(!flag) return;
	}
}
int main(){
	cin>>n; 
	for(int i=1;i<=n;i++) cin>>a[i];
	bubbleSort();
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	return 0;
} 
