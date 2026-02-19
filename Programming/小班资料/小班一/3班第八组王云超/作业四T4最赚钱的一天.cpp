#include <iostream> // 引入标准输入输出库
#include <climits>      // 提供 INT_MIN
using namespace std;

int main() {
    int n, c, s;
    cin >> n;                           //  读天数
    int maxProfit = INT_MIN;            //  最大盈利初始极小
    int bestDay = 1;                    //  最赚钱那天

    for (int i = 1; i <= n; ++i) {      //  逐天扫描
        cin >> c >> s;                  //  读当天成本与销售额
        int profit = s - c;             //  当天盈利
        if (profit > maxProfit) {       //  更大就更新
            maxProfit = profit;
            bestDay = i;
        }
    }

    cout << bestDay << '\n';            //  输出天数
    return 0;
}

