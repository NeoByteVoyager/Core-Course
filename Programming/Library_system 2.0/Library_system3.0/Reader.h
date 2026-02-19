#ifndef READER_H
#define READER_H

#include "User.h"
#include <vector>
#include "Book.h" 

class Reader : public User {
public:
    Reader(string acc, string pwd);

    // 读者特有的功能
    void borrowBook(vector<Book>& books);
    void returnBook(vector<Book>& books);
}; 

#endif
