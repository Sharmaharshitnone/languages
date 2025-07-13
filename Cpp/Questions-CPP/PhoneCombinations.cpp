#include <bits/stdc++.h>
using namespace std;

// Step 1: Define the recursive helper function for backtracking.
void generateCombinations(string &digits, int index, string &currentCombination, vector<string> &result, vector<string> &keypadMap)
{
    // Step 2: Base Case. If we have processed all digits, we have a complete combination.
    if (index == digits.length())
    {
        // We only add the combination if it's not empty (handles empty input `digits`).
        if (!currentCombination.empty())
        {
            result.push_back(currentCombination);
        }
        return;
    }

    // Step 3: Get the letters corresponding to the current digit.
    // The expression `digits[index] - '0'` converts the character digit to an integer.
    string letters = keypadMap[digits[index] - '0'];

    // Step 4: Iterate through each possible letter for the current digit.
    for (int i = 0; i < letters.length(); i++)
    {
        // Step 5: CHOOSE - Add the letter to our current combination.
        currentCombination.push_back(letters[i]);

        // Step 6: EXPLORE - Recursively call the function for the next digit.
        generateCombinations(digits, index + 1, currentCombination, result, keypadMap);

        // Step 7: UNCHOOSE (Backtrack) - Remove the letter to explore other possibilities.
        // This is crucial. It's like stepping back in the decision tree to try a different path.
        currentCombination.pop_back();
    }
}

// Step 8: Main function to set up and start the process.
vector<string> letterCombinations(string &digits)
{
    vector<string> result;
    // Handle the edge case of an empty input string.
    if (digits.empty())
    {
        return result;
    }

    string currentCombination = "";
    // Step 9: Define the mapping from digits to letters.
    vector<string> keypadMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    // Step 10: Kick off the backtracking process from the first digit (index 0).
    generateCombinations(digits, 0, currentCombination, result, keypadMap);

    return result;
}

int main()
{
    string digits;
    cin >> digits;

    vector<string> ans = letterCombinations(digits);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}