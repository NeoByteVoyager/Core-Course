#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> a;
class SegTree
{
    vector<long long> tree;
    vector<long long> lazy_multi;
    vector<long long> lazy_add;
    int n;

    void pushup(int p)
    {
        tree[p] = (tree[p << 1] + tree[p << 1 | 1]);
    }
    void pushdown(int p, int pl, int pr)
    {
        if (lazy_add[p])
        {
            int mid = (pl + pr) >> 1;

            lazy_add[p << 1] += lazy_add[p];
            lazy_add[p << 1 | 1] += lazy_add[p];
            tree[p << 1] += (mid - pl + 1) * lazy_add[p];
            tree[p << 1 | 1] += (pr - mid) * lazy_add[p];
            lazy_add[p] = 0;
        }
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
    long long query(int p, int pl, int pr, int l, int r)
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
            pushdown(p, pl, pr);
            int m = (pl + pr) >> 1;
            long long s1 = query(p << 1, pl, m, l, r);
            long long s2 = query(p << 1 | 1, m + 1, pr, l, r);
            tree[p] = tree[p << 1] + tree[p << 1 | 1];
            return (s1 + s2);
        }
    }
    void update(int p, int pl, int pr, int l, int r, long long c)
    {
        // 没有交集
        if (pl > r || pr < l)
            return;
        // 完全包含
        if (pl >= l && pr <= r)
        {
            lazy_add[p] += c;
            int len = pr - pl + 1;
            tree[p] += (long long)c * len;
        }
        else
        {
            // 先往下推
            pushdown(p, pl, pr);
            int mid = (pl + pr) >> 1;
            update(p << 1, pl, mid, l, r, c);
            update(p << 1 | 1, mid + 1, pr, l, r, c);
            tree[p] = tree[p << 1] + tree[p << 1 | 1];
        }
    }

public:
    SegTree(const vector<long long> &a, int n)
    {
        this->n = n;
        tree.resize(4 * n + 1);
        lazy_multi.resize(4 * n + 1);
        lazy_add.resize(4 * n + 1);
        buildTree(a, 1, 0, n - 1);
    }
    long long query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
    void update(int l, int r, long long c)
    {
        update(1, 0, n - 1, l, r, c);
    }
};
int main()
{
    int m;
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    SegTree tree(a, n);
    // cout << tree.query(0, 1) << " ";
    // cout << tree.query(2, 5) << " ";
    // cout << tree.query(0, 6);
    long long op, t, g, c;
    while (m--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> t >> g >> c;
            tree.update(t - 1, g - 1, c);
        }

        else
        {
            cin >> t >> g;
            cout << tree.query(t - 1, g - 1) << endl;
        }
    }
    return 0;
}