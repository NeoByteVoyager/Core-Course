#include<bits/stdc++.h>
using namespace std;

void swap1(int *&x, int *&y)
{
    int *t;
    t = x;
    x = y;
    y = t;
}

int main1()
{
    int a = 0, b = 1;
    int *p = &a, *q = &b;   // p¡úa£¬q¡úb
    swap1(p, q);            // ½»»»ºó p¡úb£¬q¡úa
    return 0;
}
