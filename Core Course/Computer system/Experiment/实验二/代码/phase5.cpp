#include<bits/stdc++.h>
using namespace std;

int arr[]={10,2,14,7,8,12,15,11,0,4,1,13,3,9,6,5};
int main(){
	unordered_map<int,int>mp; //val->index
	
	for(int i=0;i<16;i++) {
		mp[arr[i]]=i;
	}

//	int t=15,cnt=1,tot=0;;
//	while(cnt<16){
//		cout<<t<<"->"<<mp[t]<<" "; 
//		cnt++;
//		t=mp[t];
//		tot+=t;
//	}	
	
	int t=5,cnt=0,tot=0;
	while(t!=15){
		cnt++;
		t=arr[t];
		tot+=t;
	}
	cout<<"输入的第一个数字："<<5<<",循环次数："<<cnt<<"，累加和："<<tot;
	return 0;
}
