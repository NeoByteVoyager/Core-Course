#include<bits/stdc++.h>
using namespace std;
pair<int,int> Find_max_min(vector<int>&a,int l,int r){
	if(l==r) return {a[l],a[l]};
	
	int mid=l+(r-l)/2;
	//分别处理左右区间 
	auto left=Find_max_min(a,l,mid);
	auto right=Find_max_min(a,mid+1,r);
	//合并答案 
	int maxVal=max(left.first,right.first);
	int minVal=min(left.second,right.second);
	return {maxVal,minVal}; 
}
int main(){
	//从文件中读取数据 
	freopen("data3.txt","r",stdin);
	
	
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	//计时开始 
	clock_t start = clock();
	auto it=Find_max_min(a,0,n-1);
	clock_t end = clock();
	
	
	//输出数据 
	cout<<"data size:"<<n<<"\n";
	cout<<"max:"<<it.first<<" "<<"min:"<<" "<<it.second<<"\n";
	cout << "查找已结束\n";
    cout << fixed << setprecision(12)
         << "运行时间: " << double(end - start) / CLOCKS_PER_SEC << " 秒" << endl;

	fclose(stdin);
	return 0;
} 

