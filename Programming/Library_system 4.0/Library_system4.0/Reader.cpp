#include "Reader.h"
#include "Record.h"
#include <iostream>

Reader::Reader(string acc, string pwd) : User(acc, pwd, 2) {}

// === 借书功能 (支持 ISBN 或 书名) ===
void Reader::borrowBook(vector<Book>& books) { 
    string inputInfo; 
    cout << "\n=== [读者] 借阅图书 ===" << endl;
    cout << "请输入要借阅书籍的 ISBN 或 书名: ";
    cin >> inputInfo;

    bool found = false;
    
    // 遍历所有书籍
    for (int i = 0; i < books.size(); i++) {
        if (books[i].getISBN() == inputInfo || books[i].getTitle() == inputInfo) {
            found = true;
            
            // 1. 增加热度
            books[i].addBorrowCount(); 
            
            // 2. 使用 Record 类保存记录
            Record log(this->getAccount(), "借阅", books[i].getTitle(), books[i].getISBN());
            log.saveToFile();
    
            cout << "借阅成功！" << endl;
            cout << "您借阅了: 《" << books[i].getTitle() << "》" << endl;
            
            break; 
        }
    }

    if (!found) cout << "未找到该 ISBN 或书名的书籍，无法借阅。" << endl;

    cin.ignore(1024, '\n');
    system("pause");
}

// === 还书功能 (支持 ISBN 或 书名) ===
void Reader::returnBook(vector<Book>& books) {
    string inputInfo;
    cout << "\n=== [读者] 归还图书 ===" << endl;
    cout << "请输入要归还书籍的 ISBN 或 书名: ";
    cin >> inputInfo;

    bool found = false;
    
    for (int i = 0; i < books.size(); i++) {
        if (books[i].getISBN() == inputInfo || books[i].getTitle() == inputInfo) {
            found = true;
            
            Record log(this->getAccount(), "归还", books[i].getTitle(), books[i].getISBN());
            log.saveToFile();
    
            cout << "归还成功！已记录操作。" << endl;
            cout << "您归还了: 《" << books[i].getTitle() << "》" << endl;
            break;
        }
    }

    if (!found) cout << "馆藏目录中没有这本书，请确认信息。" << endl;

    cin.ignore(1024, '\n');
    system("pause");
}
