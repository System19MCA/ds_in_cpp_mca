#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    return 0; 
}


string infixToPostfix(const string& infix) {
    string postfix = "";
    stack<char> s;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(') {
                s.pop();
            } else {
                return "Error: Mismatched parentheses";
            }
        } else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                if (c == '^' && s.top() == '^') {
                    break;
                }
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
        // Ignore spaces or other unsupported characters (for this basic example)
    }

    // Pop any remaining operators from the stack to the postfix expression
    while (!s.empty()) {
        if (s.top() == '(' || s.top() == ')') {
            // Mismatched parentheses (should have been caught earlier)
            return "Error: Mismatched parentheses";
        }
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix1 = "a+b*c-(d/e+f)";
    cout << "Infix: " << infix1 << endl;
    cout << "Postfix: " << infixToPostfix(infix1) << endl << endl; // Expected: abc*+de/f+-

    string infix2 = "a*b+c/d";
    cout << "Infix: " << infix2 << endl;
    cout << "Postfix: " << infixToPostfix(infix2) << endl << endl; // Expected: ab*cd/+

    string infix3 = "(a+b)*c";
    cout << "Infix: " << infix3 << endl;
    cout << "Postfix: " << infixToPostfix(infix3) << endl << endl; // Expected: ab+c*

    string infix4 = "a+b-c";
    cout << "Infix: " << infix4 << endl;
    cout << "Postfix: " << infixToPostfix(infix4) << endl << endl; // Expected: ab+c-

    string infix5 = "a^b^c"; // Right-associativity for ^
    cout << "Infix: " << infix5 << endl;
    cout << "Postfix: " << infixToPostfix(infix5) << endl << endl; // Expected: abc^^

    string infix6 = "3+4*2/(1-5)^2";
    cout << "Infix: " << infix6 << endl;
    cout << "Postfix: " << infixToPostfix(infix6) << endl << endl; // Expected: 342*15-2/^ +

    string infix7 = "((A+B)*C-(D-E))^(F+G)";
    cout << "Infix: " << infix7 << endl;
    cout << "Postfix: " << infixToPostfix(infix7) << endl << endl; // Expected: AB+C*DE--FG+^

    string infix8 = "A*B+C/D";
    cout << "Infix: " << infix8 << endl;
    cout << "Postfix: " << infixToPostfix(infix8) << endl << endl; // Expected: AB*CD/+

    string infix9 = "(P+Q)*(R-S)/T";
    cout << "Infix: " << infix9 << endl;
    cout << "Postfix: " << infixToPostfix(infix9) << endl << endl; // Expected: PQ+RS-*T/



    return 0;
}