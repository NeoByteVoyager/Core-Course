#include "Book.h"
Book::Book(string t,string i,string a,string p,string date,double pr){
	title=t;
	isbn=i;
	author=a; 
	publisher = p;
	publishDate=date; 
    price = pr;
    borrowCount = 0; 
}

	
void Book::showInfo() const {
	cout << "--------------------------------" << endl;
    cout << "书名:   " << title << endl;
    cout << "ISBN:   " << isbn << endl;
    cout << "作者:   " << author << endl;
    cout << "出版社: " << publisher << endl;
    cout << "出版日期: " << publishDate << endl;
    cout << "价格:   " << price << " 元" << endl;
    cout << "--------------------------------" << endl;
}

string Book::getTitle() const {
    return title;
}

string Book::getISBN() const {
    return isbn;
}

string Book::getAuthor() const {
    return author;
}

int Book::getBorrowCount() const {
    return borrowCount;
}
string Book::getPublisher() const {
	return publisher; 
}
string Book::getPublishDate() const{
	return publishDate;
}
double Book::getPrice() const{ 
	return price; 
}
void Book::setBorrowCount(int count) {
    borrowCount = count;
}
void Book::addBorrowCount() {
    borrowCount++;
}
