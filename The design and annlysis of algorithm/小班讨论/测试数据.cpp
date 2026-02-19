#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// 生成单个测试用例
void generateTestCase(const string& filename, int n, int k, bool hasDuplicates = false) {
    ofstream fout(filename);
    fout << n << " " << k << endl;
    
    srand(time(nullptr) + rand());
    int last = 0;
    
    for (int i = 0; i < n; ++i) {
        int point;
        if (hasDuplicates && rand() % 3 == 0) {
            // 30%概率生成重复点
            point = last;
        } else {
            // 生成递增的点
            last += rand() % (k * 2) + 1;
            point = last;
        }
        fout << point << " ";
        
        // 每10个点换行，便于查看
        if ((i + 1) % 10 == 0) fout << endl;
    }
    
    fout.close();
    cout << "生成测试文件: " << filename << " (n=" << n << ", k=" << k << ")" << endl;
}

// 批量生成测试集
void generateTestSuite() {
    system("mkdir -p test_cases");
    
    // 小规模测试
    generateTestCase("test_cases/test_small_1.txt", 7, 3);
    generateTestCase("test_cases/test_small_2.txt", 10, 5, true); // 含重复点
    
    // 中规模测试
    generateTestCase("test_cases/test_medium_1.txt", 100, 20);
    generateTestCase("test_cases/test_medium_2.txt", 1000, 50);
    
    // 大规模测试
    generateTestCase("test_cases/test_large.txt", 100000, 100);
    
    // 边界情况
    generateTestCase("test_cases/test_edge_1.txt", 5, 1);   // k极小
    generateTestCase("test_cases/test_edge_2.txt", 5, 1000); // k极大
    generateTestCase("test_cases/test_edge_3.txt", 0, 10);   // n=0
    
    cout << "\n所有测试用例已生成在 test_cases/ 目录下" << endl;
}

int main() {
    generateTestSuite();
    return 0;
}
