/*
  Question: Generate All Subsequences of a String

  Given a string, generate all possible subsequences (the power set) of the string.
  A subsequence is a sequence that can be derived from the string by deleting zero or more characters without changing the order of the remaining characters.

  Input:
  - A string str.

  Output:
  - All possible subsequences of the string, in any order.

  Example:
  Input:  "abc"
  Output: "", "a", "b", "c", "ab", "ac", "bc", "abc"
*/

#include <bits/stdc++.h>
using namespace std;

// Step 1: Define a helper function that will recursively build all subsequences by either including or excluding the current character.
// Step 2: If the current index reaches the end of the string, add the current subsequence to the answer list.
// Step 3: Otherwise, make two recursive calls:
//         a) Include the current character in the subsequence.
//         b) Exclude the current character from the subsequence.
void helper(string &str, int idx, string current, vector<string> &ans)
{
  if (idx == str.length())
  {
    ans.push_back(current);
    return;
  }

  helper(str, idx + 1, current + str[idx], ans);
  helper(str, idx + 1, current, ans);
}

vector<string> subsquences(string str)
{
  sort(str.begin(), str.end());
  vector<string> ans;

  helper(str, 0, "", ans);
  return ans;
}

int main()
{
  // Step 4: In the main function, read the input string.
  string str;
  cin >> str;

  // Step 5: Call the subsequences function to generate all subsequences.
  vector<string> ans = subsquences(str);

  // Step 6: Print all generated subsequences.
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }

  return 0;
}
