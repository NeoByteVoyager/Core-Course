#include<bits/stdc++.h>
using namespace std;
struct Person{
	int K,I,E;
	int tot;
};
int main(){
	int n;
	cin>>n;
	vector<Person>a(n);
	for(int m=0;m<n;m++) {
		cin>>a[m].K;
	}
	for(int m=0;m<n;m++) {
		cin>>a[m].I; 
	}
	for(int m=0;m<n;m++) {
		cin>>a[m].E;
	}
	
//	sort(a.begin(),a.end(),[](Person&x,Person&y){
//		return x.K<y.K;
//	});
	int res=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i].K<a[j].K&&a[i].I<a[j].I&&a[i].E<a[j].E){
				res++;
				break;
			}
		}
	}
	cout<<res;
	return 0;
} 
