#include <iostream>
#include <string>

/**
 * ROTATED PALINDROME - CLEAN SOLUTION
 *
 * Problem: Given a string, determine if rotating it can form a palindrome.
 *
 * Examples:
 * - "aab" → rotate to "aba" → YES
 * - "abc" → no rotation works → NO
 *
 * Algorithm: Try all possible rotations and check if any is palindrome
 * Time: O(n²), Space: O(n)
 */

// Helper function to check if string is palindrome
bool isPalindrome(const std::string &str)
{
    int left = 0;
    int right = str.length() - 1;

    while (left < right)
    {
        if (str[left] != str[right])
        {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

// Main solution function
bool canFormPalindromeByRotation(const std::string &s)
{
    int n = s.length();

    // Edge case: empty or single character
    if (n <= 1)
    {
        return true;
    }

    // Try all possible rotations
    for (int i = 0; i < n; ++i)
    {
        // Create rotation by cutting at position i
        std::string rotated = s.substr(i) + s.substr(0, i);

        // Check if this rotation is palindrome
        if (isPalindrome(rotated))
        {
            return true;
        }
    }

    return false; // No palindromic rotation found
}

int main()
{
    std::string input_string;

    std::cout << "Enter a string: ";
    std::cin >> input_string;

    if (canFormPalindromeByRotation(input_string))
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }

    return 0;
}

/**
 * EXPLANATION:
 *
 * 1. Read input string
 * 2. For each possible rotation (0 to n-1):
 *    - Cut string at position i
 *    - Move first part to end: s[i:] + s[:i]
 *    - Check if result is palindrome
 * 3. Return YES if any rotation is palindrome, NO otherwise
 *
 * EXAMPLE TRACE for "aab":
 * Rotation 0: "aab" → NOT palindrome
 * Rotation 1: "aba" → IS palindrome → return YES
 *
 * COMPLEXITY:
 * - Time: O(n²) - n rotations × O(n) palindrome check
 * - Space: O(n) - for storing rotated strings
 */
