#include <bits/stdc++.h>
using namespace std;
// 小根堆
class Heap
{
    vector<int> tree;
    int n;

public:
    Heap(vector<int> &a)
    {
        n = 0;
        tree.push_back(0); // 1.占位符下标从1开始
        build2(a);
    }
    void build1(vector<int> &a)
    {
        for (int i = 0; i < a.size(); i++)
        {
            tree.push_back(a[i]);
            n++;
            shiftup(n);
        }
    }
    void build2(vector<int> &a)
    {
        for (int i = 0; i < a.size(); i++)
        {
            tree.push_back(a[i]);
            n++;
        }
        for (int i = n / 2; i >= 1; i--)
        {
            shiftdown(i);
        }
    }
    void shiftup(int index)
    {
        int elem = tree[index];
        while (index > 1 && tree[index / 2] > elem)
        {
            tree[index] = tree[index / 2];
            index /= 2;
        }
        tree[index] = elem;
    }
    void shiftdown(int index)
    {
        int elem = tree[index];
        while (true)
        {
            // 只有一个孩子一定是左孩子
            int child = 2 * index;
            // 如果有两个孩子，先找到候选孩子节点即为最小的节点
            if (child < n && tree[child + 1] < tree[child])
                child++;
            // 如果没有孩子
            else if (child > n)
            {
                break;
            }
            if (tree[child] < elem) // 2.index在运行时更新，不能用index
            {
                tree[index] = tree[child];
                index = child;
            }
            else
                break; // 已经找到合适位置
        }
        tree[index] = elem;
    }
    void Push(int val)
    {
        tree.push_back(val);
        n++;
        shiftup(n);
    }
    int Top()
    {
        return tree[1];
    }
    void Pop()
    {
        if (n == 0)
            return;
        tree[1] = tree[n];
        n--;
        tree.pop_back(); // 真正移除最后一位
        if (n > 0)       // 3.最后一个元素删除后就不需要下沉了
            shiftdown(1);
    }
    bool empty()
    {
        return tree.size() == 1;
    }
};
int main()
{
    vector<int> a(5);
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    Heap h(a);
    while (!h.empty())
    {
        cout << h.Top() << " ";
        h.Pop(); // 4.不断弹堆
    }
    return 0;
}