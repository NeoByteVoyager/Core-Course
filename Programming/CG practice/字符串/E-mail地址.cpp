#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin>>s;
	int n=s.size();	
	//找到突破口@
	int res=0;
 	for(int i=0;i<n;i++){
 		int cl=0,cr=0;
 		if(s[i]=='@'){
 			//先判断能不能构成
			 int j=i+1;
			 if(s[j]=='.') continue;//中间是空串 
			 bool ok=true;
			 while(j<n){
			 	if(isalnum(s[j])) j++;
				else if(s[j]=='.') break;
				else{
					ok=false;
					break;
				}
			 } 
//			 cout<<j<<endl; 
//			 cout<<s[j]<<endl; 
			 if(ok){
			 	while(j<n&&isalpha(s[++j])) cr++;	
			 }
//			 cout<<cr<<endl;
 			if(ok){
			 	//向左扩展	
 				j=i-1;
 				while(j>=0){
 					if(isalpha(s[j])){
 						cl++;
 						j--;
					 }
					 else if(s[j]=='_'||isdigit(s[j])) {
					 	j--; 
					 }
					 else break;
				 }	
			 }
		 }
		 res+=cl*cr;
	 }
	cout<<res;
	
	
	return 0;
} 
