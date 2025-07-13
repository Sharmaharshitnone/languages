#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
  stack<char> st;
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[')
    {
      st.push(s[i]);
    }
    else
    {
      if (st.size() == 0)
        return false;
      char ch = st.top();
      st.pop();
      if (s[i] == '}' && ch == '{' || s[i] == ']' && ch == '[' || s[i] == ')' && ch == '(')
        continue;
      else
      {
        return false;
      }
    }
  }
  return st.size() == 0;
}

int main()
{
  string str;
  cin >> str;
  if (isValid(str))
  {
    cout << "true";
  }
  else
  {
    cout << "false";
  }
  return 0;
}