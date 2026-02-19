#include "LibrarySystem.h"

// 构造函数：启动时自动读取数据 
LibrarySystem::LibrarySystem() {
    currentUser = NULL;
    loadData(); // 先尝试从文件加载数据

    if (bookList.empty()) addTestBook();
    if (userList.empty()) initUsers();
}

// 析构函数：退出时自动保存 
LibrarySystem::~LibrarySystem() {
    saveData(); 
    for(int i = 0; i < userList.size(); i++) {
        delete userList[i];
    }
}

// 保存数据
void LibrarySystem::saveData() {
    // 1. 保存书籍
    ofstream bookFile("books.txt");
    if (bookFile.is_open()) {
        for (int i = 0; i < bookList.size(); i++) {
            bookFile << bookList[i].getTitle() << " "
                     << bookList[i].getISBN() << " "
                     << bookList[i].getAuthor() << " "
                     << bookList[i].getPublisher() << " "
                     << bookList[i].getPublishDate() << " "
                     << bookList[i].getPrice() << " "
                     << bookList[i].getBorrowCount() << endl;
        }
        bookFile.close();
    }

    // 2. 保存用户
    ofstream userFile("users.txt");
    if (userFile.is_open()) {
        for (int i = 0; i < userList.size(); i++) {
            userFile << userList[i]->getRole() << " "
                     << userList[i]->getAccount() << " "
                     << userList[i]->getPassword() << endl; 
        }
        userFile.close();
    }
}

// 读取数据
void LibrarySystem::loadData() {
    // 读取书籍
    ifstream bookFile("books.txt");
    if (bookFile.is_open()) {
        string t, i, a, p, d;
        double pr;
        int bc;
        while (bookFile >> t >> i >> a >> p >> d >> pr >> bc) {
            Book b(t, i, a, p, d, pr);
            b.setBorrowCount(bc); 
            bookList.push_back(b);
        }
        bookFile.close();
    }

    // 读取用户
    ifstream userFile("users.txt");
    if (userFile.is_open()) {
        int r;
        string acc, pwd;
        while (userFile >> r >> acc >> pwd) {
            if (r == 1) userList.push_back(new Admin(acc, pwd));
            else if (r == 2) userList.push_back(new Reader(acc, pwd));
        }
        userFile.close();
    }
}

// 添加测试书籍 
void LibrarySystem::addTestBook() {
    bookList.push_back(Book("C++程序设计", "978-7-100", "谭浩强", "清华大学出版社", "2019-01", 59.0));
    bookList.push_back(Book("哈利波特", "978-7-200", "JK罗琳", "人民文学出版社", "2000-09", 68.5));
    bookList.push_back(Book("Java编程思想", "978-7-300", "Bruce_Eckel", "机械工业出版社", "2007-06", 108.0));
}

// 展示所有书籍 
void LibrarySystem::showAllBooks() {
    cout << "\n=== 馆藏书籍列表 (" << bookList.size() << "本) ===" << endl;
    for(int i = 0; i < bookList.size(); i++) {
        bookList[i].showInfo();
    }
}

// 初始化用户
void LibrarySystem::initUsers() {
    userList.push_back(new Admin("admin", "123456")); 
    userList.push_back(new Reader("tom", "123456"));  
}

// 登录功能
bool LibrarySystem::login() {
    string acc, pwd;
    cout << "\n=== 登录 ===" << endl;
    cout << "请输入账号: ";
    cin >> acc;
    cout << "请输入密码: ";
    cin >> pwd;
    
    cin.ignore(1024, '\n');
    for(int i = 0; i < userList.size(); i++) {
        if (userList[i]->getAccount() == acc) {
            if (userList[i]->checkPassword(pwd)) {
                currentUser = userList[i];
                cout << "登录成功！" << endl;
                system("pause");
                return true;
            } else {
                cout << "密码错误！" << endl;
                system("pause");
                return false;
            }
        }
    }
    cout << "账号不存在！" << endl;
    system("pause");
    return false;
}

// === 菜单系统 ===

void LibrarySystem::adminMenu() {
    int choice;
    do {
        system("cls");
        Menu::showAdmin();
        if (!(cin >> choice)) { cin.clear(); cin.ignore(1024, '\n'); choice = -1; }
        else cin.ignore(1024, '\n');

        switch(choice) {
            case 1: adminUserMenu(); break;
            case 2: adminBookMenu(); break;
            case 0: cout << "正在注销..." << endl; break;
            default: cout << "无效输入。" << endl; system("pause");
        }
    } while (choice != 0);
}

// 管理员-用户管理
void LibrarySystem::adminUserMenu() {
    // 确保是管理员
    if (currentUser->getRole() != 1) return;
    Admin* admin = (Admin*)currentUser; // 强转指针

    int choice;
    do {
        system("cls");
        Menu::adminUserMenu();
        if (!(cin >> choice)) { cin.clear(); cin.ignore(1024, '\n'); choice = -1; }
        else cin.ignore(1024, '\n');
        
        switch(choice) {
            case 1: 
                admin->addReader(userList); // 调用 Admin 类的方法
                saveData(); 
                break;
            case 2: 
                admin->deleteReader(userList); 
                saveData(); 
                break;
            case 3: 
                admin->viewAllReaders(userList); 
                break;
            case 4: 
                admin->resetReaderPassword(userList); 
                saveData(); 
                break;
            case 0: break;
            default: cout << "输入无效" << endl; system("pause");
        }
    } while (choice != 0);
}

// 管理员-书籍管理
void LibrarySystem::adminBookMenu() {
    // 确保是管理员
    if (currentUser->getRole() != 1) return;
    Admin* admin = (Admin*)currentUser; // 强转指针

    int choice;
    do {
        system("cls");
        Menu::adminBookMenu();
        if (!(cin >> choice)) { cin.clear(); cin.ignore(1024, '\n'); choice = -1; }
        else cin.ignore(1024, '\n');
        
        switch(choice) {
            case 1:
                admin->addBook(bookList); // 调用 Admin 类的方法
                saveData();
                break;
            case 2:
                admin->deleteBook(bookList);
                saveData();
                break;
            case 3:
                admin->modifyBook(bookList);
                saveData();
                break;
            case 4:
                showAllBooks(); 
                system("pause");
                break;
            case 0: break;
            default: cout << "输入无效" << endl; system("pause");
        }
    } while (choice != 0);
}

// 读者菜单 
void LibrarySystem::readerMenu() {
    // 确保是读者
    if (currentUser->getRole() != 2) return;
    Reader* reader = (Reader*)currentUser; // 强转指针

    int choice;
    do {
        system("cls");
        Menu::showReader();
        if (!(cin >> choice)) { cin.clear(); cin.ignore(1024, '\n'); choice = -1; }
        else cin.ignore(1024, '\n');

        switch(choice) {
            case 1:
                // === 搜索子菜单 (直接调用 LibrarySystem 的函数) ===
                {
                    int searchType;
                    system("cls");
                    Menu::readerSerachMenu();
                    if (!(cin >> searchType)) { cin.clear(); cin.ignore(1024, '\n'); }
                    else cin.ignore(1024, '\n');

                    if (searchType == 1) searchByTitle();
                    else if (searchType == 2) searchByISBN();
                    else if (searchType == 3) searchByAuthor();
                }
                break;
            case 2:
                // === 借还子菜单 (调用 Reader 类的方法) ===
                {
                    int type;
                    system("cls");
                    Menu::readerBoReMenu();
                    if (!(cin >> type)) { cin.clear(); cin.ignore(1024, '\n'); }
                    else cin.ignore(1024, '\n');

                    if (type == 1) {
                        reader->borrowBook(bookList); // 传入书单
                        saveData();
                    }
                    else if (type == 2) {
                        reader->returnBook(bookList); // 传入书单
                        saveData();
                    }
                }
                break;
            case 3:
                showRanking(); 
                break;
            case 0: break;
            default: cout << "无效输入。" << endl; system("pause");
        }
    } while (choice != 0);
}

// === 搜索功能 ===

void LibrarySystem::searchByTitle() {
    string inputTitle;
    cout << "\n=== 按题名搜索 ===" << endl;
    cout << "请输入书名: ";
    cin >> inputTitle;

    bool found = false;
    for (int i = 0; i < bookList.size(); i++) {
        if (bookList[i].getTitle() == inputTitle) {
            bookList[i].showInfo();
            found = true;
        }
    }
    if (!found) cout << "未找到名为 \"" << inputTitle << "\" 的书籍。" << endl;
    cin.ignore(1024, '\n');
    system("pause");
}

void LibrarySystem::searchByISBN() {
    string inputISBN;
    cout << "\n=== 按ISBN搜索 ===" << endl;
    cout << "请输入ISBN: ";
    cin >> inputISBN;

    bool found = false;
    for (int i = 0; i < bookList.size(); i++) {
        if (bookList[i].getISBN() == inputISBN) {
            bookList[i].showInfo();
            found = true;
            break;
        }
    }
    if (!found) cout << "未找到该 ISBN 的书籍。" << endl;
    cin.ignore(1024, '\n');
    system("pause");
}

void LibrarySystem::searchByAuthor() {
    string inputAuthor;
    cout << "\n=== 按作者搜索 ===" << endl;
    cout << "请输入作者名: ";
    cin >> inputAuthor;

    vector<Book> results;
    for (int i = 0; i < bookList.size(); i++) {
        if (bookList[i].getAuthor() == inputAuthor) {
            results.push_back(bookList[i]);
        }
    }

    if (results.empty()) {
        cout << "未找到作者 \"" << inputAuthor << "\" 的书籍。" << endl;
    } else {
        sort(results.begin(), results.end(), [](const Book& a, const Book& b) {
            return a.getTitle() < b.getTitle();
        });

        cout << "\n找到 " << results.size() << " 本书 (已按书名排序):" << endl;
        for (int i = 0; i < results.size(); i++) {
            results[i].showInfo();
        }
    }
    cin.ignore(1024, '\n');
    system("pause");
}

// === 排行榜功能 ===
void LibrarySystem::showRanking() {
    int type;
    system("cls");
    Menu::RankingMenu();
    if (!(cin >> type)) { cin.clear(); cin.ignore(1024, '\n'); type = -1; }
    else cin.ignore(1024, '\n');

    if (type == 1) {
        RankList::showHotRanking(bookList);
        system("pause");
    } 
    else if (type == 2) {
        RankList::showNewRanking(bookList);
        system("pause");
    }
    else if (type == 0) return;
    else {
        cout << "无效选择。" << endl;
        system("pause");
    }
}

// 系统运行入口 
void LibrarySystem::run() {
    while (true) { 
        system("cls"); 
        Menu::showMain();

        if (login()) {
            if (currentUser->getRole() == 1) {
                adminMenu(); 
            } else {
                readerMenu(); 
            }
            currentUser = NULL; 
        } else {
            cout << "登录失败，请重试。" << endl;
            system("pause");
        }
    }
}
