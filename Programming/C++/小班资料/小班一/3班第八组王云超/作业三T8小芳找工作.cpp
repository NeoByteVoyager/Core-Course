#include <iostream>        // 引入标准输入输出库
using namespace std;       // 打开 std 命名空间，省去 std::

int main() {               
    int s, d;              //  月薪 s，距离 d
    char v;                //  带薪休假标志：'y' 或 'n'
    cin >> s >> v >> d;    //一次读入：整数 字符 整数

    // 计数器：满足条件即得 1，否则 0，三数相加
    int cnt = (s >= 5000) + (v == 'y') + (d <= 2000);

    //  三元运算符：≥2 输出 Accept，否则 Refuse
    cout << (cnt >= 2 ? "Accept" : "Refuse") << '\n';

    return 0;              //  正常结束
}                          

