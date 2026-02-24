#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 整数版本：返回最少区间数量
int greedyCover(vector<int> points, int k)
{
    if (points.empty() || k <= 0)
    {
        return 0;
    }

    sort(points.begin(), points.end()); // 确保有序

    int count = 1;         // 至少需要一个区间
    int start = points[0]; // 当前区间的起点

    for (size_t i = 1; i < points.size(); ++i)
    {
        // 如果当前点无法被覆盖，需要新区间
        if (points[i] - start > k)
        {
            ++count;
            start = points[i];
        }
    }

    return count;
}

// 测试
int main()
{
    vector<int> points = {1, 3, 5, 7, 9, 11};
    int k = 3;

    int result = greedyCover(points, k);
    cout << "最少需要 " << result << " 个区间" << endl;

    return 0;
}
