#include <iostream>
#include <fstream>
#include <random>

void generate_with_constraints(const std::string& filename, int count, 
                              int min_val = 1, int max_val = 1000000, 
                              bool unique = false) {
    std::ofstream file(filename);
    
    // 第一行写入数据总数
    file << count << std::endl;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min_val, max_val);
    
    if (unique && count <= (max_val - min_val + 1)) {
        // 生成不重复的随机数
        std::vector<int> numbers;
        for (int i = min_val; i <= max_val && numbers.size() < count; i++) {
            numbers.push_back(i);
        }
        
       
        
        for (int i = 0; i < count; i++) {
            file << numbers[i];
            if (i < count - 1) file << " ";
        }
    } else {
        // 生成普通随机数
        for (int i = 0; i < count; i++) {
            file << dis(gen);
            if (i < count - 1) file << " ";
        }
    }
    
    file.close();
}

int main() {
    // 生成不同约束条件的数据集
    generate_with_constraints("data1.txt", 10, 1, 1000);      // 小范围
    generate_with_constraints("data2.txt", 1e4, -500, 500);    // 包含负数
    generate_with_constraints("data3.txt", 1e6, INT_MIN, INT_MAX); // 不重复数据
    
    std::cout << "所有数据文件生成完成！" << std::endl;
    return 0;
}
