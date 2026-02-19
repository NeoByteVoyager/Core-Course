#include <iostream>        // 引入标准输入输出库
using namespace std;       // 打开 std 命名空间，省去 std::

int main() {               
    int sum=0;
	for(int i=1;i<=5;i++){
		sum+=i;
	} 
	cout<<sum<<endl;
    return 0;              //  正常结束
}                          

