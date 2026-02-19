#include<iostream>
#include "6.2.Date.h"
using namespace std;
void Date::set(int y, int m, int d) // 类外定义的成员函数
{ year = y; month = m; day = d;
}
bool Date::is_leap_year() // 类外定义的成员函数
{ return (year%4 == 0 && year%100 != 0) || (year%400==0);
}
void Date::print() // 类外定义的成员函数
{ cout<<year<<"."<<month<<"."<<day;
}
