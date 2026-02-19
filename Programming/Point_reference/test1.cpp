#include <iostream>
using namespace std;
void swap2(int **x, int **y)
{
    int *t;
    t = *x;
    *x = *y;
    *y = t;
}

int main2()
{
    int a = 0, b = 1;
    int *p = &a, *q = &b;
    swap2(&p, &q);          // 交换后同样 p→b，q→a
    return 0;
}
