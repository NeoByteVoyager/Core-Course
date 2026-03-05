#include "RankList.h"

// === 1. 实现热度榜 ===
void RankList::showHotRanking(vector<Book> list) {
    // 按 borrowCount 从大到小排序
    sort(list.begin(), list.end(), [](const Book& a, const Book& b) {
        return a.getBorrowCount() > b.getBorrowCount();
    });

    cout << "\n=== 借阅热度榜 TOP 10 ===" << endl;
    cout << "名次\t借阅次数\t书名" << endl;
    cout << "--------------------------------" << endl;

    // 只显示前 10 名
    int count = 0;
    for (int i = 0; i < list.size(); i++) {
        if (count >= 10) break;
        
        cout << (i + 1) << "\t" 
             << list[i].getBorrowCount() << "\t\t" 
             << list[i].getTitle() << endl;
        count++;
    }
    cout << "--------------------------------" << endl;
}

// === 2. 实现新书榜 ===
void RankList::showNewRanking(vector<Book> list) {
    // 按出版日期字符串降序排序
    sort(list.begin(), list.end(), [](const Book& a, const Book& b) {
        return a.getPublishDate() > b.getPublishDate();
    });

    cout << "\n=== 最新新书榜 TOP 10 ===" << endl;
    cout << "名次\t出版日期\t书名" << endl;
    cout << "--------------------------------" << endl;

    int count = 0;
    for (int i = 0; i < list.size(); i++) {
        if (count >= 10) break;
        
        cout << (i + 1) << "\t" 
             << list[i].getPublishDate() << "\t" 
             << list[i].getTitle() << endl;
        count++;
    }
    cout << "--------------------------------" << endl;
}
