#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>      // 添加计时头文件
using namespace std;

int greedyCover(vector<int>& points, int k) {
    if (points.empty() || k <= 0) return 0;
    
    sort(points.begin(), points.end());
    
    int count = 1;
    int start = points[0];
    
    for (size_t i = 1; i < points.size(); ++i) {
        if (points[i] - start > k) {
            ++count;
            start = points[i];
        }
    }
    
    return count;
}

int main() {
    // 开始计时
    clock_t startTime = clock();
    
    ifstream fin("test_large.txt");
    ofstream fout("output.txt");
    
    if (!fin.is_open()) {
        cerr << "无法打开input.txt" << endl;
        return 1;
    }
    
    int n, k;
    fin >> n >> k;
    
    vector<int> points(n);
    for (int i = 0; i < n; ++i) {
        fin >> points[i];
    }
    
    fin.close();
    
    int result = greedyCover(points, k);
    fout << result << endl;
    fout.close();
    
    // 结束计时并显示
    clock_t endTime = clock();
    double duration = double(endTime - startTime) / CLOCKS_PER_SEC;
    
    // 显示结果和用时
    cout<<"数据大小："<<n<<endl; 
    cout << "计算完成！" << endl;
    cout << "最少区间数: " << result << endl;
    cout << "运行时间: " << duration << " 秒" << endl;
    
    return 0;
}
