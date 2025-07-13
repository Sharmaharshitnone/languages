#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '^' || c == '*' || c == '/');
}

string prefixToInfix(string s) {
    stack<string> st;
    
    for (int i = s.length() - 1; i >= 0; i--) {
        if (isOperator(s[i])) {


            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            string infix = "(" + op1 + " " + s[i] + " " + op2 + ")";
            st.push(infix);
        }
        else {
            st.push(string(1, s[i]));
        }
    }
    
    return st.top();
}

int main() {
    string str;
    getline(cin, str);

    string ans = prefixToInfix(str);
    if (!ans.empty()) {
        cout << ans << endl;
    }

    return 0;
}
