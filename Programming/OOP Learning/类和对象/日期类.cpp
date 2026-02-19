#include <iostream>
using namespace std;
class Date
{
public:
    Date()
    {
        year = 0;
        month = 0;
        day = 0;
    }                                                        // 构造函数
    Date(int y, int m, int d) : year(y), month(m), day(d) {} // 全参构造函数
	friend istream &operator>>(istream &input,Date&d);
	friend ostream &operator<<(ostream &os,const Date& d);
	bool operator==(const Date&d)const{
		return year==d.year&&month==d.month&&day==d.day;
	}
private:
    int year;
    int month;
    int day;
};

istream &operator>>(istream &input, Date &d) // 输入运算符重载
{
    input >> d.year >> d.month >> d.day;
    return input;
}
ostream &operator<<(ostream &os,const Date&d){
	os<<d.year<<"/"<<d.month<<"/"<<d.day;
	return os;
}
int main()
{
    Date date1, date2;
    cin >> date1;
    cin >> date2;
    if (date1 == date2)
        cout << date1;
    else
        cout << "NotEqual";
    return 0;
}

