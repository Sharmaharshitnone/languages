#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string prefixToPostfix(string s)
{
    stack<string> st;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (!isOperator(s[i]))
        {
            st.push(string(1, s[i]));
        }
        else if (isOperator(s[i]))
        {


            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string postfix = op1 + op2 + s[i];

            st.push(postfix);
        }
    }

    return st.top();
}

int main()
{
    
        string str;
        cin >> str;

        string ans = prefixToPostfix(str);

        cout << ans << endl;
    
   

    return 0;
}