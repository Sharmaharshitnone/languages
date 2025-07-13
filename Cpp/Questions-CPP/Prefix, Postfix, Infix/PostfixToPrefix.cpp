#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string postfixToPrefix(string s){
    stack <string> st;
    stringstream ss(s);
    string token;

    while(ss >> token){
        if (!isOperator(token[0])) {
            st.push(token);
        }
        else if (isOperator(token[0])) {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();

            string prefix = token + " " + op1 + " "+ op2;

            st.push(prefix);
        }
    }
    return st.top();
}

int main(){
    string str;
    getline(cin,str);

    string ans = postfixToPrefix(str);

    cout << ans;

    return 0;
}