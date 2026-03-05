#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

class Book{
    private:
        float price;
        string shelf_id;
                int id;
       public:
                static int Num; //Num为类的静态成员
                Book();
                friend ostream& operator<<(ostream&,const Book&);
                friend istream& operator>>(istream&,Book&);
       //请在此处补充完整的Book类声明
       
friend bool comp(const Book&,const Book&);

};
 int Book::Num = 0;//静态成员初始化
 Book::Book()
 {
     price = 0;
     shelf_id = "";
         
Num++;
id=Num;
 //利用静态成员来保证id自增
 }
//请在此处补充相应的函数定义
istream& operator>>(istream &is,Book&b){
getline(is,b.shelf_id);
is>>b.price;
is.ignore();
return is;
}
ostream&operator<<(ostream&os,const Book&b){
os<<"ID: "<<b.id<<"Shelf_ID: "<<setw(18)<<b.shelf_id<<"Price: "<<b.price;
return os;
}

bool comp(const Book& book1, const Book& book2) //请补充comp函数的定义体，按照题面规则实现按价格降序排列
{
if(book1.price!=book2.price) return book1.price>book2.price;
return book1.id<book2.id;

}
 int main()
 {
     int n;
     cin >> n;   //从键盘输入整数n
     cin.get();  //吸收整数输入后的回车
    Book *library = new Book[n];   //声明对象数组
     for(int i=0;i<n;i++)
     {
         cin >> library[i];  //从键盘输入对象数组的每个元素
    }
       sort(
library
 , 
library+n
 , comp);
     for(int i=0;i<n;i++)
     {
         cout << library[i] << endl;  //输出单个对象数组元素，并回车
    }
     return 0;
 }

