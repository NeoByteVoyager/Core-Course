#include <iostream>   // ① 引入标准输入输出
#include <iomanip>    // ② 控制小数位数 setprecision
#include <cmath>      // ③ 提供 fabsl 取绝对值
using namespace std;  // ④ 打开 std 命名空间

int main() {
    const long double PI = 3.1415926535; // ⑤ 定义高精度 π
	long double x;                       // ⑥ 任意实数角度（弧度）
	cin >> x;                            // ⑦ 读入用户角度
	long double twoPi = 2.0L * PI;       // ⑧ 一次算好 2π，避免重复乘法
	
	while (x >  PI) x -= twoPi;   // ⑨ 当x>π,把 x 压到 (-π, π] 
	while (x < -PI) x += twoPi;   // ⑩ 当x<-π,把 x 抬到 (-π, π] 
	long double sum = 0.0L, term = x; // ? sum：累加器；term：当前项（首项 = x）
	int n = 0;                       		 // ? 项序号 0,1,2...
	
	while (fabsl(term) >= 0.5e-13) {   	// ? 最后一项绝对值 < 0.5×10?13 即停
	    sum += term;                  	// ? 累加当前项
	    n++;                         		 // ? 下标前进
	    term = -term * x * x / (2*n * (2*n+1)); // ? 递推下一项：符号翻转 + 阶乘展开
	}
	
	cout << fixed << setprecision(13) << sum << '\n'; // ? 固定 13 位小数输出
	return 0;       
}
