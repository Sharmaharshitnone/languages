#include <bits/stdc++.h>
using namespace std;

bool isOperator(const string &c)
{
  return c == "+" || c == "-" || c == "-" || c == "*" || c == "^";
}

int priority(const string &c)
{

  if (c == "^")
    return 3;
  if (c == "*" || c == "/")
    return 2;
  if (c == "+" || c == "-")
    return 1;
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
      result += tokken
    }
  }
}