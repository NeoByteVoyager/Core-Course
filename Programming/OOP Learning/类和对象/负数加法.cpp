#include <iostream>
using namespace std;
// ¸´ÊýÀà
class intMyComplex
{
public:
    intMyComplex(int real, int imag)
    {
        this->real = real;
        this->imag = imag;
    }
    intMyComplex():real(0),imag(0) {}
    friend istream &operator>>(istream &is, intMyComplex &t);
    friend ostream &operator<<(ostream &os, const intMyComplex &t);
    intMyComplex operator+(const intMyComplex &t)
    {
        return intMyComplex(real + t.real, imag + t.imag);
    }

private:
    int real;
    int imag;
};

// ²¹³ä´úÂë
istream &operator>>(istream &is, intMyComplex &t){
	is>>t.real>>t.imag;
	return is;
}
ostream &operator<<(ostream&os,const intMyComplex &t){
	os<<t.real<<'+'<<t.imag<<'i';
	return os;
}

int main()
{
    intMyComplex a, b;
    cin >> a;
    cin >> b;
    b = a + b;
    cout << b;
    return 0;
}

