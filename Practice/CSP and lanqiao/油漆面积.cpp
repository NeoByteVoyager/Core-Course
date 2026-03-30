#include <bits/stdc++.h>
using namespace std;
const int MAXN=10005;
struct Edge{
    int x,y1,y2;
    int type; //1表示左边界，-1表示右边界 
};
int main()
{
    // 请在此输入您的代码
    int n;
    cin>>n;
    vector<Edge>edges;
    vector<int>Y; 
    for(int i=0;i<n;i++){
    	int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		int X1=min(x1,x2),Y1=min(y1,y2); 
		int X2=max(x1,x2),Y2=max(y1,y2);  
		
		Y.push_back(y1);
		Y.push_back(y2);
		
		edges.push_back({X1,Y1,Y2,1});
		edges.push_back({X2,Y1,Y2,-1});
	} 
	
	sort(edges.begin(),edges.end(),[](auto &u,auto &v){
		return u.x<v.x;
	}) ;
	
	//排序去重 
	sort(Y.begin(),Y.end());
	Y.erase(unique(Y.begin(),Y.end()),Y.end()); 
	
	int last_x=edges[0].x;
	vector<int>pointY(Y.size()-1);
	int res=0;
	
	for(int i=0;i<edges.size();i++){
		int dx=edges[i].x-last_x;
		if(dx>0){
			int count=0;
			for(int k=0;k<pointY.size();k++) {
				if(pointY[k]>0) count+=Y[k+1]-Y[k];
			}
			res+=count*dx;
			last_x=edges[i].x; 
		} 
		int start_id=lower_bound(Y.begin(),Y.end(),edges[i].y1)-Y.begin();
		int end_id=lower_bound(Y.begin(),Y.end(),edges[i].y2)-Y.begin();
		for(int j=start_id;j<end_id;j++){
			pointY[j]+=edges[i].type; 
		}
	}
	
	cout<<res;
    return 0;
}
