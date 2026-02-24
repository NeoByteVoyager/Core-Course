#ifndef MENU_H
#define MENU_H

#include <iostream>
using namespace std;

class Menu {
public:
    static void showMain();   // 登录前的欢迎
    static void showAdmin();  // 管理员主菜单
    static void showReader(); // 读者主菜单
    static void adminUserMenu(); // 二级菜单：管理员读者用户管理 
    static void adminBookMenu();// 二级菜单：管理员书籍用户管理 
    static void RankingMenu();//排行榜菜单 
    static void readerSerachMenu();// 子菜单：读者搜索图书菜单 
    static void readerBoReMenu();//子菜单: 读者借还书菜单 
    // static 表示静态函数，不需要 new 对象就能直接用 Menu::调用
};

#endif
