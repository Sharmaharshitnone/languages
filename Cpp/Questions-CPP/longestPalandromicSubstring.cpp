#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Step 1. Define a helper function to find the length of a palindrome
// by expanding from a given center.
int expandAroundCenter(const string &s, int left, int right)
{
  // Step 2. Initialize the left and right pointers to the given center.
  int L = left, R = right;

  // Step 3. Expand outwards as long as we are within the string's bounds
  // and the characters at the pointers match.
  while (L >= 0 && R < s.length() && s[L] == s[R])
  {
    L--; // Move left pointer to the left.
    R++; // Move right pointer to the right.
  }

  // Step 4. The final length of the palindrome is R - L - 1.
  // (e.g., if L=-1, R=3 for "aba", length is 3 - (-1) - 1 = 3).
  return R - L - 1;
}

string longestPalindrome(string s)
{
  // Step 5. Handle edge cases for very short strings.
  if (s.length() < 1)
  {
    return "";
  }

  // Step 6. Initialize variables to track the start and length of the longest palindrome.
  int start = 0;
  int maxLength = 1; // Every single character is a palindrome of length 1.

  // Step 7. Iterate through each character of the string to treat it as a potential center.
  for (int i = 0; i < s.length(); ++i)
  {
    // Step 8. Check for odd-length palindromes, centered at 'i'.
    int len1 = expandAroundCenter(s, i, i);

    // Step 9. Check for even-length palindromes, centered between 'i' and 'i+1'.
    int len2 = expandAroundCenter(s, i, i + 1);

    // Step 10. Find the maximum length from the two checks.
    int currentMaxLen = max(len1, len2);

    // Step 11. If we've found a new longest palindrome...
    if (currentMaxLen > maxLength)
    {
      // ...update our maximum length.
      maxLength = currentMaxLen;
      // ...and calculate the new starting index of this longest palindrome.
      start = i - (maxLength - 1) / 2;
    }
  }

  // Step 12. Return the longest palindromic substring using the start and length we found.
  return s.substr(start, maxLength);
}

int main()
{
  string s;
  cout << "Enter the string: ";
  cin >> s;
  string result = longestPalindrome(s);
  cout << "Longest palindromic substring: " << result << endl;
  return 0;
}