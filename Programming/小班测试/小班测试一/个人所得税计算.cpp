#include<bits/stdc++.h>
using namespace std;
int main(){
	int sum,item;
	cin>>sum>>item;
	int temp=(sum-5000-item);
	float need;
	if(temp<=3000){
		need=temp*0.03;
	}
	else if(temp<=12000){
		need=temp*0.1-210;
	}
	else if(temp<=25000){
		need=temp*0.2-1410;
	}
	else if(temp<=35000){
		need=temp*0.25-2660;
	}
	else if(temp<=55000){
		need=temp*0.3-4410;
	}
	else if(temp<=80000){
		need=temp*0.35-7160;
	}
	else{
		need=temp*0.45-15160;
	} 
	
	if(need>=0){
		cout<<need;
	}
	else cout<<0;
	return 0;
} 
