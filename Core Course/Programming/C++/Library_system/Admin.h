#ifndef ADMIN_H
#define ADMIN_H
#include "User.h"
class Admin:public User{
public:
	Admin(string acc,string pwd):User(acc,pwd,1){}
	
	//管理员特有功能 fds 
	
};

#endif 
