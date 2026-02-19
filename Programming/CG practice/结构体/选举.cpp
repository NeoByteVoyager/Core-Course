#include<bits/stdc++.h>
using namespace std;
struct Person{
	int score[101];
	int cnt;
}; 
int main(){
	int n,m;
	cin>>n>>m; 
	vector<Person>a(n);
	for(int i=0;i<m;i++){
		int t=-1;
		int id;
		for(int j=0;j<n;j++){
			cin>>a[j].score[i];
			if(a[j].score[i]>t){
				id=j;
				t=a[j].score[i];	
			}
		}
		a[id].cnt++;
	}
	int t=-1;
	int id;
	for(int i=0;i<n;i++){
		if(a[i].cnt>t){
			t=a[i].cnt;
			id=i+1;	
		}
	}
	cout<<id;
	return 0;
}
