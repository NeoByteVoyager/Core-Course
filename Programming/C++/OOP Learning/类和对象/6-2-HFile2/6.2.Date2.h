#ifndef DATE2_H
#define DATE2_H
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
void Date::set(int y, int m, int d) // 类外定义的成员函数
{ year = y; month = m; day = d;
}
bool Date::is_leap_year() // 类外定义的成员函数
{ return (year%4 == 0 && year%100 != 0) || (year%400==0);
}
void Date::print() // 类外定义的成员函数
{ cout<<year<<"."<<month<<"."<<day;
}
#endif
