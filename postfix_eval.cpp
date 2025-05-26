#include <iostream>
#include <string.h>
#include <stack>
#include <cctype>
using namespace std;

double eval(string postfix){
    stack<double> st;
    int n = postfix.length();
    for(int i =0; i < n; i++){
        if(!isalnum(postfix[i])){
            double op1 = st.top();
            st.pop();
            double op2 = st.top();
            st.pop();
            if(postfix[i]  == '+') st.push(op1+op2);
            else if(postfix[i] == '-') st.push(op2-op1);
            else if(postfix[i] == '*') st.push(op2*op1);
            else if(postfix[i] == '/') st.push(op2/op1);

        }else{
            st.push((double)(postfix[i]-'0'));
        }
    }
    return st.top();

}

int main(){
    string str = "23+45*/"; // 2+3/4*5 = 5/20 => 1/4 => 0.25    
    cout<<eval(str);
    return 0;
}