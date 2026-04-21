#ifndef POLYLIST_H
#define POLYLIST_H

// 定义多项式的一项
struct Term {
    int coef; // 系数 (coefficient)
    int exp;  // 指数 (exponent)
};

// 线性表类，用于存储多项式
class PolyList {
private:
    static const int MAX_SIZE = 205; // 题目规模 n,m <= 100，相加后最多200项左右
    Term data[MAX_SIZE];             // 存放多项式的数组
    int length;                      // 线性表当前长度

public:
    PolyList();                      // 构造函数
    bool insert(int coef, int exp);  // 尾部插入新项
    int getLength() const;           // 获取当前线性表的长度
    Term getTerm(int index) const;   // 获取指定索引处的项
};

#endif // POLYLIST_H
