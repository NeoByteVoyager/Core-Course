#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Book.h"
#include <vector>
using namespace std;

class Admin : public User {
public:
    Admin(string acc, string pwd);

    // 管理员的书籍管理功能 
    void addBook(vector<Book>& bookList);
    void deleteBook(vector<Book>& bookList);
    void modifyBook(vector<Book>& bookList); 

    // 管理员的读者管理功能
    void addReader(vector<User*>& users); // 建议参数名统一叫 users
    void deleteReader(vector<User*>& users);
    void resetReaderPassword(vector<User*>& users);
    void viewAllReaders(const vector<User*>& users); 
};

#endif
