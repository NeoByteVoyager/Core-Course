# include <iostream>

using namespace std;
void getMaxSum(int a[], int n, int &Left, int &Right);

int main()
{
    int n;
    cin>>n;

    int *p=new int[n];

    for(int i=0; i<n; i++)
        cin>>p[i];

    int Left, Right;
    getMaxSum(
p,n,Left,Right
);

    cout<<Left<<" "<<Right<<endl;
    delete[] p;

    return 0;
}

void getMaxSum(int a[], int n, int &Left, int &Right)
{
    int dp[n]={0};
	int pre[n]={0};
	dp[0]=a[0];
	for(int i=1;i<n;i++){
		if(dp[i-1]>0){
			dp[i]=dp[i-1]+a[i];
			pre[i]=pre[i-1];
		}
		else {
			dp[i]=a[i];
			pre[i]=i;
		}
	}
	int t=-100000000;
	for(int i=0;i<n;i++){

		if(dp[i]>t) {
			t=dp[i];
			Right=i; 
		}
	} 
	Left=pre[Right];
}
