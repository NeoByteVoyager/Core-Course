#include "Menu.h"

void Menu::showMain() {
    cout << "欢迎来到H大学图书馆管理系统" << endl;
}

void Menu::showAdmin() {
    cout << "===========================" << endl;
    cout << "      管理员操作面板       " << endl;
    cout << "===========================" << endl;
    cout << "1. 读者用户管理" << endl;
    cout << "2. 书籍信息管理" << endl;
    cout << "0. 注销登录 (返回上一级)" << endl;
    cout << "---------------------------" << endl;
    cout << "请输入选项: ";
}

void Menu::showReader() {
    cout << "===========================" << endl;
    cout << "       读者服务中心        " << endl;
    cout << "===========================" << endl;
    cout << "1. 搜索图书" << endl;
    cout << "2. 借阅/归还图书 " << endl;
    cout << "3. 查看排行榜" << endl;
    cout << "0. 注销登录" << endl;
    cout << "---------------------------" << endl;
    cout << "请输入: ";
}
void Menu::adminUserMenu() {
	cout << ">> 管理员 -> 读者用户管理" << endl;
    cout << "1. 添加读者" << endl;
    cout << "2. 删除读者" << endl;
    cout << "3. 查找/查看所有读者" << endl;
    cout << "4. 重置读者密码" << endl;
    cout << "0. 返回上一级" << endl;
    cout << "请输入: ";
}
void Menu::adminBookMenu() {
	cout << ">> 管理员 -> 书籍信息管理" << endl;
    cout << "1. 增加图书" << endl;
    cout << "2. 删除图书" << endl;
    cout << "3. 修改图书 " << endl;
    cout << "4. 浏览所有图书" << endl;
    cout << "0. 返回上一级" << endl;
    cout << "请输入: ";
}
void Menu::RankingMenu(){
	cout << ">> 读者 -> 图书排行榜" << endl;
    cout << "1. 借阅热度榜 (前10名)" << endl;
    cout << "2. 最新新书榜 (前10名)" << endl;
    cout << "0. 返回" << endl;
    cout << "请选择: ";
}
void Menu::readerSerachMenu(){
	cout << ">> 读者 -> 图书搜索" << endl;
    cout << "1. 按书名搜索" << endl;
   	cout << "2. 按ISBN搜索" << endl;
	cout << "3. 按作者搜索" << endl;
	cout << "0. 返回" << endl;
	cout << "请选择: ";
}
void Menu::readerBoReMenu(){
	cout << ">> 读者 -> 借还服务" << endl;
	cout << "1. 借阅图书" << endl;
	cout << "2. 归还图书" << endl;
	cout << "0. 返回" << endl;
	cout << "请选择: ";
}
