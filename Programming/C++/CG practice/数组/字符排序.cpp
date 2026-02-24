#include<iostream> 
using namespace std;
char s[61];
int n;
void selectSort(){
	for(int i=1;i<n;i++){
		char t=s[i],m=i;
		for(int j=i+1;j<=n;j++){
			if(s[j]>t) t=s[j],m=j;
		}
		swap(s[i],s[m]);
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	selectSort();
	for(int i=1;i<=n;i++)
		cout<<s[i]; 
	return 0;
}
