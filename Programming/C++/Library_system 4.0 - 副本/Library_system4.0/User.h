#ifndef USER_H
#define USER_H
#include<iostream>
#include<string>
using namespace std;

class User {
protected:
    string account;  
    string password; 
    int role;        // 1-管理员，2-读者

public:
    User(string acc, string pwd, int r);
    virtual ~User() {} 

    bool checkPassword(string inputPwd);
    string getAccount();
    string getPassword();
    int getRole();
    void setPassword(string newPwd);
};


#endif
