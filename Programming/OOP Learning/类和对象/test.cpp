#include <iostream>
using namespace std;

class A {
    int x;
public:
    A() { cout << "A()\n"; }                     // ? 添加 \n
    A(int a) : x(a) { cout << "A(int a)\n"; }
    A(const A& a) : x(a.x) { cout << "A(const A&)\n"; }
    void display() const { cout << x; }
};

class B : public A {
    int y;
public:
    B(int x1, int y1) : A(x1), y(y1) {}           // ? 初始化列表统一写法
    
    // ? 正确：使用初始化列表同时调用基类拷贝构造和初始化成员
    B(const B& b) : A(b), y(b.y) {}              // ? 删除重复代码
    
    void display() const {
        cout << y << ",";
        A::display();
    }
};

int main() {
    B b1(2, 10);
    B b2(b1);
    b2.display();
    return 0;
}
