#ifndef DATE3_H
#define DATE3_H
#include<iostream>
using namespace std;
class Date
{ public:
void set(int y, int m, int d); // 成员函数的声明
bool is_leap_year(); // 成员函数的声明
void print(); // 成员函数的声明
private:
int year,month,day;
};
#endif
