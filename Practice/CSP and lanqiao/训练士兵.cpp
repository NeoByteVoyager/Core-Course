#include <bits/stdc++.h>
using namespace std; 


int main()
{
    // 请在此输入您的代码
    long long n,s;
    cin>>n>>s;

    vector<int>p(n),c(n);

    int min_c=INT_MAX;
    bool ok=false;

    long long totol_p=0;
    for(int i=0;i<n;i++){
        cin>>p[i]>>c[i];
        totol_p+=p[i];
        min_c=min(min_c,c[i]);
    }
    //先判断团购是否更便宜
    if(s<=totol_p) ok=true;

    auto check=[&](int mid){
        return true;
    };

    long long left=0,right=1e15;
    while(left<=right){
        long long mid=left+(right-left)/2;
        if(check(mid)) right=mid-1;
        else left=mid+1;
    }
	cout<<left;
    return 0;
}
