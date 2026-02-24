#include <iostream>
#include <algorithm>
using namespace std;

struct Building {
    int x, a;
};


bool cmp(Building b1, Building b2) {
    return b1.x < b2.x;
}

int main() {
    int n, t;
    cin >> n >> t;
    
    Building b[1005];
    for(int i = 0; i < n; i++) {
        cin >> b[i].x >> b[i].a;
    }
    
    // 排序
    sort(b, b + n, cmp);
    
    int ans = 2; // 最左和最右必定各有一个位置
    
    for(int i = 0; i < n - 1; i++) {
        // 使用 / 2.0 强制转换为浮点数运算，防止精度丢失
        double right_side = b[i].x + b[i].a / 2.0;       // 左边房子的右墙
        double left_side = b[i+1].x - b[i+1].a / 2.0;    // 右边房子的左墙
        double gap = left_side - right_side;             // 中间的空隙
        
        if (gap > t) {
            ans += 2; // 空隙很大，可以贴左边放一个，也可以贴右边放一个
        } else if (gap == t) {
            ans += 1; // 空隙刚好够放一个
        }
        // 如果 gap < t，放不下，ans不变
    }
    
    cout << ans << endl;
    return 0;
}
