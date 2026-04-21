#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e6;
bool ok[MAXN+1];
int main()
{
    // 请在此输入您的代码
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    ok[0]=true;
    for(int i=1;i<=MAXN;i++){
        for(int j=0;j<n;j++){
            if(i>=a[j]&&ok[i-a[j]]) {
                ok[i]=true;
                break;
            }
        }
    }
    for(int i=1e7;i<=MAXN;i++){
        if(!ok[i]) {
            cout<<"INF";
            return 0;
        }
    }
    int count=0;
    for(int i=1;i<=MAXN;i++){
        if(!ok[i]){
            count++;
        }
    }
    cout<<count;
    return 0;
}
