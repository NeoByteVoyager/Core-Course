#include <bits/stdc++.h>
using namespace std;
int calculate(int x,int y,int z){
    if(x==y&&y==z) return 200; //三个都相等
    if(x+1==y&&y+1==z) return 200; //顺序出现
    if(x==y||y==z||x==z) return 100; //两个相等
    vector<int>v={x,y,z};
    sort(v.begin(),v.end());
    if(v[0]+1==v[1]&&v[1]+1==v[2]) return 100;
    return 0;
}
int main()
{
  // 请在此输入您的代码
    int n;
    cin>>n;
    //输入转盘
    vector<int>a(n),b(n),c(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++) cin>>c[i];

    int ai=0,bi=0,ci=0; //指针位置
    int res=0; //结果
    int m;
    cin>>m;
    while(m--){
        int x,y,z;
        cin>>x>>y>>z;
        ai=(ai+x)%n,bi=(y+bi)%n,ci=(z+ci)%n;
        res+=calculate(a[ai],b[bi],c[ci]);
    }
    cout<<res;
    return 0;
}
