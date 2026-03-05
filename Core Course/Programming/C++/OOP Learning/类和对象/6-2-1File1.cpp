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
