#include <iostream>
#include <string>
using namespace std;

// 成员对象类
class Member {
private:
    string name;
public:
    Member(string n) : name(n) {
        cout << "【构造】Member对象: " << name << endl;
    }
    
    ~Member() {
        cout << "【析构】Member对象: " << name << endl;
    }
};

// 包含多个成员对象的容器类
class Container {
private:
    // 按顺序声明三个成员对象
    Member member1;
    Member member2;
    Member member3;
public:
    // 构造函数：通过初始化列表构造成员对象
    Container() : member1("member1"), member2("member2"), member3("member3") {
        cout << "【构造】Container对象本身" << endl;
    }
    
    ~Container() {
        cout << "【析构】Container对象本身" << endl;
    }
};

int main() {
    cout << "========== 开始创建Container对象 ==========" << endl;
    Container* obj = new Container();  // 动态创建
    
    cout << "\n========== 开始销毁Container对象 ==========" << endl;
    delete obj;  // 手动删除，触发析构
    
    cout << "\n========== 程序结束 ==========" << endl;
    return 0;
}
