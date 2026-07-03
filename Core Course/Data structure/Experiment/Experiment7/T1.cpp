#include <bits/stdc++.h>
using namespace std;
int n, P;
vector<long long> a;
class SegTree
{
    vector<long long> tree;
    vector<long long> lazy_multi;
    vector<long long> lazy_add;
    int n;

    void pushup(int p)
    {
        tree[p] = (tree[p << 1] + tree[p << 1 | 1]) % P;
    }
    void pushdown(int p, int pl, int pr)
    {
    }
    void buildTree(const vector<long long> &a, int p, int l, int r)
    {
        if (l == r)
        { // 到根节点
            tree[p] = a[l];
            return;
        }
        int m = (l + r) >> 1;
        buildTree(a, p << 1, l, m);
        buildTree(a, p << 1 | 1, m + 1, r);
        pushup(p); // 回溯
    }
    int query(int p, int pl, int pr, int l, int r)
    {
        // 完全不包含
        if (pl > r || pr < l)
        {
            return 0;
        }
        // 完全包含
        else if (pl >= l && pr <= r)
        {
            return tree[p];
        }
        // 重叠
        else
        {
            int m = (pl + pr) >> 1;
            long long s1 = query(p << 1, pl, m, l, r);
            long long s2 = query(p << 1 | 1, m + 1, pr, l, r);
            return (s1 + s2) % P;
        }
    }
    void update(int p, int pl, int pr, int l, int r, int type)
    {
        // 全包含
        if (pl <= l && pr <= r)
        {
        }
        pushdown(p, pl, pr);
        update()
    }

public:
    SegTree(const vector<long long> &a, int n) : n(n)
    {
        tree.resize(4 * n + 1);
        lazy_multi.resize(4 * n + 1);
        lazy_add.resize(4 * n + 1);
        buildTree(a, 1, 0, n - 1);
    }
    int query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
    void update(int l, int r, int c, int type)
    {
        update(1, 0, n - 1, l, r, type);
    }
};
int main()
{
    cin >> n >> P;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    SegTree tree(a, n);
    // cout << tree.query(0, 1) << " ";
    // cout << tree.query(2, 5) << " ";
    // cout << tree.query(0, 6);
    int m, op, t, g, c;
    cin >> m;
    while (m--)
    {
        cin >> op;
        if (op == 1 || op == 2)
        {
            cin >> t >> g >> c;
            tree.update(t - 1, g - 1, c, op);
        }

        else
        {
            cin >> t >> g;
            cout << tree.query(t - 1, g - 1) << endl;
        }
    }
    return 0;
}