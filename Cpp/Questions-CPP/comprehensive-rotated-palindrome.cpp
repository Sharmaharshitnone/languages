#include <iostream>
#include <string>
#include <vector>

/**
 * ROTATED PALINDROME PROBLEM - COMPREHENSIVE SOLUTION
 *
 * Problem: Given a string, determine if it can be transformed into a palindrome
 * by rotating it (moving characters from one end to the other).
 *
 * Examples:
 * - "aab" → "aba" (after rotation) → YES
 * - "abc" → No rotation works → NO
 *
 * Real-world analogy: Like a circular necklace with lettered beads - can we
 * find a starting position that makes the sequence read the same forwards/backwards?
 */

// Helper function to check if a string is palindrome
bool isPalindromeHelper(const std::string &str)
{
    int left = 0;
    int right = str.length() - 1;

    // Step 1: Use two pointers from both ends
    while (left < right)
    {
        if (str[left] != str[right])
        {
            return false; // Found mismatch
        }
        left++;
        right--;
    }

    return true; // All characters matched
}

// APPROACH 1: Brute Force - Try all rotations
// Time: O(n²), Space: O(n)
bool canFormPalindromeBruteForce(const std::string &original_string)
{
    int string_length = original_string.length();

    // Step 1: Handle edge cases
    if (string_length <= 1)
    {
        return true; // Empty or single char is always palindrome
    }

    // Step 2: Try each possible rotation
    for (int rotation_start = 0; rotation_start < string_length; ++rotation_start)
    {
        // Step 2a: Create rotated string by cutting at position rotation_start
        std::string rotated_string = original_string.substr(rotation_start) +
                                     original_string.substr(0, rotation_start);

        // Step 2b: Check if this rotation is palindrome
        if (isPalindromeHelper(rotated_string))
        {
            return true; // Found palindromic rotation!
        }
    }

    return false; // No palindromic rotation found
}

// APPROACH 2: Optimal - String concatenation trick
// Time: O(n²), Space: O(n)
bool canFormPalindromeOptimal(const std::string &original_string)
{
    int string_length = original_string.length();

    // Step 1: Handle edge cases
    if (string_length <= 1)
    {
        return true;
    }

    // Step 2: Create doubled string - all rotations become substrings
    // Example: "aab" → "aabaab" contains "aab", "aba", "baa"
    std::string doubled_string = original_string + original_string;

    // Step 3: Check each substring of original length
    for (int start_position = 0; start_position < string_length; ++start_position)
    {
        // Step 3a: Extract rotation as substring
        std::string current_rotation = doubled_string.substr(start_position, string_length);

        // Step 3b: Check if this rotation is palindrome
        if (isPalindromeHelper(current_rotation))
        {
            return true;
        }
    }

    return false;
}

// APPROACH 3: Most Optimal - No extra strings, direct checking
// Time: O(n²), Space: O(1)
bool canFormPalindromeMostOptimal(const std::string &original_string)
{
    int string_length = original_string.length();

    // Step 1: Handle edge cases
    if (string_length <= 1)
    {
        return true;
    }

    // Step 2: Try each rotation starting position
    for (int rotation_start = 0; rotation_start < string_length; ++rotation_start)
    {
        bool is_current_rotation_palindrome = true;

        // Step 2a: Check palindrome using modular arithmetic for circular access
        for (int check_position = 0; check_position < string_length / 2; ++check_position)
        {
            // Calculate actual indices in original string
            int left_index = (rotation_start + check_position) % string_length;
            int right_index = (rotation_start + string_length - 1 - check_position) % string_length;

            // Step 2b: Compare characters at symmetric positions
            if (original_string[left_index] != original_string[right_index])
            {
                is_current_rotation_palindrome = false;
                break; // Early termination for this rotation
            }
        }

        if (is_current_rotation_palindrome)
        {
            return true; // Found palindromic rotation!
        }
    }

    return false; // No palindromic rotation exists
}

// Function to demonstrate all rotations for understanding
void demonstrateRotations(const std::string &test_string)
{
    std::cout << "\\n=== DEMONSTRATION FOR: \"" << test_string << "\" ===" << std::endl;

    if (test_string.empty())
    {
        std::cout << "Empty string is considered palindrome." << std::endl;
        return;
    }

    if (test_string.length() == 1)
    {
        std::cout << "Single character is always palindrome." << std::endl;
        return;
    }

    std::cout << "All possible rotations:" << std::endl;

    int string_length = test_string.length();
    bool found_palindrome = false;

    // Show every rotation
    for (int i = 0; i < string_length; ++i)
    {
        std::string rotation = test_string.substr(i) + test_string.substr(0, i);
        bool is_palindrome = isPalindromeHelper(rotation);

        std::cout << "Rotation " << i << ": \"" << rotation << "\"";

        if (is_palindrome)
        {
            std::cout << " ✅ PALINDROME!";
            found_palindrome = true;
        }
        else
        {
            std::cout << " ❌ Not palindrome";
        }
        std::cout << std::endl;
    }

    std::cout << "\\nFinal result: " << (found_palindrome ? "YES" : "NO") << std::endl;
}

int main()
{
    // Test cases for demonstration
    std::vector<std::string> test_cases = {
        "aab",    // Should be YES (becomes "aba")
        "abc",    // Should be NO
        "abcba",  // Should be YES (already palindrome)
        "aaa",    // Should be YES (all same characters)
        "abccba", // Should be YES (already palindrome)
        "abcd",   // Should be NO
        "a",      // Should be YES (single character)
        ""        // Should be YES (empty string)
    };

    std::cout << "ROTATED PALINDROME SOLUTIONS COMPARISON" << std::endl;
    std::cout << "======================================" << std::endl;

    for (const std::string &test_case : test_cases)
    {
        std::cout << "\\nTesting: \"" << test_case << "\"" << std::endl;

        bool result1 = canFormPalindromeBruteForce(test_case);
        bool result2 = canFormPalindromeOptimal(test_case);
        bool result3 = canFormPalindromeMostOptimal(test_case);

        std::cout << "Brute Force:   " << (result1 ? "YES" : "NO") << std::endl;
        std::cout << "Optimal:       " << (result2 ? "YES" : "NO") << std::endl;
        std::cout << "Most Optimal:  " << (result3 ? "YES" : "NO") << std::endl;

        // Verify all methods agree
        if (result1 == result2 && result2 == result3)
        {
            std::cout << "✅ All methods agree!" << std::endl;
        }
        else
        {
            std::cout << "❌ Methods disagree - check implementation!" << std::endl;
        }
    }

    // Detailed demonstration for key examples
    demonstrateRotations("aab");
    demonstrateRotations("abc");

    std::cout << "\\n=== COMPLEXITY ANALYSIS ===" << std::endl;
    std::cout << "Brute Force:   Time O(n²), Space O(n)" << std::endl;
    std::cout << "Optimal:       Time O(n²), Space O(n)" << std::endl;
    std::cout << "Most Optimal:  Time O(n²), Space O(1)" << std::endl;
    std::cout << "\\nReal-world analogy: Like checking if a circular necklace" << std::endl;
    std::cout << "can be read the same forwards/backwards from any starting bead." << std::endl;

    return 0;
}

/**
 * EDGE CASES HANDLED:
 * 1. Empty string (considered palindrome)
 * 2. Single character (always palindrome)
 * 3. Already palindrome string (rotation 0)
 * 4. All same characters (always palindrome)
 * 5. No valid rotation (return false)
 *
 * OPTIMIZATION NOTES:
 * - Early termination when palindrome found
 * - Modular arithmetic for circular access
 * - Avoid unnecessary string creation in most optimal version
 * - Clear variable names for maintainability
 *
 * REAL-WORLD APPLICATIONS:
 * - Circular buffer analysis
 * - DNA sequence analysis (circular chromosomes)
 * - Game development (circular game boards)
 * - Network topology (ring networks)
 */
