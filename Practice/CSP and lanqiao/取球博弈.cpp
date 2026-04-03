#include <bits/stdc++.h>
using namespace std;
int n[3];
const int MAXN=1005;
//dp[剩余球的数目][先手的奇偶][后手的奇偶][轮次] 
int dp[MAXN][2][2][2]; //0表示第一个人，1表示第二个人
int first=0,second=0;
//再使用一把minmax;
int end(int a,int b){
    int t1=a%2,t2=b%2;
    if(t1==t2) return 0;
    else if(t1==1) return 1;
    else return -1;
}
int MAX(int balls);
int MIN(int balls); 
char compete(int balls){
    int res=MAX(balls);
    if(res==1) return '+';
    else if(res==0) return '0';
    else return '-';
}
int main()
{
    // 请在此输入您的代码
    //初始化dp数组
    for(int i=0;i<MAXN;i++){
    	for(int j=0;j<2;j++){
    		for(int k=0;k<2;k++){
    			dp[i][j][k][0]=dp[i][j][k][1]=-2;
			}
		}
    }
    cin>>n[0]>>n[1]>>n[2];
    for(int i=0;i<5;i++){
        int balls=0;
        cin>>balls;
        cout<<compete(balls)<<" ";
    }
    return 0;
}
int MAX(int balls){
    if(dp[balls][first%2][second%2][0]!=-2) return dp[balls][first%2][second%2][0];
    int res=INT_MIN;
    bool ok=false;
    int upper=INT_MIN;
    for(int i=0;i<3;i++){
        if(balls>=n[i]){
            ok=true;
            first+=n[i];
            upper=max(upper,MIN(balls-n[i]));
            first-=n[i];
        }
    }
    if(!ok){ //不能继续取球
        return end(first,second);
    }
    else {
        return dp[balls][first%2][second%2][0]=upper;
    }
}
int MIN(int balls){
    if(dp[balls][first%2][second%2][1]!=-2) return dp[balls][first%2][second%2][1];
    int res=INT_MAX;
    bool ok=false;
    int lower=INT_MAX;
    for(int i=0;i<3;i++){
        if(balls>=n[i]){
            ok=true;
            second+=n[i];
            lower=min(lower,MAX(balls-n[i]));
            second-=n[i];
        }
    }
    if(!ok) return end(first,second);
    else return dp[balls][first%2][second%2][1]=lower;
}

