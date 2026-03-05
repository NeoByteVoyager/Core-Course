#include<bits/stdc++.h>
using namespace std;
int compute(int a,int b,char c){
	if(c=='-') return a-b;
	else if(c=='+') return a+b;
	else return a*b;
}
vector<int> f(vector<int>&a,vector<char>&b){
	int len=a.size();
	vector<vector<vector<int>>>t(len,vector<vector<int>>(len));
	for(int i=0;i<len;i++) t[i][i].push_back(a[i]);
	for(int r=2;r<=len;r++){
		for(int i=0;i<=len-r;i++){
			int j=i+r-1;
			for(int k=i;k<j;k++){
				for(int p:t[i][k]){
					for(int q:t[k+1][j]){
						int tmp=compute(p,q,b[k]);
						t[i][j].push_back(tmp);
					}
				}
			}
		}
	} 
	vector<int>res;
	for(int i:t[0][len-1]){
		res.push_back(i);
	}
	return res;
}
vector<int> diffWaysToCompute(string expression) {
        vector<int>a;
        vector<char>b;
        string t;
        int len=expression.size();
        int i=0;
        while(i<len){
            if(isdigit(expression[i])){
                t+=expression[i];
                i++;
            }
            else{
                a.push_back(stoi(t));
                b.push_back(expression[i]);
                t="";
                i++;
            }
        }
        a.push_back(stoi(t));
		return f(a,b);
}
int main(){
	string s;
	cin>>s;
	vector<int>t=diffWaysToCompute(s);
	for(int i:t) cout<<i<<" ";
	return 0;
} 
