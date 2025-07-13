#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

// Helper function for backtracking
void backtrack(int index, const std::vector<std::string> &valid_strings,
               std::string current, std::unordered_set<char> &used_chars,
               int &max_length)
{
    // Step 3a: Update maximum length found so far
    max_length = std::max(max_length, (int)current.length());

    // Step 3b: Try including each remaining string
    for (int i = index; i < valid_strings.size(); ++i)
    {
        const std::string &candidate = valid_strings[i];

        // Step 3c: Check if this string can be added (no duplicate characters)
        bool can_add = true;
        for (char c : candidate)
        {
            if (used_chars.count(c))
            {
                can_add = false;
                break;
            }
        }

        if (can_add)
        {
            // Step 3d: Add this string and continue recursion
            // Add characters to used set
            for (char c : candidate)
            {
                used_chars.insert(c);
            }

            // Recurse with updated state
            backtrack(i + 1, valid_strings, current + candidate, used_chars, max_length);

            // Step 3e: Backtrack - remove characters from used set
            for (char c : candidate)
            {
                used_chars.erase(c);
            }
        }
    }
}

int main()
{
    // Step 1: Read input
    int n;
    std::cin >> n;

    std::vector<std::string> arr(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    // Step 2: Filter out strings that have duplicate characters within themselves
    std::vector<std::string> valid_strings;
    for (const std::string &s : arr)
    {
        std::unordered_set<char> char_set(s.begin(), s.end());
        if (char_set.size() == s.length())
        {
            valid_strings.push_back(s);
        }
    }

    int max_length = 0;

    // Step 3: Start backtracking from index 0 with empty string
    std::unordered_set<char> empty_set;
    backtrack(0, valid_strings, "", empty_set, max_length);

    // Step 4: Output the result
    std::cout << max_length << std::endl;

    return 0;
}

/*
SIMPLE APPROACH EXPLANATION:

This uses backtracking to try all possible subsequences:

1. First, we filter out strings that have duplicate characters within themselves
2. Then we try every possible combination of the remaining strings
3. For each combination, we check if all characters are unique
4. We keep track of the maximum length found

Time Complexity: O(2^n * m)
- We try 2^n possible subsequences (include/exclude each string)
- For each subsequence, we check m characters for uniqueness
- With 10× more strings, this could take 1000× longer!

Space Complexity: O(m)
- We store the current string and character set
- m is the total length of all strings combined

Edge Cases Handled:
- Empty array (max length = 0)
- Single string (max length = string length if no duplicates)
- All strings have overlapping characters (max length = longest single string)
- All strings are completely unique (max length = sum of all lengths)

Why O(2^n)?
- For each string, we have 2 choices: include it or skip it
- With n strings, we have 2×2×2×...×2 = 2^n total combinations
- This exponential growth is why backtracking can be slow for large inputs
*/
