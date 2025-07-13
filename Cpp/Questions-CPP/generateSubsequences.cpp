#include <bits/stdc++.h>
using namespace std;

// Step 1: Helper function to generate all subsequences recursively
void generateSubsequences(string &str, int currentIndex, string currentSubsequence, vector<string> &result)
{
  // Step 2: Base case - we've processed all characters
  if (currentIndex == str.length())
  {
    result.push_back(currentSubsequence);
    return;
  }

  // Step 3: Choice 1 - Include current character
  generateSubsequences(str, currentIndex + 1, currentSubsequence + str[currentIndex], result);

  // Step 4: Choice 2 - Exclude current character
  generateSubsequences(str, currentIndex + 1, currentSubsequence, result);
}

// Step 5: Main function to get all subsequences
vector<string> getAllSubsequences(string str)
{
  // Step 6: Sort string to get lexicographically ordered output
  sort(str.begin(), str.end());

  vector<string> result;

  // Step 7: Start recursion from index 0 with empty subsequence
  generateSubsequences(str, 0, "", result);

  return result;
}

int main()
{
  string inputString;
  cin >> inputString;

  // Step 8: Generate all subsequences
  vector<string> subsequences = getAllSubsequences(inputString);

  // Step 9: Print all subsequences
  for (int i = 0; i < subsequences.size(); i++)
  {
    cout << subsequences[i] << " ";
  }
  cout << endl;

  return 0;
}