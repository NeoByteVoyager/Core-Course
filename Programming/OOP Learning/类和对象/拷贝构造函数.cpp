#include<bits/stdc++.h>
using namespace std;

class String {
private:
    char* data;
public:
    // 构造函数
    String(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }
    
    // ? 自定义拷贝构造函数（深拷贝）
    String(const String& other) {
        data = new char[strlen(other.data) + 1];  // 重新分配内存
        strcpy(data, other.data);                 // 复制内容
        cout << "深拷贝完成！" << endl;
    }
    
    ~String() {
        delete[] data;
    }
};

int main() {
    String s1("hello");
    String s2 = s1;  // ? 调用自定义拷贝构造，s2有独立的内存
    
    // s1和s2完全独立，安全释放
    return 0;
}
