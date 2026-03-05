#include<iostream>
using namespace std;
int a[100001];
int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int t=0,cnt=0;
	for(int i=1;i<n;i++){
		if(a[i+1]==a[i]) continue;
		else if(a[i+1]>a[i]){
			if(t==-1){
				t=1;
				cnt++;
			}
			else if(t==0){
				t=1;
			}
			else continue;
		}
		else{
			if(t==-1)continue;
			else if(t==0){
				t=-1;
			}
			else{
				t=-1;
				cnt++;
			}
		}
	} 
	if(cnt<=2) cout<<"Yes";
	else cout<<"No";
	return 0;
}
