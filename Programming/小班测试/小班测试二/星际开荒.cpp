#include<bits/stdc++.h>
using namespace std;
int a[1001][1001],pre[1001][1001];
int n,m;
int main(){
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			sum+=a[i][j];
			pre[i][j]=pre[i-1][j]+sum;
//			cout<<pre[i][j]<<" ";
		}
//		cout<<endl;
	}
	int res=INT_MIN;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){//×óÉÏ¶¥µã 
			for(int p=i;p<=n;p++){
				for(int q=j;q<=m;q++){
					int sum=pre[p][q]-pre[i-1][q]-pre[p][j-1]+pre[i-1][j-1];
					if(sum==(p-i+1)*(q-j+1)) res=max(res,sum);
				
				}
			}
		}
	}
	cout<<res;
	return 0;
} 
