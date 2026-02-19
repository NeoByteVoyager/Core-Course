#include "Reader.h"
#include "Record.h"

#include <iostream>

Reader::Reader(string acc, string pwd) : User(acc, pwd, 2) {}
// === 借书功能 ===
void Reader::borrowBook(vector<Book>& books) { 
    string inputISBN;
    cout << "\n=== [读者] 借阅图书 ===" << endl;
    cout << "请输入要借阅的ISBN: ";
    cin >> inputISBN;

    bool found = false;
    for (int i = 0; i < books.size(); i++) {
        if (books[i].getISBN() == inputISBN) {
            found = true;
            
            // 1. 增加热度
            books[i].addBorrowCount(); 
            
            // 2. 使用 Record 类保存记录
            Record log(this->getAccount(), "借阅", books[i].getTitle(), books[i].getISBN());
            log.saveToFile();
    
            cout << "借阅成功！" << endl;
            
            
            break;
        }
    }

    if (!found) cout << "未找到该 ISBN 的书籍，无法借阅。" << endl;

    cin.ignore(1024, '\n');
    system("pause");
}

// === 还书功能 ===
void Reader::returnBook(vector<Book>& books) {
    string inputISBN;
    cout << "\n=== [读者] 归还图书 ===" << endl;
    cout << "请输入要归还的ISBN: ";
    cin >> inputISBN;

    bool found = false;
    
    for (int i = 0; i < books.size(); i++) {
        if (books[i].getISBN() == inputISBN) {
            found = true;
            
            Record log(this->getAccount(), "归还", books[i].getTitle(), books[i].getISBN());
            log.saveToFile();
    
            cout << "归还成功！已记录操作。" << endl;
            break;
        }
    }

    if (!found) cout << "馆藏目录中没有这本书，请确认ISBN。" << endl;

    cin.ignore(1024, '\n');
    system("pause");
}
