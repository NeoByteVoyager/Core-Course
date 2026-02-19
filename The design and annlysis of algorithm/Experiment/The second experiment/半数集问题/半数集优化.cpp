#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int mod=100007;
int dp[10001]; 

ll getNum(int n){
	dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]=1;
		for(int j=1;j<=i/2;j++){
			dp[i]=(dp[i]+dp[j])%mod;
		}
	}
	return dp[n];
}

int main(){
	int n;
	ifstream fin("input3.txt");
	ofstream fout("res.txt");
	fin>>n;
	clock_t start=clock();
	ll res=getNum(n);
	clock_t end=clock();
	fout<<res;
	cout<<"data size:"<<n<<endl; 
    cout << fixed << setprecision(12)
         << "运行时间: " << double(end - start) / CLOCKS_PER_SEC << " 秒" << endl;
	return 0;
} 
