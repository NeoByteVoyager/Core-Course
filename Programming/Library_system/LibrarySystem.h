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
    
    //管理员的书籍管理功能 
    void addBook();    // 增：添加图书
    void deleteBook(); // 删：根据ISBN删除图书
    
    //管理员的读者管理功能
	void addReader();          // 增：添加读者
    void deleteReader();       // 删：删除读者
    void viewAllReaders();     // 查：查看所有读者
    void resetReaderPassword();// 改：重置密码 
    
  	//读者搜索功能 
    void searchByTitle();
    void searchByISBN();
    void searchByAuthor();
    
    //读者借还书籍功能
	void borrowBook(); // 借书
    void returnBook(); // 还书 
    
    // 排行榜功能
    void showRanking();
    
	//系统运行入口 
    void run();
	~LibrarySystem(); 
};


#endif
