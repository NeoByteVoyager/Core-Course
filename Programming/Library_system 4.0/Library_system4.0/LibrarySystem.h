#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H

#include<iostream> 
#include<vector>
#include <fstream>
#include <algorithm>
#include "Book.h" 
#include "User.h"
#include "Admin.h"
#include "Reader.h"
#include "Record.h"
#include "Menu.h"
#include "RankList.h" 
class LibrarySystem{
private:
	vector<Book>bookList;
	vector<User*>userList;
	User*currentUser;
	//以外部文件的形式存储书籍信息、用户信息 
	void saveData(); 
    void loadData();
public:
	//系统运行入口 
	LibrarySystem();
	
	//用户管理与登录功能
	void initUsers();//初始化用户
	bool login();//登录验证 
	
	//各种菜单函数
	void adminMenu(); //管理员总菜单
	void adminUserMenu();//管理员-用户管理菜单
	void adminBookMenu();//管理员-书籍菜单
	void readerMenu();//读者总菜单 
	
	//书籍辅助功能 
    void addTestBook();
    void showAllBooks();
    
    
  	//搜索功能 
    void searchByTitle();
    void searchByISBN();
    void searchByAuthor();
    
    
    // 排行榜功能
    void showRanking();
    
	//系统运行入口 
    void run();
	~LibrarySystem(); 
};


#endif
