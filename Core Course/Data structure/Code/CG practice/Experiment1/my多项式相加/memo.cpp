#include <iostream>
#include "List.h" 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	int n;
	cin>>n;
	List L1,L2,L;
	while(n--){
		int cof,exp;
		cin>>cof>>exp;
		L1.insert(cof,exp);
	}
	cin>>n;
	while(n--){
		int cof,exp;
		cin>>cof>>exp;
		L2.insert(cof,exp);
	}
	int i=0,j=0;
	while(i<L1.getLen()&&j<L2.getLen()){
		Term t1=L1.getTerm(i),t2=L2.getTerm(j),t;
		if(t1.exp>t2.exp){
			L.insert(t1.cof,t1.exp);
			i++;
		}
		else if(t1.exp<t2.exp){
			L.insert(t2.cof,t2.exp);
			j++;
		} 
		else{
			int sumcof=t1.cof+t2.cof;
			if(sumcof!=0){
				L.insert(sumcof,t1.exp);
			}
			i++,j++;
		}
	}
	while(i<L1.getLen()){
		Term t=L1.getTerm(i);
		L.insert(t.cof,t.exp);
		i++;
	}
	while(j<L2.getLen()){
		Term t=L2.getTerm(j);
		L.insert(t.cof,t.exp);
		j++;
	}
	for(int i=0;i<L.getLen();i++){
		Term t=L.getTerm(i);
		cout<<t.cof<<" "<<t.exp<<endl;
	}
	return 0;
}
