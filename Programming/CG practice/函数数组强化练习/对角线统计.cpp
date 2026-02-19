#include <bits/stdc++.h>
using namespace std;

const int MAXN = 26;
int g[MAXN][MAXN];   // 原矩阵
bool rep[MAXN][MAXN];// 是否被替换过

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> x >> y;
    for(int i = 1; i <= x; i++)
        for(int j = 1; j <= y; j++)
            cin >> g[i][j];

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    /* 1. 求子矩阵最值 */
    int mx = INT_MIN, mn = INT_MAX;
    for(int i = a; i <= c; i++)
        for(int j = b; j <= d; j++){
            mx = max(mx, g[i][j]);
            mn = min(mn, g[i][j]);
        }
    int diff = mx - mn;

    /* 2. 替换并统计次数 */
    int cnt1 = 0;
    for(int i = a; i <= c; i++)
        for(int j = b; j <= d; j++)
            if(g[i][j] < diff){          // 严格小于
                g[i][j] = mx;            // 改成最大值
                rep[i][j] = true;        // 打标记
                ++cnt1;
            }

    /* 3. 统计两条对角线上被替换过的元素个数 */
    int cnt2 = 0;
    // 主对角线：行号 == 列号
    for(int i = 1; i <= min(x, y); i++)
        if(rep[i][i]) ++cnt2;

    // 副对角线：行号 + 列号 == x + 1
    for(int i = 1; i <= min(x,y); i++){
        int j = x + 1 - i;
        if(1 <= j && j <= y && rep[i][j]) ++cnt2;
    }

    cout << cnt1 << ' ' << cnt2 << '\n';
    return 0;
}
