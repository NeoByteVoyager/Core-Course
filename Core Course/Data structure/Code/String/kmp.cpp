#include <bits/stdc++.h>
using namespace std;
void kmp(string s, string p)
{
    int n = s.size(), m = p.size();
    vector<int> next(m, -1);
    for (int i = 1; i < m; i++)
    {
        int j = next[i - 1];
        while (j != -1 && p[j + 1] != p[i])
        {
            j = next[j];
        }
        if (p[j + 1] == p[i])
            j++;
        next[i] = j;
    }
    for (int i : next)
        cout << i << " ";
}
int main()
{
    string s;
    cin >> s;
    string p;
    cin >> p;
    kmp(s, p);
    return 0;
}