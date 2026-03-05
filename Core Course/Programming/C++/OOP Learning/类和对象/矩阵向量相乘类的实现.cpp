#include <bits/stdc++.h>
using namespace std;

class Rational
{
    int fm;

    int fz;

public:
	Rational(){
		fm=1,fz=1;
		
	}
    Rational(int fz, int fm)
    {
        this->fz = fz;
        this->fm = fm;
    } // 构造函数
    Rational(const Rational &r)
    {
        this->fz = r.fz;
        this->fm = r.fm;
    } // 构造函数

    ~Rational() {} // 析构函数
    void show() { cout << fz << "/" << fm << endl; }
};
int main(int argc, char **argv)
{
    Rational r1;
    Rational r2(3, 4);
    r2.fm = 5;
    Rational r3(r2);
    r3.show();
    return 0;
}
