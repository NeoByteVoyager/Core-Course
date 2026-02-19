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
int main()
{ int y,m,d;
cout << " 请输入年、月、日：";
cin >> y >> m >> d;
Date some_date; // 创建一个 Date 类的对象 some_date
some_date.set(y,m,d); // 设置对象 some_date 的日期值
some_date.print(); // 输出 some_date 所表示的日期
if (some_date.is_leap_year())
cout << " 是闰年 \n";
else
cout << " 不是闰年 \n";
return 0;
}
