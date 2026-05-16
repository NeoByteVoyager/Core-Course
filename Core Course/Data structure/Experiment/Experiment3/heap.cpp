#include <bits/stdc++.h>

using namespace std;

class heap
{
private:
    int n;
    int *elem;
    void shiftdown(int pos)
    {
        int v = elem[pos];
        while (true)
        {
            int child = leftChild(pos);
            // 一个孩子也没有
            if (child >= n)
                break;
            if (child + 1 < n && elem[child + 1] > elem[child])
            {                      // 有两个孩子并有孩子更大
                child = child + 1; // child应为孩子中的大者
            }
            // 孩子都比它小
            if (elem[child] <= v)
                break;
            else
            {
                elem[pos] = elem[child];
            }
            pos = child;
        }
        elem[pos] = v;
    }

public:
    heap() {}
    heap(int m)
    {
        n = m;
        elem = new int[n];
    }
    ~heap()
    {
        delete[] elem;
    }
    void initial()
    {
        for (int i = 0; i < n; i++)
            cin >> elem[i];
    }

    void out()
    {
        for (int i = 0; i < n; i++)
        {
            cout << elem[i];
            if (i <= n - 2)
                cout << " ";
            else
                cout << endl;
        }
    }

    bool isLeaf(int pos) const
    {
        return ((pos >= n / 2) && pos < n);
    }

    int leftChild(int pos)
    {
        return 2 * pos + 1;
    }

    int rightChild(int pos)
    {
        return 2 * pos + 2;
    }

    void arrange()
    {
        for (int i = (n - 1) / 2; i >= 0; i--)
        {
            shiftdown(i);
        }
    }

    void insertElem(int x)
    {
        int *to_del = elem;
        // 重新开辟内存
        int *new_elem = new int[n + 1];
        // 第一个放要插入的元素，保证可以下调
        new_elem[n] = x;
        // 拷贝原来元素
        for (int i = 0; i < n; i++)
        {
            new_elem[i] = elem[i];
        }
        // 修改指针
        elem = new_elem;
        // 修改堆大小
        n++;
        // 删除原来数据
        delete[] to_del;
        // 上调
        int i = n - 1;
        while (i > 0 && elem[(i - 1) / 2] < x)
        {
            elem[i] = elem[(i - 1) / 2];
            i = (i - 1) / 2;
        }
        elem[i] = x;
    }
};

int main()
{
    int m;
    cin >> m;
    heap *ex = new heap(m);
    ex->initial();
    ex->arrange();
    ex->out();
    int insData;
    cin >> insData;
    ex->insertElem(insData);
    ex->out();
    return 0;
}