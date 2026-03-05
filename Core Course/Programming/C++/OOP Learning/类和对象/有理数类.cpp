#include<bits/stdc++.h>
using namespace std; 
class Rational{
private:
//数据成员声明：分子,分母；
     int fm;
     int fz;
public:
    Rational(int fz,int fm);//构造函数 
    Rational(const Rational&); 
    Rational(); 
    ~Rational();//析构函数 
    void show();
};
Rational::Rational(int fz,int fm)
{
    this->fm=fm;
    this->fz=fz;
    cout<<"Rational(int fz,int fm)"<<endl;
}
Rational::Rational(const Rational& r)
{
    fz=r.fz;
    fm=r.fm;
    cout<<"Rational(const Rational& r)"<<endl;
}
Rational::Rational()
{
    fz=0;
    fm=1;
    cout<<"Rational()"<<endl;
}
Rational::~Rational()
{
    cout<<"~Rational()"<<endl;   
    cout<<fz<<"/"<<fm<<endl; 
}
void Rational::show()
{
    cout<<fz<<"/"<<fm<<endl; 
}
int main(int argc, char** argv) {
    Rational r(3,4);
    Rational r1;
    Rational r2(r);
    Rational  *arr=new Rational[3];
    delete[] arr; 
    return 0;

}
