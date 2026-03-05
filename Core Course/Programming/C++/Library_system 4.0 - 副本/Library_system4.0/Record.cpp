#include "Record.h"

Record::Record(string acc, string act, string title, string isbn) {
    userAccount = acc;
    action = act;
    bookTitle = title;
    bookISBN = isbn;
}

void Record::saveToFile() {
    // 使用追加模式 (ios::app) 打开记录文件
    ofstream file("records.txt", ios::app);
    if (file.is_open()) {
        // 写入格式：账号 动作 书名 ISBN
        file << userAccount << " " 
             << action << " " 
             << bookTitle << " " 
             << bookISBN << endl;
        
        file.close();
        cout << "[系统记录] 日志已保存。" << endl;
    }
}
