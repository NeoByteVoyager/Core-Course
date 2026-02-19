#include "RankList.h"
#include <iomanip> // 必须引入此头文件用于对齐
// === 1. 实现热度榜 ===
void RankList::showHotRanking(vector<Book> list) {
    // 按 borrowCount 从大到小排序
    sort(list.begin(), list.end(), [](const Book& a, const Book& b) {
        return a.getBorrowCount() > b.getBorrowCount();
    });

    cout << "\n\t┌────────────────────────────────────────────────────────┐" << endl;
    cout << "\t│                   借阅热度榜 TOP 10                    │" << endl;
    cout << "\t├──────┬──────────┬──────────────────────────────────────┤" << endl;
    cout << "\t│ 名次 │ 借阅次数 │ 书名                                 │" << endl;
    cout << "\t├──────┼──────────┼──────────────────────────────────────┤" << endl;

    // 只显示前 10 名
    int displayCount = (list.size() < 10) ? list.size() : 10;
    
    for (int i = 0; i < displayCount; i++) {
        // 使用 left 和 setw(n) 强制设定每列宽度
        cout << "\t│ " << setw(4) << left << (i + 1) 
             << " │ " << setw(8) << left << list[i].getBorrowCount() 
             << " │ " << setw(36) << left << list[i].getTitle().substr(0, 34) << " │" << endl;
    }

    cout << "\t└──────┴──────────┴──────────────────────────────────────┘" << endl;
}

void RankList::showNewRanking(vector<Book> list) {
    // 排序逻辑保持不变
    sort(list.begin(), list.end(), [](const Book& a, const Book& b) {
        return a.getPublishDate() > b.getPublishDate();
    });

    const int RANK_W = 6;
    const int DATE_W = 14;
    const int TITLE_W = 30;

    cout << endl;
    cout << "\t+--------+--------------+--------------------------------+" << endl;
    cout << "\t|                 最新新书榜 TOP 10              |" << endl;
    cout << "\t+--------+--------------+--------------------------------+" << endl;
    
    cout << "\t| " << setw(RANK_W) << left << "名次" 
         << "| " << setw(DATE_W) << left << "出版日期" 
         << "| " << setw(TITLE_W) << left << "书名" << " |" << endl;
    
    cout << "\t+--------+--------------+--------------------------------+" << endl;

    int displayCount = (list.size() < 10) ? list.size() : 10;
    
    for (int i = 0; i < displayCount; i++) {
        string displayTitle = list[i].getTitle();
        if (displayTitle.length() > TITLE_W - 3) {
            displayTitle = displayTitle.substr(0, TITLE_W - 3) + "...";
        }

        cout << "\t| " << setw(RANK_W) << left << (i + 1) 
             << "| " << setw(DATE_W) << left << list[i].getPublishDate() 
             << "| " << setw(TITLE_W) << left << displayTitle << " |" << endl;
    }

    cout << "\t+--------+--------------+--------------------------------+" << endl;
}
void RankList::recommendBook(vector<Book> list) {
    if (list.empty()) return;

    // 1. 先按热度排序
    sort(list.begin(), list.end(), [](const Book& a, const Book& b) {
        return a.getBorrowCount() > b.getBorrowCount();
    });

    // 2. 从前 5 名里随机挑一本
    srand(time(0)); 
    int topN = list.size() > 5 ? 5 : list.size();
    int luckyIndex = rand() % topN;

    cout << "\n [今日必读推荐] " << endl;
    cout << "根据全校大数据，我们为您甄选了这本好书：" << endl;
    cout << "《" << list[luckyIndex].getTitle() << "》" << endl;
    cout << "作者：" << list[luckyIndex].getAuthor() << endl;
    cout << "已被借阅 " << list[luckyIndex].getBorrowCount() << " 次！" << endl;
    cout << "----------------------------------" << endl;
}
