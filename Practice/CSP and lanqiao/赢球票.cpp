#include <bits/stdc++.h>
using namespace std;
int res=0;
int n;
vector<int>p;
void f(int x){
    queue<int>q;
    for(int i=x;i<=n;i++) q.push(p[i]);
    for(int i=1;i<x;i++) q.push(p[i]);

    int now=1; //当前报数
    int index=x;
    int tmp=0;
    
    while(!q.empty()&&now<=n){
        int u=q.front();
        q.pop(); 
        if(u==now) {
        	now=1;
        	tmp+=u;
		}
        else {
            now++;
            q.push(u);
        }
    }

    res=max(res,tmp);
}
int main()
{
    // 请在此输入您的代码
    
    cin>>n;
    p.resize(n+1);
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) f(i);
    cout<<res;
    return 0;
}
