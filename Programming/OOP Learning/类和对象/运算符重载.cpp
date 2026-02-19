//有理数类的定义与实现，运算符重载 
#include <iostream>
using namespace std;

//类的定义
class Rational {
    private:
        int fz;
        int fm;
    public:
        
        ~Rational();//析构函数的原型声明
        Rational(); //无参构造函数声明
        Rational(int, int); //全参构造函数声明，形参列表和数据成员列表完全相同
        Rational(const Rational &); //复制构造函数声明，以该类型的常引用为形参
      // 重载输入运算符>>
    
friend istream& operator>>(istream &is,Rational &r);

 
    // 重载输出运算符<< 
  
friend ostream& operator<<(ostream &os,const Rational &r);

    // 重载乘法运算符 * 
   
Rational operator*(const Rational&r)const{
return Rational(fz*r.fz,fm*r.fm);
};

};

istream& operator>>(istream& is, Rational& r) {
    char slash;
    is >> r.fz >> slash >> r.fm;
    return is;
}

ostream& operator<<(ostream& os, const Rational& r) {
    os << r.fz << '/' << r.fm;
    return os;
}


Rational::~Rational() { //功能：释放资源
    cout << "Destructor called. \n";
}

Rational::Rational() { //功能：初始化数据成员
    fz = 0;
    fm = 1;
}

Rational::Rational(int x, int y) { //功能：初始化数据成员
    fz = x;
    fm = y;
}

Rational::Rational(const Rational &r) { //功能：初始化数据成员
    fz = r.fz;
    fm = r.fm;
}

//创建对象，测试功能
int main() {

    Rational a; //调用无参构造函数
    cin>>a;
    cout << "a = "<<a<<endl;

    Rational b(3, 5); //调用全参构造函数
    cout << "b = "<<b<<endl;
    Rational c(a); //调用复制构造函数
    cout << "c = "<<c<<endl;


    c=a*b; //乘法运算 
    cout << "c = a * b = "<<c<<endl;
    
    return 0;
}
