#include "PolyList.h"

// 构造函数：初始化线性表长度为0
PolyList::PolyList() {
    length = 0;
}

// 在线性表尾部插入多项式的项
bool PolyList::insert(int coef, int exp) {
    if (length >= MAX_SIZE) {
        return false; // 线性表已满
    }
    data[length].coef = coef;
    data[length].exp = exp;
    length++;
    return true;
}

// 获取线性表的长度
int PolyList::getLength() const {
    return length;
}

// 获取指定索引处的多项式项
Term PolyList::getTerm(int index) const {
    if (index >= 0 && index < length) {
        return data[index];
    }
    // 如果索引越界，返回一个全为0的默认项
    Term emptyTerm = {0, 0};
    return emptyTerm;
}
