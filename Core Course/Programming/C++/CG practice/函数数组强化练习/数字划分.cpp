#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(int l,int r){
    ll res=0;
    for(int i=l;i<=r;i++){
        string a=to_string(i);
        int len=a.size();
        ll t=LLONG_MAX;
        for(int i=0;i<len-1;i++){
             if(a[i+1]!='0'||(a[i+1]=='0'&&i+1==len-1)){
                 ll t1=0,t2=0;
                for(int j=0;j<=i;j++) t1+=(int)(a[j]-'0');
                for(int j=i+1;j<len;j++) t2+=(int)(a[j]-'0');
                t=min(t,abs(t1-t2));
             }
        }
        res+=t;
    }
     return res;
}
int main(){
    int n;
    cin>>n;
    while(n--){
       ll l,r;
       cin>>l>>r;
       cout<<f(l,r)<<endl;
    }
    return 0;
}
