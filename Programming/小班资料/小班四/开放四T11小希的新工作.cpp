#include <iostream>
using namespace std;

int main() {
    int n, L, a;
    cin >> n >> L >> a; // 读入人数、总时长、休息单位时间

    int last = 0; // 记录上一次任务结束的时间点，初始为0
    int ans = 0;  // 记录总休息次数

    for(int i = 0; i < n; i++) {
        int t, l;
        cin >> t >> l; // 读入客人到来时刻和服务时长
        
        // 1. 计算客人到来前的空闲时间能休息几次
        // t - last 就是这段空闲的长度
        ans += (t - last) / a;

        // 2. 更新忙碌结束的时间点
        // 服务结束时间 = 到达时间 + 服务时长
        last = t + l;
    }

    // 3. 循环结束后，处理从最后一位客人离开到下班这段时间
    ans += (L - last) / a;

    cout << ans << endl;
    return 0;
}
