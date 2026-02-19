#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long dp[10001][10001];

int main(){
	ifstream fin("input3.txt");
	ofstream fout("output.txt");
	int n;
	fin>>n;
	clock_t start=clock();
	dp[1][1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i][j]=dp[i-1][j-1]%mod+j*dp[i-1][j]%mod ;
		}
	}
	int res=0;
	for(int i=1;i<=n;i++) res=(res+dp[n][i])%mod;
	clock_t end=clock();
	fout<<res;
	cout<<"data size:"<<n<<endl; 
    cout << fixed << setprecision(12)
         << "运行时间: " << double(end - start) / CLOCKS_PER_SEC << " 秒" << endl;
	return 0;
} 
