#include<bits/stdc++.h>
using namespace std;
struct Item{
	int w,v;
	double t;
};
int bestv=-1;
int weight=0;
int val=0;
double calculateBound(int k,int n,int c,vector<Item>&item) {
	//界限函数判断有无必要进入右子树,这里的界限按照贪心计算 
	int nw=weight;
	double bound=val;
	for(int i=k+1;i<n;i++){
		if(nw+item[i].w<=c) {
			nw+=item[i].w;
			bound+=item[i].v;
		}
		else{
			bound+=item[i].t*(c-nw); 
			break;
		} 
	}	
	return bound;
}
void backtrack(int k,int n,int c,vector<Item>&item){
	if(k>=n){
		bestv=max(val,bestv);
		return ;
	}
	//判断能否进入左子树(约束函数)
	if(weight+item[k].w<=c){
		weight+=item[k].w;
		val+=item[k].v;
		backtrack(k+1,n,c,item);
		val-=item[k].v;
		weight-=item[k].w;
	}
	//判断上界是否大于当前bestv 
	double bound=calculateBound(k,n,c,item);
	if(bound<=bestv) return;
	backtrack(k+1,n,c,item);
}
int main(){
	ifstream fin("input1.txt");
	ofstream fout("output.txt"); 
	int n,c;
	fin>>c>>n;
	
	vector<Item>item(n);
	for(int i=0;i<n;i++){
		fin>>item[i].w>>item[i].v;
		item[i].t=double(item[i].v)/item[i].w;
	} 
	sort(item.begin(),item.end(),[](Item&x,Item&y){
		return x.t>y.t;	
	}); 
	backtrack(0,n,c,item);
	fout<<bestv;
	return 0;
} 
