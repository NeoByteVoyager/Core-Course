#include<iostream>
#include<string.h>
using namespace std; 
class MyString {
private:
    char* data;
    size_t len;
    
public:
    // 1. 默认构造函数：创建空字符串
    MyString();
    
    // 2. 从C字符串构造
    MyString(const char* str);
    
    // 3. 拷贝构造函数（深拷贝）
    MyString(const MyString& other);
    
    // 4. 赋值运算符（处理自赋值、深拷贝）
    MyString& operator=(const MyString& other);
    
    // 5. 析构函数（释放内存）
    ~MyString();
    
    // 6. 字符串拼接（strcat功能）
    MyString operator+(const MyString& other) const;
    
    // 7. 获取长度
    size_t length() const;
    
    // 8. 获取C风格字符串
    const char* c_str() const;
};
MyString::MyString():data(NULL),len(0){}
MyString::MyString(const char *str){
	if(str==NULL)return;
	len=strlen(str);
	data=new char[len+1];
	strcpy(data,str);
}
MyString::MyString(const MyString &other){
	len=strlen(other.data);
	data=new char[len+1];
	strcpy(data,other.data);
}
MyString& MyString::operator=(const MyString&other){
	len=strlen(other.data);
	data=new char[len+1];
	strcpy(data,other.data);
	return *this;
}
MyString::~MyString (){
	delete [] data;
}
MyString MyString::operator+(const MyString&other)const {
	char *ptr=new char[strlen(data)+strlen(other.data)+1];
	strcpy(ptr,data);
	strcat(ptr,other.data);
	return MyString(ptr);
}
size_t MyString::length()const{
	return len;
}
const char* MyString::c_str()const{
	return data;
}
int main() {
    MyString s1("df");                    // data=NULL
	cout<<s1.c_str();
	MyString s2("Fdas");
	MyString s3=s1+s2;
	cout<<s3.c_str();
}
