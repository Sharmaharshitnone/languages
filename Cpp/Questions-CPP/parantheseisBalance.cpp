// Problem: Check if the given string of parentheses is balanced or not.
#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++) // loop to iterate through the string 
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') // push the current char of string if this condition is met
        {
            st.push(s[i]); // pushes into the stack 
        }
        else // if the char is other than ( { or [  })
        {
            if (st.size() == 0)
                return false; // if stack is empty

            char ch = st.top(); // stores the top element inorder to pop it later
            st.pop();
            if (s[i] == '}' && ch == '{' || s[i] == ']' && ch == '[' || s[i] == ')' && ch == '(')
                continue;// checks according to what was recieved

            else
            {

                return false;
            }
        }
    }
    return st.size() == 0; // if the stack is empty meaning all the elements meat their end 
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
