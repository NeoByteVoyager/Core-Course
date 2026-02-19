#include <bits/stdc++.h>
using namespace std;

inline bool isLetter(char c){ return c >= 'a' && c <= 'z'; }
inline bool isDigit(char c){ return c >= '0' && c <= '9'; }
inline bool isAlnumChar(char c){ return isLetter(c) || isDigit(c); }
// 允许出现在 A 段（开头以后）的字符：字母/数字/_ 
inline bool allowedInA(char c){ return isLetter(c) || isDigit(c) || c == '_'; }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    if(!(cin >> s)) return 0;
    int n = (int)s.size();

    // runLetters[i] = 在以 i 结尾的、仅由 allowedInA 组成的连续段中，
    // 到位置 i 为止，该段中字符为字母的个数（即可作为 A 起点的字母数）
    vector<int> runLetters(n, 0);
    for(int i = 0; i < n; ++i){
        if(allowedInA(s[i])){
            int prev = (i > 0 && allowedInA(s[i-1])) ? runLetters[i-1] : 0;
            runLetters[i] = prev + (isLetter(s[i]) ? 1 : 0);
        } else {
            runLetters[i] = 0;
        }
    }

    long long ans = 0;
    // 对每个 '@' 计算贡献
    for(int i = 0; i < n; ++i){
        if(s[i] != '@') continue;

        // 左侧 A 的数量等于 runLetters[i-1]（若 i==0 则为0）
        int leftCnt = 0;
        if(i - 1 >= 0) leftCnt = runLetters[i-1];
        if(leftCnt == 0) continue; // 左侧没有合法 A，跳过

        // 右侧：B 必须是非空字母或数字序列（不能含 '_'）
        int pos = i + 1;
        if(pos >= n || !isAlnumChar(s[pos])) continue;
        while(pos < n && isAlnumChar(s[pos])) pos++;

        // 接下来必须是 '.'
        if(pos >= n || s[pos] != '.') continue;
        ++pos;

        // C 段必须是由字母组成的非空序列
        int cntC = 0;
        while(pos < n && isLetter(s[pos])){
            ++cntC;
            ++pos;
        }
        if(cntC == 0) continue;

        // 每一个从 '.' 后字母段中任意一个起点到不同终点都是不同子串，
        // 因此 C 的可选数就是 cntC（以 '.' 后第1字母起、或第2字母起...）
        ans += 1LL * leftCnt * cntC;
    }

    cout << ans << '\n';
    return 0;
}

