#ifndef DATE1_H
#define DATE1_H
#include<iostream>
using namespace std;
class Date
{ public:
void set(int y, int m, int d){ year = y; month = m; day = d;
}; // 成员函数的实现 
bool is_leap_year(){ return (year%4 == 0 && year%100 != 0) || (year%400==0);
}; // 成员函数的实现 
void print(){ cout<<year<<"."<<month<<"."<<day;
}; // 成员函数的实现 
private:
int year,month,day;
};
#endif
