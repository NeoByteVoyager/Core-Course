#include <iostream>
using namespace std;

template <class T>
class A {
    T x;
public:
    A(T val) : x(val) {}

    // 友元函数模板
    template <class U>
    friend void f(A<U>& a);
};

// 函数模板定义
template <class U>
void f(A<U>& a) {
    cout << "f(A<U>) called, x = " << a.x << endl;
}

int main() {
    A<int> a1(10);
    A<double> a2(3.14);
    A<char*> a3((char*)"hello");

    f(a1); // 调用 f(A<int>&)
    f(a2); // 调用 f(A<double>&)
    f(a3); // 调用 f(A<char*>&) 成功！

    return 0;
}

