#include<bits/stdc++.h>
using namespace std;
vector<int>seq;
vector<queue<int>>qi;
int res=0,cur=1; //记录答案和下一个要出队列的列车号码 
void add(int x){
	//先入队列,优先加入到队尾最大的队列 
	int idx=-1,max=-1; 
	for(int i=0;i<qi.size();i++){
		if(!qi[i].empty()&&qi[i].back()<x) {
			if(qi[i].back()>max){
				idx=i;
				max=qi[i].back();
			}
		}
		//此处是空的并且在其他位置不能加入此时max=-1 
		else if(qi[i].empty()&&max==-1) idx=i;
	}
	if(idx==-1){ //没有队列可以加上 
		//新开一个队列
		res++; 
		queue<int>q;
		qi.push_back(q);
		qi[qi.size()-1].push(x);
	}
	else{//有队列可以加上
		//加在该队列的后面 
		 qi[idx].push(x);
	}
	//然后出队
	while(true){
		//记录本轮是否有出队 
		int flag=false;
		for(int i=0;i<qi.size();i++){
			if(!qi[i].empty()&&qi[i].front()==cur){
				qi[i].pop();
				cur++;
				flag=true;
			}
		}
		//如果该轮没有出队，退出 
		if(!flag) break;
	}
}
int main(){
	//输入入队序列,此处容易被误导不一定是9个 
	int x; 
	while(cin>>x){
		seq.push_back(x);
	}
	for(int i=seq.size()-1;i>=0;i--){
		add(seq[i]);
	}
	cout<<res;
	return 0;
}
