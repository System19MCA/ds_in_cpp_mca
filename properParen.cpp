#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isOpeningParen(char ch)
{
    return ch == '(' || ch == '{' || ch == '[';
}

bool isClosingParen(char ch)
{
    return ch == ')' || ch == '}' || ch == ']';
}

char inverseParen(char ch)
{
    if (ch == ')')
        return '(';
    if (ch == '}')
        return '{';
    if (ch == ']')
        return '[';
    return '\0';
}

bool isValidParen(string str)
{
    stack<char> st;
    for (char ch : str)
    {
        if (isOpeningParen(ch))
            st.push(ch);
        else if (isClosingParen(ch))
        {
            if (st.empty() || st.top() != inverseParen(ch))
                return false;
            st.pop();
        }
    }
    return st.empty() == true;
}

int main()
{
    string str1 = "(2+3-{2-9/4+[32/33]})";
    string str2 = "(2+3-{2-9/4+[32/33]}";
    cout << isValidParen(str1) << endl;
    cout << isValidParen(str2) << endl;
    return 0;
}