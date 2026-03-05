class Date
{ public: // 访问控制
void set(int y, int m, int d); // 成员函数
bool is_leap_year(); // 成员函数
void print(); // 成员函数

private: // 访问控制
int year,month,day; // 数据成员
};
