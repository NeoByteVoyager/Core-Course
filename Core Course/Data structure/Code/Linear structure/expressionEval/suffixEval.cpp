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
int suffixEval(string &s)
{
    int op2, op1;
    int index = 0;
    stack<int> st;
    Type token = get_token(s, index);
    while (token != END)
    {
        if (token == NUM)
            st.push(s[index] - '0');
        else
        {

            op2 = st.top();
            st.pop();
            op1 = st.top();
            st.pop();
            switch (token)
            {
            case ADD:
                st.push(op1 + op2);
                break;
            case SUB:
                st.push(op1 - op2);
                break;
            case MUL:
                st.push(op1 * op2);
                break;
            case DIV:
                st.push(op1 / op2);
                break;
            case MOD:
                st.push(op1 % op2);
                break;
            default:
                break;
            }
        }
        index++;
        token = get_token(s, index);
    }

    return st.top();
}
int main()
{
    string s = "82/2+56*-";
    cout << suffixEval(s);
    return 0;
}