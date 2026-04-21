#include<stdio.h>
int func4(int x,int y){
	if(x<=0) return 0;
	if(x==1) return y;
	return y+func4(x-1,y)+func4(x-2,y);
}
int main(){
    int y;
    scanf("%d",&y);
	printf("%d",func4(7,y));
	return 0;
}
