#include "Menu.h"
#include <iostream>
#include <iomanip>

using namespace std;

// 辅助函数：画水平分割线
void printLine(int n) {
    for (int i = 0; i < n; i++) cout << "═";
}

void Menu::showMain() {
    cout << "\n\t╔══════════════════════════════════════╗" << endl;
    cout << "\t║                                      ║" << endl;
    cout << "\t║      欢迎来到H大学图书馆管理系统     ║" << endl;
    cout << "\t║                                      ║" << endl;
   
    cout << "\t║      1. 登录系统                     ║" << endl;
    cout << "\t║      2. 注册新账户                   ║" << endl; 
    cout << "\t║      0. 退出程序                     ║"<< endl;
//    cout << "\t║--------------------------------------║" << endl;
    cout << "\t╚══════════════════════════════════════╝" << endl;
    cout << "请输入选项:"<<endl;
}

void Menu::showAdmin() {
    cout << "\n\t┌──────────────────────────────────────┐" << endl;
    cout << "\t│            管理员操作面板            │" << endl;
    cout << "\t├──────────────────────────────────────┤" << endl;
    cout << "\t│  [1] 读者用户管理                    │" << endl;
    cout << "\t│  [2] 书籍信息管理                    │" << endl;
    cout << "\t│  [0] 注销登录 (返回上一级)           │" << endl;
    cout << "\t└──────────────────────────────────────┘" << endl;
    cout << "\t 请输入选项: ";
}

void Menu::showReader() {
    cout << "\n\t┌──────────────────────────────────────┐" << endl;
    cout << "\t│             读者服务中心             │" << endl;
    cout << "\t├──────────────────────────────────────┤" << endl;
    cout << "\t│  [1] 搜索图书                        │" << endl;
    cout << "\t│  [2] 借阅/归还图书                   │" << endl;
    cout << "\t│  [3] 查看排行榜                      │" << endl;
    cout << "\t│  [0] 注销登录                        │" << endl;
    cout << "\t└──────────────────────────────────────┘" << endl;
    cout << "\t 请输入: ";
}

void Menu::adminUserMenu() {
    cout << "\n\t>> 管理员 -> 读者用户管理" << endl;
    cout << "\t╔══════════════════════════════════════╗" << endl;
    cout << "\t║  (1) 添加读者                        ║" << endl;
    cout << "\t║  (2) 删除读者                        ║" << endl;
    cout << "\t║  (3) 查找/查看所有读者               ║" << endl;
    cout << "\t║  (4) 重置读者密码                    ║" << endl;
    cout << "\t║  (0) 返回上一级                      ║" << endl;
    cout << "\t╚══════════════════════════════════════╝" << endl;
    cout << "\t 请输入: ";
}

void Menu::adminBookMenu() {
    cout << "\n\t>> 管理员 -> 书籍信息管理" << endl;
    cout << "\t╔══════════════════════════════════════╗" << endl;
    cout << "\t║  (1) 增加图书                        ║" << endl;
    cout << "\t║  (2) 删除图书                        ║" << endl;
    cout << "\t║  (3) 修改图书                        ║" << endl;
    cout << "\t║  (4) 浏览所有图书                    ║" << endl;
    cout << "\t║  (0) 返回上一级                      ║" << endl;
    cout << "\t╚══════════════════════════════════════╝" << endl;
    cout << "\t 请输入: ";
}

void Menu::RankingMenu(){
    cout << "\n\t>> 读者 -> 图书排行榜" << endl;
    cout << "\t━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    cout << "\t  1. 借阅热度榜 (前10名)" << endl;
    cout << "\t  2. 最新新书榜 (前10名)" << endl;
    cout << "\t  0. 返回" << endl;
    cout << "\t━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    cout << "\t 请选择: ";
}

void Menu::readerSerachMenu(){
    cout << "\n\t>> 读者 -> 图书搜索" << endl;
    cout << "\t--------------------------------------" << endl;
    cout << "\t  [1] 按书名搜索" << endl;
    cout << "\t  [2] 按ISBN搜索" << endl;
    cout << "\t  [3] 按作者搜索" << endl;
    cout << "\t  [0] 返回" << endl;
    cout << "\t--------------------------------------" << endl;
    cout << "\t 请选择: ";
}

void Menu::readerBoReMenu(){
    cout << "\n\t>> 读者 -> 借还服务" << endl;
    cout << "\t--------------------------------------" << endl;
    cout << "\t  <1> 借阅图书" << endl;
    cout << "\t  <2> 归还图书" << endl;
    cout << "\t  <0> 返回" << endl;
    cout << "\t--------------------------------------" << endl;
    cout << "\t 请选择: ";
}
