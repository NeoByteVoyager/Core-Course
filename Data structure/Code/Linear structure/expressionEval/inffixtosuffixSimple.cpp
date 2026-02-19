#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}
int Precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/' || c == '%')
        return 2;
    return 0;
}
string inffixtosuffix(string s)
{
    string res;

    stack<char> st;
    int index = 0;
    int n = s.size();

    while (index < n)
    {
        char c = s[index];
        if (isdigit(c))
        {
            while (index < n && isdigit(s[index]))
            {
                res += s[index];
                index++;
            }
            res += " ";
            index--;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                res += " ";
                st.pop();
            }
            st.pop(); // 左括号弹出栈
        }
        else
        { // 如果他是操作符
            while (!st.empty() && Precedence(st.top()) >= Precedence(c))
            {
                res += st.top();
                res += " ";
                st.pop();
            }
            st.push(c);
        }
        index++;
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}
int eval(string s)
{
    stack<int> st;
    stringstream ss(s);
    string c;
    while (ss >> c)
    {
        if (isdigit(c[0]))
            st.push(stoi(c));
        else
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            if (c == "+")
                st.push(op1 + op2);
            else if (c == "-")
                st.push(op1 - op2);
            else if (c == "*")
                st.push(op1 * op2);
            else if (c == "/")
                st.push(op1 / op2);
            else
                st.push(op1 % op2);
        }
    }
    return st.top();
}
int main()
{
    string s = "15/(5-2)*6";
    cout << inffixtosuffix(s) << endl;
    cout << eval(inffixtosuffix(s));
    return 0;
}