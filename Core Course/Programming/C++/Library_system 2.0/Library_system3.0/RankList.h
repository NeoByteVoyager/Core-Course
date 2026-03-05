#ifndef RANKLIST_H
#define RANKLIST_H

#include <vector>
#include <iostream>
#include <algorithm> 
#include "Book.h"    // 必须认识 Book

using namespace std;

class RankList {
public:
    // 1. 显示借阅热度榜
    // 参数传 vector<Book> list (按值传递)，会自动复制一份，不会影响 LibrarySystem 里原来的顺序。
    static void showHotRanking(vector<Book> list);

    // 2. 显示最新新书榜
    static void showNewRanking(vector<Book> list);
};

#endif
