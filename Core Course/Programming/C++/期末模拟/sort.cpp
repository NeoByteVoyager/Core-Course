#include<bits/stdc++.h>
using namespace std;
void mysort(int a[],int n){
	for(int i=0;i<n-1;i++){
		int minIndex=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[minIndex]){
				minIndex=j;
			}
		} 
		swap(a[i],a[minIndex]); 
	} 
}
int main(){
	int a[]={3,8,5,6};
	mysort(a,4);
	for(int i=0;i<4;i++) cout<<a[i]<<" ";
	return 0; 
}
