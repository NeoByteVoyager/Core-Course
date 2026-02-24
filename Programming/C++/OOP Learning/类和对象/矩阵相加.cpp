#include <iostream>
using namespace std;
class Matrix
{
public:
    Matrix() {}
    Matrix(int a[][3])
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                this->mat[i][j]=a[i][j] ;
            }
        }
    }
    friend istream& operator>>(istream &is,Matrix& t);
    friend ostream& operator<<(ostream &os,const Matrix& t); 
	Matrix operator+(const Matrix t)const{
		int a[2][3];
		for(int i=0;i<2;i++){
			for(int j=0;j<3;j++){
				a[i][j]=mat[i][j]+t.mat[i][j];
			}
		}
		return Matrix(a);
	}
private:
    int mat[2][3];
};
istream& operator>>(istream &is,Matrix &t){
	 for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                is>>t.mat[i][j] ;
            }
        }
}
 ostream& operator<<(ostream &os,const Matrix &t){
	 for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                os<<t.mat[i][j]<<" ";
            }
            os<<"\n";
        }
}
int main()
{
    Matrix a, b, c;
    cin >> a >> b;
    c = a + b;
    cout << c;
    return 0;
}
