#include <bits/stdc++.h>
using namespace std;
int n;
string a, b;
string post(string a, int al, int ar, string b, int bl, int br)
{
    if (al > ar)
        return "";
    string res;

    char rt = a[al]; // 根节点的值
    // 查找根节点在b中的位置
    int i = bl;
    for (i; i <= br; i++)
    {
        if (b[i] == rt)
            break;
    }

    int lz = i - bl, rz = br - i; // 计算左右子树的大小

    // 递归求解左右子树
    res += post(a, al + 1, al + lz, b, bl, i - 1);
    res += post(a, al + lz + 1, ar, b, i + 1, br);

    return res += rt;
}
int main()
{
    while (cin >> n)
    {
        if (n == 0)
            break;
        cin >> a >> b;
        cout << post(a, 0, n - 1, b, 0, n - 1) << endl;
    }
    return 0;
}