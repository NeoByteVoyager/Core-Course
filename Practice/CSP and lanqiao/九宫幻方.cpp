#include <iostream>
using namespace std;
int a[3][3];
bool vis[10];
int c[3][3];
int res=0;
bool ok(){ //每一行每一列每个对角线都等于15 
	for(int i=0;i<3;i++){
		int rs=0,cs=0; //记录行和列的和 
		for(int j=0;j<3;j++){
			rs+=a[i][j];
			cs+=a[j][i]; 
		}
		if(rs!=15||cs!=15) return false;
	}
	return a[0][0]+a[1][1]+a[2][2]==15&&a[0][2]+a[1][1]+a[2][0]==15;
}
void dfs(int now){
	if(res>=2) return; //如果结果不唯一,直接返回 
	if(now==9){ //搜索完成，判断是否合格 
		if(ok()){
			res++; //如果合格 
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					c[i][j]=a[i][j];
				}
			}
		}
		return;
	} 
	int i=now/3,j=now%3;
	if(a[i][j]) { //bug1:每个分支及时返回 
		dfs(now+1); //如果这个格子已经填写过
		return ;
	}
	//如果还没有填写
	for(int k=1;k<10;k++){
		if(!vis[k]){ //如果这个数字还没有使用 
			vis[k]=true;
			a[i][j]=k; 
			dfs(now+1);
			vis[k]=false;
			a[i][j]=0;
		}
	} 
}
int main()
{
    // 请在此输入您的代码
    int cnt=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
            if(a[i][j]){
                vis[a[i][j]]=true;
                cnt++;
            }
        }
    }
    if(cnt<=1) {
        cout<<"Too Many";
        return 0; //bug2:及时返回零后面不再执行 
    }
    dfs(0);

    if(res>1) cout<<"Too Many";
    else {
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<c[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
/*
0 7 2
0 5 0
0 3 0
*/
