#include<bits/stdc++.h>
using namespace std;
int s[]={-3,-2,-1,1,2,3}; //一共有六种选择 
int main(){
	unordered_map<string,int>mp; //记录已经到达的局面 
	string a,b;
	cin>>a>>b;
	int n=a.size();
	
	queue<string>q; 
	q.push(a);
	mp[a]=1;
	int step=0;
	
	while(!q.empty()){
		step++;
		int sz=q.size();
		for(int i=0;i<sz;i++){
			string t=q.front();
			q.pop();
			for(int j=0;j<n;j++){
				if(t[j]=='*'){ //当前是空杯子，相当于空杯子进行跳跃 
					for(int k=0;k<6;k++){
						string ti=t;//创建副本 
						int m=s[k]+j;
						if(m>=0&&m<n) {
							
							swap(ti[m],ti[j]);
							if(mp.count(ti)==0) {
//								cout<<step<<" "<<ti<<endl;
								if(ti==b) {
									cout<<step;
									return 0;
								}
								else{
									q.push(ti);
									mp[ti]=1;
								}
							}
						}
					}
				}
			}
		}
	} 
	
	return 0;
} 
