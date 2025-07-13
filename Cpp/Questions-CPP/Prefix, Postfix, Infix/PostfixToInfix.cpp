#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string postfixToinfix(string postfix){
    stack<string> st;
    stringstream ss(postfix);
    string token;

    while(ss >> token){
        if(!isOperator(token[0])){
            st.push(token);
        }
        else if(token.length() == 1 && isOperator(token[0])){
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();

            string infix = "(" + op1 + " " + token[0] + " " + op2 + ")";

            st.push(infix);
        }

    }


    return st.top();
}

int main(){
    string str;
    getline(cin,str);

    string infix = postfixToinfix(str);

    

    cout << infix;

    return 0;
}