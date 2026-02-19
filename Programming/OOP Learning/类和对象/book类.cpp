#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//请在此处补充完整Book类的声明
class Book{
public:
Book();
void setInfo(){
getline(cin,shelf_id);
cin>>price;
cin.ignore();
}
void show(){
cout<<"Shelf_ID: "<<setw(18)<<left<<shelf_id;
cout<<"Price: "<<price<<endl;
}


    private:
        float price;
        string shelf_id;
};
 //Book类声明完成
 Book::Book()
 {
     price = 0;
     shelf_id = "";
 }



 int main()
 {
     int n;
     cin >> n;   //从键盘输入整数n
     cin.get();  //吸收整数输入后的回车
    Book *library = new Book[n];   //声明对象数组
     for(int i=0;i<n;i++)
     {
         library[i].setInfo();  //从键盘输入对象数组的每个元素
    }
     for(int i=0;i<n;i++)
     {
         library[i].show();  //输出对象数组
    }
     return 0;
 }

