#include <bits/stdc++.h>
using namespace std;
enum Type
{
    LEFT_PARE,
    RIGHT_PARE,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    END,
    NUM
};
Type get_token(string &s, int index)
{
    if (index == s.size())
        return END;
    switch (s[index])
    {
    case '(':
        return LEFT_PARE;
    case ')':
        return RIGHT_PARE;
    case '+':
        return ADD;
    case '-':
        return SUB;
    case '*':
        return MUL;
    case '/':
        return DIV;
    case '%':
        return MOD;
    default:
        return NUM;
    }
}
char change(Type e)
{
    switch (e)
    {
    case LEFT_PARE:
        return '(';
    case ADD:
        return '+';
    case SUB:
        return '-';
    case MUL:
        return '*';
    case DIV:
        return '/';
    case MOD:
        return '%';
    default:
        return ' ';
    }
}
string inffixTosuffix(string &s)
{
    int inStack[] = {0, 3, 1, 1, 2, 2, 2, 0, 0};
    int outStack[] = {3, 3, 1, 1, 2, 2, 2, 0, 0};
    string res;
    int index = 0;
    Type token = get_token(s, index);
    stack<Type> st;
    st.push(END);
    while (token != END)
    {
        if (token == NUM)
        {
            res += s[index];
        }
        else if (token == RIGHT_PARE)
        {
            // 遇到右括号优先级最高出栈直至左括号出栈
            while (st.top() != LEFT_PARE)
            {
                res += change(st.top());
                st.pop();
            }
            st.pop(); // 左括号出栈,但是不输出
        }
        else
        {
            // 遇到一般的符号
            while (inStack[st.top()] >= outStack[token])
            {
                res += change(st.top());
                st.pop();
            }
            st.push(token);
        }
        index++;
        token = get_token(s, index);
    }
    while (st.top() != END)
    {
        res += change(st.top());
        st.pop();
    }
    return res;
}
int main()
{
    string s = "x/(i-j)*y";
    cout << inffixTosuffix(s);
    return 0;
}