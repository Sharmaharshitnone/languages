#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}


int getPrecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPrefix(const string &infix)
{
    stack<char> operators;
    string prefix;

    // Reverse the infix expression
    string reversedInfix(infix.rbegin(), infix.rend());

    for (char c : reversedInfix)
    {
        if (isalnum(c))
        { // Operand
            prefix = c + prefix;
        }
        else if (c == ')')
        {
            operators.push(c);
        }
        else if (c == '(')
        {
            // Pop operators until a closing parenthesis is found
            while (!operators.empty() && operators.top() != ')')
            {
                prefix = operators.top() + prefix;
                operators.pop();
            }
            // Pop the remaining ')' from the stack
            operators.pop();
        }
        else if (isOperator(c))
        { // Operator
            while (!operators.empty() && getPrecedence(c) < getPrecedence(operators.top()))
            {
                prefix = operators.top() + prefix;
                operators.pop();
            }
            operators.push(c);
        }
    }

    // Pop remaining operators from the stack
    while (!operators.empty())
    {
        prefix = operators.top() + prefix;
        operators.pop();
    }

    return prefix;
}

string infixToPostfix(const string &infix)
{
    stack<char> operators;
    string postfix;

    for (char c : infix)
    {
        if (isalnum(c))
        { // Operand
            postfix += c;
        }
        else if (c == '(')
        {
            operators.push(c);
        }
        else if (c == ')')
        {
            // Pop operators until a matching '(' is found
            while (!operators.empty() && operators.top() != '(')
            {
                postfix += operators.top();
                operators.pop();
            }
            // Pop the '(' from the stack
            operators.pop();
        }
        else if (isOperator(c))
        { // Operator
            while (!operators.empty() && getPrecedence(c) <= getPrecedence(operators.top()))
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    // Pop remaining operators from the stack
    while (!operators.empty())
    {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main()
{
    string infix_expression;
    getline(cin , infix_expression);
    string prefix_expression = infixToPrefix(infix_expression);
    cout << "Infix Expression: " << infix_expression << endl;
    cout << "Prefix Expression: " << prefix_expression << endl;
    return 0;
}