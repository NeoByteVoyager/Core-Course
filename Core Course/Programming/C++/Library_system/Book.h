#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include <string>
using namespace std;

class Book {
private:
	string title;
	string isbn;
	string author;
	string publisher;
	string publishDate;//提供出版排行功能 
	double price;
	int borrowCount;//提供借阅次数前十功能 
public:
	Book(string t,string i,string author,string p,string date,double pr);
	Book(){}
	
	void showInfo() const;
	
	string  getTitle() const;
	string getISBN() const;
	string getAuthor() const;
	string getPublisher() const;
    string getPublishDate() const;
	double getPrice() const;
	int getBorrowCount() const;
	void setBorrowCount(int count); 
	void addBorrowCount(); 
};

#endif

