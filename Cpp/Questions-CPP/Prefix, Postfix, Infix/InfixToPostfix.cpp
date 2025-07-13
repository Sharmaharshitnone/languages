#include <bits/stdc++.h>
using namespace std;

bool isOperator(const string &c)
{
    return c == "+" || c == "-" || c == "*" || c == "/" || c == "^";
}

int priority(const string &c)
{
    if (c == "^")
        return 3;
    if (c == "*" || c == "/")
        return 2;
    if (c == "+" || c == "-")
        return 1;
    return -1;
}

string infixToPostfix(const string &expr)
{
    stack<string> st;
    stringstream ss(expr);
    string token;
    string result;

    while (ss >> token)
    {
        if (isalnum(token[0]))
        {
            // Operand (multi-digit or variable)
            result += token + " ";
        }
        else if (token == "(")
        {
            st.push(token);
        }
        else if (token == ")")
        {
            while (!st.empty() && st.top() != "(")
            {
                result += st.top() + " ";
                st.pop();
            }
            if (!st.empty())
                st.pop(); // Pop '('
        }
        else if (isOperator(token))
        {
            while (!st.empty() && st.top() != "(" &&
                   ((priority(token) < priority(st.top())) ||
                    (priority(token) == priority(st.top()))))
            {
                result += st.top() + " ";
                st.pop();
            }
            st.push(token);
        }
    }

    // Pop any remaining operators
    while (!st.empty())
    {
        result += st.top() + " ";
        st.pop();
    }

    return result;
    
}

int main()
{
    string input;
    getline(cin, input);

    string postfix = infixToPostfix(input);
    cout << "Postfix: " << postfix << endl;

    return 0;
}
