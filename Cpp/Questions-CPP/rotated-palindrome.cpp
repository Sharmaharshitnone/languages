#include <iostream>
#include <string>
#include <algorithm>

// Step 1: Efficient helper function to check palindrome without creating new strings
bool isPalindrome(const std::string &s, int start, int len)
{
    int left = 0;
    int right = len - 1;

    // Step 1a: Check characters from both ends, handling circular rotation
    while (left < right)
    {
        int left_idx = (start + left) % s.length();
        int right_idx = (start + right) % s.length();

        if (s[left_idx] != s[right_idx])
        {
            return false; // Found mismatch
        }
        left++;
        right--;
    }

    return true; // All characters matched
}

// Step 2: Optimal approach using string concatenation trick
bool canFormPalindromeOptimal(const std::string &s)
{
    // Step 2a: Handle edge cases
    if (s.empty())
        return true;
    if (s.length() == 1)
        return true;

    // Step 2b: Create doubled string to easily check all rotations
    std::string doubled = s + s;
    int n = s.length();

    // Step 2c: Check each possible starting position in doubled string
    for (int i = 0; i < n; ++i)
    {
        // Step 2d: Extract substring of original length starting at position i
        std::string rotation = doubled.substr(i, n);

        // Step 2e: Check if this rotation is a palindrome
        if (isPalindrome(rotation, 0, n))
        {
            return true; // Found palindromic rotation
        }
    }

    return false; // No palindromic rotation found
}

// Step 3: Even more optimal approach - check rotations without creating strings
bool canFormPalindromeVeryOptimal(const std::string &s)
{
    // Step 3a: Handle edge cases
    if (s.empty())
        return true;
    if (s.length() == 1)
        return true;

    int n = s.length();

    // Step 3b: Try each rotation starting position
    for (int start = 0; start < n; ++start)
    {
        bool is_palindrome = true;

        // Step 3c: Check if rotation starting at 'start' is palindrome
        for (int i = 0; i < n / 2; ++i)
        {
            int left_idx = (start + i) % n;
            int right_idx = (start + n - 1 - i) % n;

            if (s[left_idx] != s[right_idx])
            {
                is_palindrome = false;
                break;
            }
        }

        if (is_palindrome)
        {
            return true; // Found palindromic rotation
        }
    }

    return false; // No palindromic rotation found
}

int main()
{
    // Step 4: Read input
    std::string s;
    std::cin >> s;

    // Step 5: Use the most optimal approach
    bool result = canFormPalindromeVeryOptimal(s);

    // Step 6: Output result in required format
    if (result)
    {
        std::cout << "Yes, the rotated string is a palindrome." << std::endl;
    }
    else
    {
        std::cout << "No, the rotated string is not a palindrome." << std::endl;
    }

    return 0;
}

/*
OPTIMAL APPROACH EXPLANATION:

This solution uses efficient rotation checking without creating new strings:

Key Insight: Instead of creating n different rotated strings, we can simulate
rotations by using modular arithmetic to "wrap around" the original string.

How it works:
1. For each possible rotation starting position (0 to n-1)
2. Check if that rotation forms a palindrome using index calculations
3. Use modular arithmetic: (start + offset) % n to get the actual character
4. Compare characters from both ends moving inward

Example with "aab":
- Rotation 0: start=0, check s[0] vs s[2], s[1] vs s[1] → "aab"
- Rotation 1: start=1, check s[1] vs s[0], s[2] vs s[2] → "aba" ✓ palindrome!
- Rotation 2: start=2, check s[2] vs s[1], s[0] vs s[0] → "baa"

Index calculation for rotation starting at position 'start':
- Left character at position i: (start + i) % n
- Right character at position i: (start + n - 1 - i) % n

Time Complexity: O(n²)
- We try n different starting positions
- For each position, we check n/2 character pairs
- But we avoid string creation overhead, making it faster in practice

Space Complexity: O(1)
- Only uses a few variables, no extra string storage
- Much more memory efficient than creating n rotated strings

Why this is better than the simple approach:
- No string creation/copying overhead
- Better cache locality (working with same string)
- Lower memory usage
- Same time complexity but faster constant factors

Real-world Analogy:
- Instead of physically rearranging books on a circular bookshelf
- We imagine different starting points and check if the sequence is symmetric
- Much faster than actually moving the books each time

Edge Cases Handled:
- Empty string (considered palindrome)
- Single character (always palindrome)
- All characters the same (always palindrome)
- No palindromic rotations exist
- Original string is already a palindrome

Advanced Optimization Note:
For very large strings, we could use more sophisticated algorithms like:
- Manacher's algorithm for palindrome detection
- Rolling hash for fast string comparison
- But for the given constraints (≤10,000 chars), this O(n²) solution is sufficient
*/
