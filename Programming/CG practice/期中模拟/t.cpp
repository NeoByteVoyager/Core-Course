// cpp_pointer_examples_detailed.cpp
// C++ 指针操作详细示例
// 编译：g++ -std=c++17 cpp_pointer_examples_detailed.cpp -o pointer_demo_detailed

#include <iostream>
using namespace std;

void line() { cout << "--------------------------------------------\n"; }

// ---------- 1. 基本指针 ----------
void example_basic_pointer() {
    line();
    cout << "示例：基本指针\n";
    int x = 10;             // 普通变量
    int *p = &x;            // 指针指向 x 的地址
    cout << "x = " << x << ", &x = " << &x << ", p = " << p << ", *p = " << *p << '\n';

    *p = 20;                // 通过指针修改变量值
    cout << "修改 *p 后 x = " << x << '\n';

    cout << "指针大小 sizeof(p) = " << sizeof(p) << " 字节\n";
}

// ---------- 2. 指针数组 ----------
void example_pointer_array() {
    line();
    cout << "示例：指针数组\n";
    int a[3] = {1,2,3};     // 普通数组
    int* p[3];              // 指针数组
    for (int i = 0; i < 3; i++) {
        p[i] = &a[i];       // 每个指针指向数组元素
    }
    for (int i = 0; i < 3; i++) {
        cout << "*p[" << i << "] = " << *p[i] << ', ';  // 通过指针访问
    }
    cout << '\n';
}

// ---------- 3. 指针与函数 ----------
void swap_by_pointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void example_pointer_function() {
    line();
    cout << "示例：指针作为函数参数\n";
    int x = 5, y = 10;
    cout << "交换前 x = " << x << ", y = " << y << '\n';
    swap_by_pointer(&x, &y);  // 传入变量地址
    cout << "交换后 x = " << x << ", y = " << y << '\n';
}

// ---------- 4. 指向指针的指针 ----------
void example_pointer_to_pointer() {
    line();
    cout << "示例：指向指针的指针\n";
    int x = 30;
    int *p = &x;       // 一层指针
    int **pp = &p;     // 二层指针

    cout << "x = " << x << ", *p = " << *p << ", **pp = " << **pp << '\n';
    **pp = 50;         // 修改 x 的值
    cout << "修改后 x = " << x << '\n';
}

// ---------- 5. 动态内存 ----------
void example_dynamic_memory() {
    line();
    cout << "示例：动态内存\n";
    int *p = new int(100);        // 分配单个整数
    cout << "*p = " << *p << '\n';

    delete p;                     // 释放内存
    p = nullptr;                  // 避免悬空指针

    int n = 5;
    int *arr = new int[n];        // 分配数组
    for (int i = 0; i < n; i++) arr[i] = i * 10;
    cout << "动态数组元素：";
    for (int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << '\n';
    delete[] arr;                 // 释放数组内存
    arr = nullptr;
}

// ---------- 6. 指针与数组 ----------
void example_pointer_and_array() {
    line();
    cout << "示例：指针与数组\n";
    int arr[4] = {10,20,30,40};
    int *p = arr;                 // 数组名即指向首元素的指针
    cout << "通过指针访问数组：";
    for (int i = 0; i < 4; i++) cout << *(p + i) << ' ';  // 指针偏移
    cout << '\n';
}

// ---------- 7. 指针与字符串 ----------
void example_pointer_and_string() {
    line();
    cout << "示例：指针与字符串\n";
    char str[] = "Hello";
    char *p = str;                // 指向首字符
    cout << "字符串内容：";
    while (*p != '\0') {
        cout << *p << ' ';
        p++;
    }
    cout << '\n';
}

int main() {
    example_basic_pointer();
    example_pointer_array();
    example_pointer_function();
    example_pointer_to_pointer();
    example_dynamic_memory();
    example_pointer_and_array();
    example_pointer_and_string();
    return 0;
}
