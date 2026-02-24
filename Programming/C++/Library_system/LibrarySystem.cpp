#include "LibrarySystem.h"

// 构造函数：启动时自动读取数据 
LibrarySystem::LibrarySystem() {
    currentUser = NULL;
    
    // 先尝试从文件加载数据
    loadData();

    // 如果文件不存在或没数据（第一次运行），才加载测试数据
    if (bookList.empty()) {
        addTestBook();
    }
    if (userList.empty()) {
        initUsers();
    }
}

//析构函数：退出时自动保存 
LibrarySystem::~LibrarySystem() {
    saveData(); // 自动保存
    
    // 释放用户指针内存
    for(int i = 0; i < userList.size(); i++) {
        delete userList[i];
    }
}

// 保存数据到文件
void LibrarySystem::saveData() {
    // 1. 保存书籍
    ofstream bookFile("books.txt"); // 打开文件准备写
    if (bookFile.is_open()) {
        // 格式：书名 ISBN 作者 出版社 日期 价格 借阅次数
        for (int i = 0; i < bookList.size(); i++) {
            bookFile << bookList[i].getTitle() << " "
                     << bookList[i].getISBN() << " "
                     << bookList[i].getAuthor() << " "
                     << bookList[i].getPublisher()<< " " // 为了简单，出版社暂时写死，因为原来的Book没提供getPublisher接口，或者你自己补一个getPublisher()
                     << bookList[i].getPublishDate() << " "
                     << bookList[i].getPrice()<< " " // 价格同理，如果没有getPrice()，暂时写死或者你去Book类补上 
					 << bookList[i].getBorrowCount() << endl;
        }
        bookFile.close();
	}

    // 2. 保存用户
    ofstream userFile("users.txt");
    if (userFile.is_open()) {
        // 格式：角色 账号 密码
        for (int i = 0; i < userList.size(); i++) {
            userFile << userList[i]->getRole() << " "
                     << userList[i]->getAccount() << " "
                     << userList[i]->getPassword() << endl; 
        }
        userFile.close();
    }
}


//实现读取数据
void LibrarySystem::loadData() {
    // --- 读取书籍 ---
    ifstream bookFile("books.txt");
    if (bookFile.is_open()) {
        string t, i, a, p, d;
        double pr;
        int bc;
        // 按照写入的顺序读取
        while (bookFile >> t >> i >> a >> p >> d >> pr >> bc) {
            Book b(t, i, a, p, d, pr);
            b.setBorrowCount(bc); // 恢复借阅次数
            bookList.push_back(b);
        }
        bookFile.close();
    }

    // --- 读取用户 ---
    ifstream userFile("users.txt");
    if (userFile.is_open()) {
        int r;
        string acc, pwd;
        while (userFile >> r >> acc >> pwd) {
            if (r == 1) {
                userList.push_back(new Admin(acc, pwd));
            } else if (r == 2) {
                userList.push_back(new Reader(acc, pwd));
            }
        }
        userFile.close();
    }
}


//添加测试书籍 
void LibrarySystem::addTestBook() {
    Book b1("C++程序设计", "978-7-100", "谭浩强", "清华大学出版社", "2019-01", 59.0);
    bookList.push_back(b1);
    
    Book b2("哈利波特", "978-7-200", "JK罗琳", "人民文学出版社", "2000-09", 68.5);
    bookList.push_back(b2);
    
    Book b3("Java编程思想", "978-7-300", "Bruce_Eckel", "机械工业出版社", "2007-06", 108.0);
    bookList.push_back(b3);
}

//展示所有书籍 
void LibrarySystem::showAllBooks() {
    cout << "\n=== 馆藏书籍列表 (" << bookList.size() << "本) ===" << endl;
    for(int i = 0; i < bookList.size(); i++) {
        bookList[i].showInfo();
    }
}


//初始化用户的实现
void LibrarySystem::initUsers() {
    userList.push_back(new Admin("admin", "123456")); // 添加管理员
    userList.push_back(new Reader("tom", "123456"));  // 添加读者
}

//添加图书 
void LibrarySystem::addBook() {
    string t, i, a, p, d;
    double pr;
    
    cout << "\n=== 录入新书 ===" << endl;
    cout << "请输入书名 (不要带空格): ";
    cin >> t;
    cout << "请输入ISBN: ";
    cin >> i;
    
    // 检查ISBN是否重复（防止录重了）
    for(int k=0; k<bookList.size(); k++) {
        if(bookList[k].getISBN() == i) {
            cout << "错误：该ISBN已存在！" << endl;
            system("pause");
            return;
        }
    }

    cout << "请输入作者: ";
    cin >> a;
    cout << "请输入出版社: ";
    cin >> p;
    cout << "请输入出版日期 (如 2024-01): ";
    cin >> d;
    cout << "请输入价格: ";
    cin >> pr;

  
    
    //重置并清空
    if (!cin) { // 如果刚才输入的不是数字（比如输了 u）
        cin.clear(); // 修复 cin 的错误状态
    }
    // 把缓冲区里剩下的回车符或者输错的字母全部吃掉
    cin.ignore(1024, '\n'); 


    // 创建对象并加入列表
    Book b(t, i, a, p, d, pr);
    bookList.push_back(b);
    
    cout << "书籍录入成功！" << endl;
    saveData();
    system("pause");
 
}

//删除图书
void LibrarySystem::deleteBook() {
    string inputISBN;
    cout << "\n=== 删除图书 ===" << endl;
    cout << "请输入要删除的ISBN: ";
    cin >> inputISBN;

    // 遍历查找
    for (int i = 0; i < bookList.size(); i++) {
        if (bookList[i].getISBN() == inputISBN) {
            // 找到书了，显示一下确认信息
            cout << "找到书籍: " << bookList[i].getTitle() << endl;
            cout << "确认删除吗? (y/n): ";
            char confirm;
            cin >> confirm;
            
            if (confirm == 'y' || confirm == 'Y') {
                // vector 的删除操作
                bookList.erase(bookList.begin() + i);
                cout << "删除成功！" << endl;
            } else {
                cout << "已取消操作。" << endl;
            }
            saveData();
            system("pause");
            return; // 删完就结束函数
        }
    }
    //重置并清空
    if (!cin) { // 如果刚才输入的不是数字（比如输了 u）
        cin.clear(); // 修复 cin 的错误状态
    }
    // 把缓冲区里剩下的回车符或者输错的字母全部吃掉
    cin.ignore(1024, '\n'); 
    cout << "未找到ISBN为 " << inputISBN << " 的书籍。" << endl;
    system("pause");
}

//添加读者 
void LibrarySystem::addReader() {
    string acc, pwd;
    cout << "\n=== 添加读者 ===" << endl;
    cout << "请输入新账号: ";
    cin >> acc;
    
    // 检查账号是否重复
    for(int i=0; i<userList.size(); i++) {
        if(userList[i]->getAccount() == acc) {
            cout << "错误：该账号已存在！" << endl;
            system("pause");
            return;
        }
    }

    cout << "请输入初始密码: ";
    cin >> pwd;
    
    // 创建读者对象
    userList.push_back(new Reader(acc, pwd));
    cout << "读者添加成功！" << endl;
    
    // 清理缓冲区，防止回到菜单报错
    cin.ignore(1024, '\n');
    system("pause");
}

//删除读者
void LibrarySystem::deleteReader() {
    string acc;
    cout << "\n=== 删除读者 ===" << endl;
    cout << "请输入要删除的读者账号: ";
    cin >> acc;

    for (int i = 0; i < userList.size(); i++) {
        // 只能删除读者(Role=2)，且账号匹配
        if (userList[i]->getRole() == 2 && userList[i]->getAccount() == acc) {
            delete userList[i]; // 先释放内存
            userList.erase(userList.begin() + i); // 再从列表移除
            cout << "删除成功！" << endl;
            
            cin.ignore(1024, '\n'); 
            system("pause");
            return;
        }
    }
    cout << "未找到该读者账号。" << endl;
    cin.ignore(1024, '\n');
    system("pause");
}

//看所有读者
void LibrarySystem::viewAllReaders() {
    cout << "\n=== 读者列表 ===" << endl;
    cout << "账号\t\t密码(仅展示)" << endl;
    cout << "----------------------" << endl;
    int count = 0;
    for (int i = 0; i < userList.size(); i++) {
        // 只显示读者
        if (userList[i]->getRole() == 2) {
            cout << userList[i]->getAccount() << "\t\t" << userList[i]->getPassword() << endl;
            count++;
        }
    }
    cout << "----------------------" << endl;
    cout << "共找到 " << count << " 位读者。" << endl;
    system("pause");
}

//重置密码
void LibrarySystem::resetReaderPassword() {
    string acc;
    cout << "\n=== 重置密码 ===" << endl;
    cout << "请输入要重置的读者账号: ";
    cin >> acc;

    for (int i = 0; i < userList.size(); i++) {
        if (userList[i]->getRole() == 2 && userList[i]->getAccount() == acc) {
            userList[i]->setPassword("123456"); // 强制设为 123456
            cout << "密码已重置为 123456 ！" << endl;
            
            cin.ignore(1024, '\n');
            system("pause");
            return;
        }
    }
    cout << "未找到该读者账号。" << endl;
    cin.ignore(1024, '\n');
    system("pause");
}

//题名精确查找
void LibrarySystem::searchByTitle() {
    string inputTitle;
    cout << "\n=== 按题名搜索 ===" << endl;
    cout << "请输入书名: ";
    cin >> inputTitle;

    bool found = false;
    for (int i = 0; i < bookList.size(); i++) {
        // 精确匹配
        if (bookList[i].getTitle() == inputTitle) {
            bookList[i].showInfo(); // 调用 Book 类的显示函数
            found = true;
        }
    }
    
    if (!found) cout << "未找到名为 \"" << inputTitle << "\" 的书籍。" << endl;
    
    cin.ignore(1024, '\n'); // 清理缓冲区
    system("pause");
}

//ISBN精确查找
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
            break; // ISBN 是唯一的，找到一本就可以停了
        }
    }
    
    if (!found) cout << "未找到该 ISBN 的书籍。" << endl;
    
    cin.ignore(1024, '\n');
    system("pause");
}

//按作者查找 (结果按字典序排序)
void LibrarySystem::searchByAuthor() {
    string inputAuthor;
    cout << "\n=== 按作者搜索 ===" << endl;
    cout << "请输入作者名: ";
    cin >> inputAuthor;

    // 1. 先把这位作者所有的书找出来，存到一个临时列表里
    vector<Book> results;
    for (int i = 0; i < bookList.size(); i++) {
        if (bookList[i].getAuthor() == inputAuthor) {
            results.push_back(bookList[i]);
        }
    }

    if (results.empty()) {
        cout << "未找到作者 \"" << inputAuthor << "\" 的书籍。" << endl;
    } else {
        // 2. 使用 sort 进行排序 (PDF要求：字典序)
        // 这里的逻辑是：比较两本书的 Title，字母小的排前面
        sort(results.begin(), results.end(), [](const Book& a, const Book& b) {
            return a.getTitle() < b.getTitle();
        });

        // 3. 显示排序后的结果
        cout << "\n找到 " << results.size() << " 本书 (已按书名排序):" << endl;
        for (int i = 0; i < results.size(); i++) {
            results[i].showInfo();
        }
    }
    
    cin.ignore(1024, '\n');
    system("pause");
}

//借书功能
void LibrarySystem::borrowBook() {
    string inputISBN;
    cout << "\n=== 借阅图书 ===" << endl;
    cout << "请输入要借阅的ISBN: ";
    cin >> inputISBN;

    bool found = false;
    for (int i = 0; i < bookList.size(); i++) {
        if (bookList[i].getISBN() == inputISBN) {
            // 1. 增加借阅次数 (为排行榜做贡献)
            bookList[i].addBorrowCount(); 
            found = true;

            // 2. 写入借阅记录文件 (追加模式 ios::app)
            ofstream recordFile("records.txt", ios::app);
            if (recordFile.is_open()) {
                // 格式：账号 借/还 书名 ISBN
                recordFile << currentUser->getAccount() << " 借阅 " 
                           << bookList[i].getTitle() << " " 
                           << bookList[i].getISBN() << endl;
                recordFile.close();
            }

            cout << "借阅成功！《" << bookList[i].getTitle() << "》已加入您的书单。" << endl;
            saveData();
            break;
        }
    }

    if (!found) cout << "未找到该 ISBN 的书籍，无法借阅。" << endl;

    cin.ignore(1024, '\n');
    system("pause");
}

//还书功能
void LibrarySystem::returnBook() {
    string inputISBN;
    cout << "\n=== 归还图书 ===" << endl;
    cout << "请输入要归还的ISBN: ";
    cin >> inputISBN;

    // 这里简化处理：只要书库里有这本书，就允许“归还”
    bool found = false;
    for (int i = 0; i < bookList.size(); i++) {
        if (bookList[i].getISBN() == inputISBN) {
            found = true;
            
            // 写入归还记录
            ofstream recordFile("records.txt", ios::app);
            if (recordFile.is_open()) {
                recordFile << currentUser->getAccount() << " 归还 " 
                           << bookList[i].getTitle() << " " 
                           << bookList[i].getISBN() << endl;
                recordFile.close();
            }

            cout << "归还成功！已记录操作。" << endl;
            break;
        }
    }

    if (!found) cout << "馆藏目录中没有这本书，请确认ISBN。" << endl;

    cin.ignore(1024, '\n');
    system("pause");
}


//登录功能的实现
bool LibrarySystem::login() {
    string acc, pwd;
    cout << "\n=== 登录 ===" << endl;
    cout << "请输入账号: ";
    cin >> acc;
    cout << "请输入密码: ";
    cin >> pwd;
    
	cin.ignore(1024, '\n');
    // 遍历查找用户
    for(int i = 0; i < userList.size(); i++) {
        if (userList[i]->getAccount() == acc) {
            // 验证密码
            if (userList[i]->checkPassword(pwd)) {
                currentUser = userList[i]; // 记录当前登录人
                cout << "登录成功！" << endl;
                system("pause"); // 暂停一下让用户看到提示
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

//菜单函数
void LibrarySystem::adminMenu() {
    int choice;
    do {
        system("cls"); // 清屏，让界面更干净（Windows系统通用）
        cout << "===========================" << endl;
        cout << "      管理员操作面板       " << endl;
        cout << "===========================" << endl;
        cout << "1. 读者用户管理" << endl;
        cout << "2. 书籍信息管理" << endl;
        cout << "0. 注销登录 (返回上一级)" << endl;
        cout << "---------------------------" << endl;
        cout << "请输入选项: ";
        cin >> choice;

        switch(choice) {
            case 1: 
                adminUserMenu(); // 进入二级菜单
                break;
            case 2: 
                adminBookMenu(); // 进入二级菜单
                break;
            case 0:
                cout << "正在注销..." << endl;
                break; // 退出循环，函数结束，也就是“返回”
            default:
                cout << "无效输入，请重试。" << endl;
                system("pause");
        }
    } while (choice != 0);
}
// 二级菜单：读者用户管理
void LibrarySystem::adminUserMenu() {
    int choice;
    do {
        system("cls");
        cout << ">> 管理员 -> 读者用户管理" << endl;
        cout << "1. 添加读者" << endl;
        cout << "2. 删除读者" << endl;
        cout << "3. 查找/查看所有读者" << endl;
        cout << "4. 重置读者密码" << endl;
        cout << "0. 返回上一级" << endl;
        cout << "请输入: ";
        
        // 还是用防错写法
        if (cin >> choice) {
            cin.ignore(1024, '\n');
        } else {
            cin.clear();
            cin.ignore(1024, '\n');
            choice = -1;
        }
        
        switch(choice) {
            case 1: addReader(); break;
            case 2: deleteReader(); break;
            case 3: viewAllReaders(); break;
            case 4: resetReaderPassword(); break;
            case 0: break;
            default:
                cout << "输入无效" << endl;
                system("pause");
        }
    } while (choice != 0);
}
// 二级菜单：书籍管理
void LibrarySystem::adminBookMenu() {
    int choice;
    do {
        system("cls");
        cout << ">> 管理员 -> 书籍信息管理" << endl;
        cout << "1. 增加图书" << endl;
        cout << "2. 删除图书" << endl;
        cout << "3. 修改图书 (暂未开发)" << endl;
        cout << "4. 浏览所有图书" << endl;
        cout << "0. 返回上一级" << endl;
        cout << "请输入: ";
        
          // === 核心修改：更稳健的输入处理 ===
        if (cin >> choice) {
            // 如果输入成功，立刻把缓冲区里的回车符吃掉！
            // 否则这个回车符可能会传给 addBook，导致那里出问题
            cin.ignore(1000, '\n'); 
        } else {
            // 如果输入的不是数字（比如输了abc）
            cin.clear(); // 修复输入流
            cin.ignore(1000, '\n'); // 清空垃圾
            choice = -1; // 设为无效值
        }
        
        switch(choice) {
            case 1:
                addBook(); //添加书籍
                break;
            case 2:
                deleteBook(); //删除书籍
                break;
            case 3:
                cout << "功能开发中..." << endl; // 修改功能逻辑比较简单，通常是先删后加或直接set
                system("pause");
                break;
            case 4:
                showAllBooks(); 
                system("pause");
                break;
            case 0: break;
            default:
                cout << "输入无效" << endl;
                system("pause");
        }
    } while (choice != 0);
}
//读者菜单 
void LibrarySystem::readerMenu() {
    int choice;
    do {
        system("cls");
        cout << "===========================" << endl;
        cout << "       读者服务中心        " << endl;
        cout << "===========================" << endl;
        cout << "1. 搜索图书" << endl;
        cout << "2. 借阅/归还图书 " << endl;
        cout << "3. 查看排行榜" << endl;
        cout << "0. 注销登录" << endl;
        cout << "---------------------------" << endl;
        cout << "请输入: ";
        
        if (cin >> choice) {
            cin.ignore(1024, '\n');
        } else {
            cin.clear(); cin.ignore(1024, '\n'); choice = -1;
        }

        switch(choice) {
            case 1:
                // === 搜索子菜单 ===
                {
                    int searchType;
                    system("cls");
                    cout << ">> 读者 -> 图书搜索" << endl;
                    cout << "1. 按书名搜索" << endl;
                    cout << "2. 按ISBN搜索" << endl;
                    cout << "3. 按作者搜索" << endl;
                    cout << "0. 返回" << endl;
                    cout << "请选择: ";
                    cin >> searchType;
                    cin.ignore(1024, '\n'); // 吃回车

                    if (searchType == 1) searchByTitle();
                    else if (searchType == 2) searchByISBN();
                    else if (searchType == 3) searchByAuthor();
                }
                break;
            case 2:
                //借还子菜单
                {
                    int type;
                    system("cls");
                    cout << ">> 读者 -> 借还服务" << endl;
                    cout << "1. 借阅图书" << endl;
                    cout << "2. 归还图书" << endl;
                    cout << "0. 返回" << endl;
                    cout << "请选择: ";
                    cin >> type;
                    cin.ignore(1024, '\n'); 

                    if (type == 1) borrowBook();
                    else if (type == 2) returnBook();
                }
                break;
            case 3:
                showRanking(); 
                break;
            case 0: break;
            default:
                cout << "无效输入。" << endl;
                system("pause");
        }
    } while (choice != 0);
}

// === 排行榜功能 ===
void LibrarySystem::showRanking() {
    int type;
    system("cls");
    cout << ">> 读者 -> 图书排行榜" << endl;
    cout << "1. 借阅热度榜 (前10名)" << endl;
    cout << "2. 最新新书榜 (前10名)" << endl;
    cout << "0. 返回" << endl;
    cout << "请选择: ";
    cin >> type;
    cin.ignore(1024, '\n'); // 吃掉回车

    if (type == 0) return;

    // 1. 复制一份书籍列表 (为了不打乱原来的顺序)
    vector<Book> rankingList = bookList;

    // 2. 根据用户选择进行排序
    if (type == 1) {
        // 按借阅次数：从大到小
        sort(rankingList.begin(), rankingList.end(), [](const Book& a, const Book& b) {
            return a.getBorrowCount() > b.getBorrowCount();
        });
        cout << "\n=== 借阅热度榜 TOP 10 ===" << endl;
    } 
    else if (type == 2) {
        // 按出版日期：字符串越大越新
        sort(rankingList.begin(), rankingList.end(), [](const Book& a, const Book& b) {
            return a.getPublishDate() > b.getPublishDate();
        });
        cout << "\n=== 最新新书榜 TOP 10 ===" << endl;
    } 
    else {
        cout << "无效选择。" << endl;
        system("pause");
        return;
    }

    // 3. 打印前 10 名 (如果书不足10本，就打印所有)
    int count = 0;
    for (int i = 0; i < rankingList.size(); i++) {
        if (count >= 10) break; // 只显示前10个
        
        cout << "第 " << (i + 1) << " 名: ";
        // 简单打印书名和关键指标
        if (type == 1) {
            cout << rankingList[i].getTitle() 
                 << " (借阅: " << rankingList[i].getBorrowCount() << "次)" << endl;
        } else {
            cout << rankingList[i].getTitle() 
                 << " (出版: " << rankingList[i].getPublishDate() << ")" << endl;
        }
        count++;
    }
    
    cout << "-------------------------" << endl;
    system("pause");
}


//系统运行入口 
void LibrarySystem::run() {
    // 这里我们模拟一下以后的菜单结构
    cout << "系统初始化..." << endl;
   
    while (true) { // 让程序一直运行，直到用户强制关闭
        system("cls"); // 登录前清屏
        cout << "欢迎来到H大学图书馆管理系统" << endl;

        if (login()) {
            // === 核心逻辑：根据角色跳转不同菜单 ===
            if (currentUser->getRole() == 1) {
                adminMenu(); // 管理员去管理员菜单
            } else {
                readerMenu(); // 读者去读者菜单
            }
            // 当菜单函数结束（用户选了0），就会回到这里
            currentUser = NULL; // 登出，清空当前用户
        } else {
            cout << "登录失败，请重试。" << endl;
            system("pause");
        }
    }

}

