#include "Admin.h"
#include "Reader.h" 

#include <iostream>

Admin::Admin(string acc, string pwd) : User(acc, pwd, 1) {}
// === 1. 添加图书 ===
void Admin::addBook(vector<Book>& bookList) {
    string t, i, a, p, d;
    double pr;
    
    cout << "\n=== 录入新书 ===" << endl;
    cout << "请输入书名 (不要带空格): ";
    cin >> t;
    cout << "请输入ISBN: ";
    cin >> i;
    
    // 检查ISBN是否重复
    for(int k=0; k<bookList.size(); k++) {
        if(bookList[k].getISBN() == i) {
            cout << "错误：该ISBN已存在！" << endl;
            cin.ignore(1024, '\n'); 
            system("pause");
            return;
        }
    }

    cout << "请输入作者: "; cin >> a;
    cout << "请输入出版社: "; cin >> p;
    cout << "请输入出版日期 (如 2024-01): "; cin >> d;
    cout << "请输入价格: "; cin >> pr;

    // 重置并清空缓冲区
    if (!cin) { 
        cin.clear(); 
    }
    cin.ignore(1024, '\n'); 

    // 创建对象并加入列表
    Book b(t, i, a, p, d, pr);
    bookList.push_back(b);
    
    cout << "书籍录入成功！" << endl;
    system("pause");
}

// === 2. 删除图书 ===
void Admin::deleteBook(vector<Book>& bookList) {
    string inputISBN;
    cout << "\n=== 删除图书 ===" << endl;
    cout << "请输入要删除的ISBN: ";
    cin >> inputISBN;
    cin.ignore(1024, '\n'); 

    for (int i = 0; i < bookList.size(); i++) {
        if (bookList[i].getISBN() == inputISBN) {
            cout << "找到书籍: " << bookList[i].getTitle() << endl;
            cout << "确认删除吗? (y/n): ";
            char confirm;
            cin >> confirm;
            cin.ignore(1024, '\n'); // 吃掉回车
            
            if (confirm == 'y' || confirm == 'Y') {
                bookList.erase(bookList.begin() + i);
                cout << "删除成功！" << endl;
            } else {
                cout << "已取消操作。" << endl;
            }
            system("pause");
            return; 
        }
    }
    cout << "未找到ISBN为 " << inputISBN << " 的书籍。" << endl;
    system("pause");
}

// === 3. 修改图书 ===
void Admin::modifyBook(vector<Book>& bookList) {
    string inputISBN;
    cout << "\n=== 修改图书信息 ===" << endl;
    cout << "请输入要修改的图书ISBN: ";
    cin >> inputISBN;
    cin.ignore(1024, '\n');

    int index = -1;
    for (int i = 0; i < bookList.size(); i++) {
        if (bookList[i].getISBN() == inputISBN) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "未找到ISBN为 " << inputISBN << " 的书籍。" << endl;
        system("pause");
        return;
    }

    while (true) {
        system("cls");
        cout << "=== 当前书籍信息 ===" << endl;
        bookList[index].showInfo();
        
        cout << "\n请选择要修改的内容:" << endl;
        cout << "1. 修改书名" << endl;
        cout << "2. 修改作者" << endl;
        cout << "3. 修改出版社" << endl;
        cout << "4. 修改出版日期" << endl;
        cout << "5. 修改价格" << endl;
        cout << "0. 修改完成，退出" << endl;
        cout << "-----------------------" << endl;
        cout << "请输入选项: ";
        
        int choice;
        if (!(cin >> choice)) {
            cin.clear(); cin.ignore(1024, '\n'); choice = -1;
        } else {
            cin.ignore(1024, '\n');
        }

        string tempStr;
        double tempPrice;

        switch (choice) {
            case 1:
                cout << "请输入新书名: "; cin >> tempStr;
                bookList[index].setTitle(tempStr);
                break;
            case 2:
                cout << "请输入新作者: "; cin >> tempStr;
                bookList[index].setAuthor(tempStr);
                break;
            case 3:
                cout << "请输入新出版社: "; cin >> tempStr;
                bookList[index].setPublisher(tempStr);
                break;
            case 4:
                cout << "请输入新出版日期: "; cin >> tempStr;
                bookList[index].setPublishDate(tempStr);
                break;
            case 5:
                cout << "请输入新价格: "; cin >> tempPrice;
                if(cin) bookList[index].setPrice(tempPrice);
                else { cin.clear(); cin.ignore(1024, '\n'); }
                break;
            case 0:
                return; 
            default:
                cout << "无效选项。" << endl;
        }
        if (choice != 0) cout << ">>> 更新成功！" << endl;
    }
}


// === 4. 添加读者 ===
void Admin::addReader(vector<User*>& users) { 
    string acc, pwd;
    cout << "\n=== 添加读者 ===" << endl;
    cout << "请输入新账号: ";
    cin >> acc;
    
    for(int i=0; i < users.size(); i++) {
        if(users[i]->getAccount() == acc) {
            cout << "错误：该账号已存在！" << endl;
            system("pause");
            return;
        }
    }

    cout << "请输入初始密码: ";
    cin >> pwd;
    cin.ignore(1024, '\n');
    
    users.push_back(new Reader(acc, pwd));
    cout << "读者添加成功！" << endl;
    system("pause");
}

// === 5. 删除读者 ===
void Admin::deleteReader(vector<User*>& users) {
    string acc;
    cout << "\n=== 删除读者 ===" << endl;
    cout << "请输入要删除的读者账号: ";
    cin >> acc;
    cin.ignore(1024, '\n');


    for (int i = 0; i < users.size(); i++) {
        if (users[i]->getRole() == 2 && users[i]->getAccount() == acc) {
            delete users[i]; 
            users.erase(users.begin() + i); 
            cout << "删除成功！" << endl;
            system("pause");
            return;
        }
    }
    cout << "未找到该读者账号。" << endl;
    system("pause");
}

// === 6. 查看所有读者 ===
void Admin::viewAllReaders(const vector<User*>& users) {
    cout << "\n=== 读者列表 ===" << endl;
    cout << "账号\t\t密码(仅展示)" << endl;
    cout << "----------------------" << endl;
    int count = 0;

    for (int i = 0; i < users.size(); i++) {
        if (users[i]->getRole() == 2) {
            cout << users[i]->getAccount() << "\t\t" << users[i]->getPassword() << endl;
            count++;
        }
    }
    cout << "----------------------" << endl;
    cout << "共找到 " << count << " 位读者。" << endl;
    system("pause");
}

// === 7. 重置密码 ===
void Admin::resetReaderPassword(vector<User*>& users) {
    string acc;
    cout << "\n=== 重置密码 ===" << endl;
    cout << "请输入要重置的读者账号: ";
    cin >> acc;
    cin.ignore(1024, '\n');


    for (int i = 0; i < users.size(); i++) {
        if (users[i]->getRole() == 2 && users[i]->getAccount() == acc) {
            users[i]->setPassword("123456");
            cout << "密码已重置为 123456 ！" << endl;
            system("pause");
            return;
        }
    }
    cout << "未找到该读者账号。" << endl;
    system("pause");
}
