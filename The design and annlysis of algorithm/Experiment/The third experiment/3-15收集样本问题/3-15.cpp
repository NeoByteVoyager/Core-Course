#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("input_large_1.txt");
	ofstream fout("output.txt");
	
	int n;
	fin>>n;
	
	int x,y,w;
	vector<vector<int>>grid(n+1,vector<int>(n+1));
	while(fin>>x>>y>>w){
		if(x==0&&y==0&&w==0) break;
		grid[x][y]=w;
	}
	
	clock_t st = clock();
	//走k步时，一个在第i行一个在第j行时的最大值
	int maxSteps=2*n;//最大走2*n-2步即可到达b点
	vector<vector<vector<int>>>dp(maxSteps+1,vector<vector<int>>(n+1,vector<int>(n+1))); 
	dp[2][1][1]=grid[1][1];//把初始状态设置为k=2，可以达到行数加上列数等于k的效果，便于计算坐标
	
	for(int k=3;k<=maxSteps;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int y1=k-i;
				int y2=k-j;
				//如果越界跳过 
				if(y1<1||y1>n||y2<1||y2>n) {
					dp[k][i][j]=INT_MIN;
					continue; 
				}
				
				//计算到达这个状态的值 
				int val=grid[i][y1];
				if(i!=j||y1!=y2) val+=grid[j][y2];//如果到达同一个格子就只需要加一次 
				
				int prev=INT_MIN;
				//这一状态可以有四个状态到达
				prev=max(prev,dp[k-1][i-1][j-1]);//两人同时向下走
				prev=max(prev,dp[k-1][i-1][j]);//一人向下走，一人向右走
				prev=max(prev,dp[k-1][i][j-1]);//一人向下走，一人向右走
				prev=max(prev,dp[k-1][i][j]);//两人同时向右走
				
				dp[k][i][j]=val+prev;
				 
			}
		}
	}
	clock_t ed = clock();
	
	cout<<"图形规模："<<n<<"*"<<n<<endl; 
	cout<<"结果："<<dp[maxSteps][n][n]<<endl;
	 // 程序运行时间
    cout << fixed << setprecision(12);
    cout << "程序运行时间: " << (double)(ed - st) / CLOCKS_PER_SEC << "秒\n";
	
	return 0;
} 
