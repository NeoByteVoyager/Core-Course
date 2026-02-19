#include <bits/stdc++.h>
using namespace std;

// 生成随机字符串
string genRandStr(int minLen, int maxLen, char minChar = 'a', char maxChar = 'z', bool allowEmpty = true) {
    int len = allowEmpty ? rand() % (maxLen - minLen + 1) + minLen : rand() % (maxLen - minLen + 1) + minLen + 1;
    string s;
    for (int i = 0; i < len; i++) {
        char c = minChar + rand() % (maxChar - minChar + 1);
        s.push_back(c);
    }
    return s;
}

// 写入文件
void writeTestCase(const string& A, const string& B, int k, const string& sizeLabel, int caseNum) {
    string filename = "input_" + sizeLabel + "_" + to_string(caseNum) + ".txt";
    ofstream outFile(filename);
    outFile << A << endl << B << endl << k << endl;
    outFile.close();
    cout << "? " << filename << " 已生成" << endl;
}

int main() {
    srand(time(0));
    int caseNum = 1;
    
    // ==================== 小规模测试（长度1-10）====================
    cout << "\n【生成小规模测试用例】" << endl;
    caseNum = 1;
    
    // 1.1 边界情况
    writeTestCase("", "", 10, "small", caseNum++);
    writeTestCase("", "a", 5, "small", caseNum++);
    writeTestCase("a", "", 5, "small", caseNum++);
    
    // 1.2 单个字符
    writeTestCase("a", "z", 10, "small", caseNum++);
    writeTestCase("A", "a", 10, "small", caseNum++);
    
    // 1.3 短字符串
    writeTestCase("abc", "abc", 10, "small", caseNum++);
    writeTestCase("cmc", "snmn", 10, "small", caseNum++);
    writeTestCase("hello", "world", 15, "small", caseNum++);
    writeTestCase("算法", "算数", 10, "small", caseNum++);
    
    // 1.4 随机生成5个
    for (int i = 0; i < 5; i++) {
        string A = genRandStr(1, 10);
        string B = genRandStr(1, 10);
        int k = 1 + rand() % 20;
        writeTestCase(A, B, k, "small", caseNum++);
    }
    
    
    // ==================== 中规模测试（长度10-100）====================
    cout << "\n【生成中规模测试用例】" << endl;
    caseNum = 1;
    
    // 2.1 中等长度
    writeTestCase("algorithm", "altruistic", 10, "medium", caseNum++);
    writeTestCase("dynamicprogramming", "divideandconquer", 15, "medium", caseNum++);
    
    // 2.2 同长度不同字符
    string s1(30, 'a'), s2(30, 'b');
    writeTestCase(s1, s2, 10, "medium", caseNum++);
    
    // 2.3 包含大小写和数字
    writeTestCase("HelloWorld2024", "helloWORLD2023", 12, "medium", caseNum++);
    
    // 2.4 随机生成8个
    for (int i = 0; i < 8; i++) {
        string A = genRandStr(10, 100, 'a', 'z', false);
        string B = genRandStr(10, 100, 'A', 'Z', false);
        int k = 5 + rand() % 30;
        writeTestCase(A, B, k, "medium", caseNum++);
    }
    
    
    // ==================== 大规模测试（长度100-1000）====================
    cout << "\n【生成大规模测试用例】" << endl;
    caseNum = 1;
    
    // 3.1 长字符串
    string longA = genRandStr(500, 500, 'a', 'z', false);
    string longB = genRandStr(500, 500, 'a', 'z', false);
    writeTestCase(longA, longB, 10, "large", caseNum++);
    
    // 3.2 极端差异
    string veryLong(5000, 'a');
    string veryShort(100, 'z');
    writeTestCase(veryLong, veryShort, 20, "large", caseNum++);
    
    // 3.3 随机生成5个
    for (int i = 0; i < 5; i++) {
        string A = genRandStr(100, 5000, 'a', 'z', false);
        string B = genRandStr(200, 5000, 'a', 'z', false);
        int k = 10 + rand() % 40;
        writeTestCase(A, B, k, "large", caseNum++);
    }
    
    cout << "\n=============== 生成完成！ ===============" << endl;
    cout << "小规模：" << caseNum - 1 << " 个文件 (input_small_*.txt)" << endl;
    cout << "中规模：8 个文件 (input_medium_*.txt)" << endl;
    cout << "大规模：5 个文件 (input_large_*.txt)" << endl;
    
    return 0;
}
