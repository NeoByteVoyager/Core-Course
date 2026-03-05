#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int x;
	cin>>x;
	int current_sum=x,max_sum=x;
	for(int i=1;i<n;i++){																								
		int x;
		cin>>x;
		current_sum=max(x,current_sum+x);//要么重新开始，要么接上去
		max_sum=max(max_sum,current_sum);
	}
	cout<<max_sum;
	return 0;
}
