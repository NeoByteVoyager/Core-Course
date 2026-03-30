#include<bits/stdc++.h>
using namespace std;
int outstack(char c){
	if(c=='*'||c=='/') return 2;
	else if(c=='+'||c=='-') return 1; //
	else return 3; 	//在栈外'('的优先级最高 
}
int instack(char c){
	if(c=='*'||c=='/') return 2;
	else if(c=='+'||c=='-') return 1;
	else return 0; //在栈内'('的优先级最低 
} 
bool check(string exp){
	for(int i=0;i<exp.size()-1;i++) { //最后一个#不用判断 
		char c=exp[i];
		if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')'||isdigit(c)) continue; //bug:字符串还有数字 
		return false;
	} 
	return true;
}
string change(string exp){
	int n=exp.size();
	stack<char>st;
	string res; 
	for(int i=0;i<n-1;){
		char c=exp[i];
		if(isdigit(c)){ //求得该数字
			string num;
			while(i<n-1&&isdigit(exp[i])){
				num+=exp[i];
				i++;
			}
			res+=num;
			res+=" ";
		}
		else{ //运算符 
			if(c==')'){
				while(st.top()!='('){ //直到把左括号弹出来 
					res+=st.top();
					res+=" ";
					st.pop(); 
				}
				st.pop(); //左括号弹出来 
			}
			else{ //比较运算符级别 
				int cur_prior=outstack(c);
				while(!st.empty()&&instack(st.top())>=cur_prior){ //把优先级大的弹出来 
					res+=st.top();
					res+=" ";
					st.pop(); 
				}
				st.push(c); //把当前运算符压栈 
			}
			i++; 
		} 
	}	
	while(!st.empty()){
		res+=st.top();
		res+=' '; 
		st.pop();
	}
	return res; 
}
int f(int u,int v,char c){
	switch(c){
		case '+':return u+v;
		case '-':return u-v;
		case '*':return u*v;
		default: return u/v;
	}
}
int calculate(string exp){
	stack<int>st;
	stringstream ss(exp);
	string item;
	while(getline(ss,item,' ')){
		if(isdigit(item[0])){
			st.push(stoi(item));
		}	
		else{
			int v1,v2;
			v2=st.top(); st.pop(); 
			v1=st.top(); st.pop();
			st.push(f(v1,v2,item[0]));		
		}
	}
	return st.top();
}
int main(){
	string org_exp;
	cin>>org_exp;
	if(!check(org_exp)){
		cout<<"NO";
		return 0; 
	}
	string ex_exp=change(org_exp);
//	cout<<ex_exp;
	int res=calculate(ex_exp);
	cout<<res;
	return 0;
} 
