#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	string a;
	cin>>n;
	cin>>a;
	a=a+a+a;
	int res=0;
	for(int i=n;i<=2*n;i++){
		char l=a[i-1],r=a[i];
		int p=i-1,q=i;
		int cntl=1,cntr=1;
		if(l!='w'){
			while(p>0&&(a[--p]==l||a[p]=='w')) cntl++;
		}
		else{
			char cl;
			while(p>0){
				if(a[--p]=='w') cntl++;
				else {
					cl=a[p];
					cntl++;
					break;
				}
			}
			while(p>0&&(a[--p]==cl||a[p]=='w') )cntl++;//
		}
		if(r!='w') {
			while(q<3*n-1&&(a[++q]==r||a[q]=='w')) cntr++;
		}
		else{
			char cr;
			while(q<3*n-1){
				if(a[++q]=='w') cntr++;
				else{
					cr=a[q];
					cntr++;
					break;
				}
			}
			while(q<3*n-1&&(a[++q]==cr||a[q]=='w')) cntr++;//
			
		}
//		cout<<cntl<<" "<<cntr<<endl; 

		res=max(res,cntl+cntr);//
		res=min(res,n);//
	}
	cout<<res;
	return 0;
} 
