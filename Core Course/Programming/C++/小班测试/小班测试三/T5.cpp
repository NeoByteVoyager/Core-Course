#include <iostream>
#include <string.h>
using namespace std;
#define  size_t int

class MyString{
    private:
           char * p_str;
           size_t strLength;
    public:
          MyString();
          MyString(const MyString&);
          MyString(const char*);
          MyString(const size_t,const char);
          ~MyString();
          /*声明输出字符串的友元函数*/
		friend ostream& operator<<(ostream&os,const MyString& s);
          /*声明赋值运算符重载函数*/ 
     	MyString& operator=(const MyString &s);

          void setStr(const char*);
          char* getStr();  
};

MyString::MyString() : p_str(NULL) , strLength(0)
{}

MyString::MyString(const char* str)
{
    if(str==NULL)      {    return;  }
    strLength=strlen(str);
    p_str = new char[strLength+1];
    strcpy(p_str,str);
}

//深度拷贝构造函数 
MyString::MyString(const MyString&s){
	if(s.p_str==NULL){
		p_str=NULL;
		strLength=0;
		return ;
	}
	strLength=strlen(s.p_str);
	p_str=new char[strLength+1];
	strcpy(p_str,s.p_str);
}
MyString::MyString(const size_t len,const char c) 
{ 
    this->strLength=len;
    this->p_str = new char[len+1];
    int i=0;
    for(;i<len;i++)
    {
        this->p_str[i]=c;
    }
    this->p_str[i]='\0';
}
MyString::~MyString()
{
    delete []p_str;
}
/*输出运算符重载*/
ostream& operator<<(ostream&os,const MyString& s){
			os<<s.p_str;
			return os;
}
/*赋值运算符重载*/
MyString& MyString::operator=(const MyString &s){
     	if(s.p_str==NULL){
     		p_str=NULL;
     		strLength=0;
     		return *this;
		 } 
		 int len=strlen(s.p_str);
		 p_str=new char[len+1];
		 strcpy(p_str,s.p_str);
}
void MyString::setStr(const char* str)
{
    if(p_str!=NULL)
    {
        delete []p_str;
    }
    this->strLength=strlen(str);
    this->p_str = new char[strLength+1];
    strcpy( this->p_str , str);    
}
char* MyString::getStr()
{
    return p_str;
}  
int main(){
    MyString s1;
    s1.setStr("hello");
    cout<<s1<<endl;
    MyString s2(s1);
    cout<<s2<<endl;
    MyString s3=s1;
    cout<<s3<<endl;
    s1.setStr("world");
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;    
}
