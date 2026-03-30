#include <bits/stdc++.h>
using namespace std;
const int maxn=1e7+1;
bool is_prime[maxn];
void init(){
    for(int i=2;i<=maxn;i++) is_prime[i]=true;
    for(int i=2;i*i<=maxn;i++){
        if(is_prime[i]){
            for(int j=2*i;j<=maxn;j+=i){
                is_prime[j]=false;
            }
        }
    }
}
int main()
{
    init();
    int cnt=0;
    for(int i=2;i<=maxn;i++){
        if(is_prime[i]) cnt++;
        if(cnt==2025){
            cout<<i;
            return 0;
        } 
    }
    return 0;
}
