#include <iostream>
#include <string>
#include <stack>
using namespace std;

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 3;
    else
        return 1;
}

// char *convertArray(string exp){
//     char result[exp.length()];

// }

string convert(string exp)
{
    stack<char> st;
    string result;
    for (char ch : exp)
    {
        if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (st.top() != '(' && !st.empty())
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (!isdigit(ch))
        {
            while (!st.empty() && precedence(ch) > precedence(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(ch);
        }
        else
        {
            while (ch != ' ')
            {
                result += ch;
            }
            continue;
        }
    }
    while (!st.empty())
    {
        char ch = st.top();
        result += ch;
        st.pop();
    }
    return result;
}

int main()
{

    string exp = "23 + 9";
    cout << convert(exp) << endl;

    return 0;
}