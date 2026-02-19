#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("input_large_5.txt");
	ofstream fout("output.txt");
	string a,b;
	fin>>a>>b;
	a=" "+a,b=" "+b;//转换为1-base 
	int k;
	fin>>k; 
	
	
	int n=a.size(),m=b.size();
	vector<vector<int>>dp(n+1,vector<int>(m+1));
	dp[0][0]=0;
	
	
	clock_t st = clock();
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(!i) dp[i][j]=k*j;//a串为空 
			else if(!j) dp[i][j]=k*i;//b串为空
			else {
				//如果选择a[i]和b[j]匹配 
				int t1=dp[i-1][j-1]+abs(a[i]-b[j]);
				//如果让a[i]和空格匹配 
				int t2=dp[i-1][j]+k;
				//如果让b[i]和空格匹配 
				int t3=dp[i][j-1]+k;
				dp[i][j]=min(t1,min(t2,t3)); 
			}
		}
	}
	clock_t ed = clock();
	
	cout<<"a串长度:"<< n<<",b串长度："<<m<<endl;
	cout<<"结果："<<dp[n][m]<<endl;
	 // 程序运行时间
    cout << fixed << setprecision(12);
    cout << "程序运行时间: " << (double)(ed - st) / CLOCKS_PER_SEC << "秒\n";
	return 0;
} 
