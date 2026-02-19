#include <iostream>
using namespace std;

int main() {
    int n;
    long long d;
    cin >> n >> d;
    long long x[100000]; // n 最大不会很大，这里预设足够大
    for (int i = 0; i < n; ++i) cin >> x[i];

    int ans = 2; // 两端各一个候选位置
    for (int i = 0; i + 1 < n; ++i) {
        long long gap = x[i+1] - x[i];
        if (gap == 2 * d) ans += 1;
        else if (gap > 2 * d) ans += 2;
    }

    cout << ans << endl;
    return 0;
}

