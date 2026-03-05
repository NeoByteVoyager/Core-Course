#include<iostream>
#include "6.2.Date2.h"

using namespace std;
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
