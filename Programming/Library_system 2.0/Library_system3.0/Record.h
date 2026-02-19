#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Record {
private:
    string userAccount; // 谁借的
    string action;      // 动作："借阅" 或 "归还"
    string bookTitle;   // 书名
    string bookISBN;    // ISBN

public:
    Record(string acc, string act, string title, string isbn);
    
    // 核心功能：把自己这条记录写进文件
    void saveToFile();
};

#endif
