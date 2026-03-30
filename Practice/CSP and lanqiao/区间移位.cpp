#include <bits/stdc++.h>
using namespace std;
struct line{
    int l,r;
};
int main()
{
    // 请在此输入您的代码
    int n;
    cin>>n;
	vector<line>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].l>>a[i].r;
	}       
	sort(a.begin(),a.end(),[](auto &x,auto y){
		if(x.l!=y.l) return x.l<y.l;
		return x.r<y.r;
	});
	
	auto check=[&](int mid){
		int liner=0;
		for(int i=0;i<n;i++){
			int left=a[i].l,right=a[i].r;
			if(liner<left){  //中间有空白 ,向前移动到边界 
				if(left-liner>mid) return false;
				else liner+=right-left; 
			}
			else{ //中间无空白，但是要贪心的向后移动 
				int diff=min(liner-left,mid);
				liner=right+diff;
			}
			if(liner>=10000) return true;
		}
		return false;
	
	};
	
	int left=0,right=1e4;
	while(left<=right){
		int mid=left+(right-left)/2;
		if(check(mid)) right=mid-1;
		else left=mid+1;
	}
	cout<<left;
    return 0;
}
