#include <bits/stdc++.h>
using namespace std;
vector<int> a = {1, 4, 3, 5, 9, 5, 4, 5, 3, 4};
class HeapSort
{
private:
    vector<int> data;
    int n;

public:
    HeapSort(const vector<int> &a)
    {
        // bug1：下标问题
        n = a.size();
        data.resize(n + 1);
        for (int i = 1; i <= n; i++)
            data[i] = a[i - 1];
        build();
        // sort();
    }
    void build()
    {
        for (int i = n / 2; i >= 1; i--)
        {
            shiftDown(i);
        }
    }
    void shiftDown(int idx)
    {
        int t = data[idx];
        int i = idx;
        while (true)
        {
            int child = 2 * i;
            if (child > n)
                break;
            if (child + 1 <= n && data[child + 1] > data[child])
                child = child + 1;
            if (data[child] <= t)
                break;
            data[i] = data[child];
            i = child;
        }
        data[i] = t; // 最后赋值
    }
    void shiftUp(int idx)
    {
        int t = data[idx];
        int i = idx;
        while (i >= 1 && t > data[i / 2])
        {
            data[i] = data[i / 2];
            i = i / 2; // bug2:死循环
        }
        data[i] = t;
    }
    void sort()
    {
        int loop = n;
        while (loop > 1)
        {
            swap(data[1], data[n]); // bug3:错误的交换了全局a
            n--;
            shiftDown(1);
            loop--; // bug：死循环
        }
        cout << "排序完成后的数据:\n";
        for (int i = 1; i < data.size(); i++)
        {
            int v = data[i];
            cout << v << " ";
        }
    }
};
int main()
{
    HeapSort h = HeapSort(a);
    h.sort();
    return 0;
}