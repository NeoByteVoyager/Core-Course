#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i) cin >> a[i];

        if (n < 3) {           // 题目已给 n≥3，防御性写法
            cout << "No\n";
            continue;
        }

        bool ok = true;
        for (int i = 1; i < n - 1; ++i) {
            int prev = a[i - 1], cur = a[i], next = a[i + 1];
            if (cur == prev || cur == next) {   // 相邻相等
                ok = false;
                break;
            }
            bool peak = (cur > prev && cur > next);
            bool valley = (cur < prev && cur < next);
            if (!peak && !valley) {             // 既不是峰也不是谷
                ok = false;
                break;
            }
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}
