#include <iostream>
#include <string>

/**
 * ROTATED PALINDROME PROBLEM - SIMPLE APPROACH FIRST
 *
 * Problem in simple terms:
 * Given a string, can we rotate it (move some characters from front to back
 * or back to front) to make it read the same forwards and backwards?
 *
 * Examples:
 * 1. "aab" → rotate right once → "baa" → rotate right again → "aba" → YES!
 * 2. "abc" → try all rotations → "abc", "bca", "cab" → none are palindromes → NO
 *
 * Constraints:
 * - String length: 1 to 10,000 characters
 * - Only printable ASCII characters (letters and digits)
 */

// Step 1: Helper function to check if a string is palindrome
bool isPalindrome(const std::string &text)
{
    int left_pointer = 0;
    int right_pointer = text.length() - 1;

    // Step 1a: Compare characters from both ends moving inward
    while (left_pointer < right_pointer)
    {
        if (text[left_pointer] != text[right_pointer])
        {
            return false; // Found different characters, not palindrome
        }
        left_pointer++;  // Move left pointer right
        right_pointer--; // Move right pointer left
    }

    return true; // All characters matched, it's a palindrome
}

int main()
{
    std::string input_string;

    // Step 2: Read the input string
    std::cin >> input_string;

    int string_length = input_string.length();
    bool found_palindrome = false;

    // Step 3: Handle edge cases first
    if (string_length <= 1)
    {
        // Empty string or single character is always a palindrome
        found_palindrome = true;
    }
    else
    {
        // Step 4: Try all possible rotations
        // Think of it like a circular necklace - we try starting from each bead
        for (int rotation_position = 0; rotation_position < string_length; ++rotation_position)
        {
            // Step 4a: Create rotated string by cutting at position 'rotation_position'
            // For "aab" at position 1: "ab" + "a" = "aba"
            std::string rotated_string = input_string.substr(rotation_position) +
                                         input_string.substr(0, rotation_position);

            // Step 4b: Check if this rotation is a palindrome
            if (isPalindrome(rotated_string))
            {
                found_palindrome = true;
                break; // Found one! No need to check more rotations
            }
        }
    }

    // Step 5: Output the result based on problem requirements
    if (found_palindrome)
    {
        std::cout << "Yes, the rotated string is a palindrome." << std::endl;
    }
    else
    {
        std::cout << "No, the rotated string is not a palindrome." << std::endl;
    }

    return 0;
}

/**
 * ALGORITHM EXPLANATION:
 *
 * Step-by-step visual for "aab":
 *
 * Original: a a b
 *          ↑ ↑ ↑
 *          0 1 2
 *
 * Rotation 0: cut at position 0 → "" + "aab" = "aab"
 * Check: a≠b (first vs last) → NOT palindrome
 *
 * Rotation 1: cut at position 1 → "ab" + "a" = "aba"
 * Check: a=a (first vs last), b=b (middle) → IS palindrome! ✓
 *
 * Result: YES
 *
 * TIME COMPLEXITY: O(n²)
 * - We try n different rotations
 * - Each rotation takes O(n) time to create the string
 * - Each palindrome check takes O(n) time
 * - Total: n × (n + n) = O(n²)
 *
 * Real-world analogy: Like checking if a circular necklace with n beads
 * can be read the same forwards/backwards from any starting bead.
 * With 10× more beads, this takes about 100× longer (n² growth).
 *
 * SPACE COMPLEXITY: O(n)
 * - We create new rotated strings of length n
 * - The substr operations create temporary strings
 *
 * EDGE CASES HANDLED:
 * - Empty string: considered palindrome
 * - Single character: always palindrome
 * - Already palindrome: found at rotation 0
 * - All same characters: always palindrome
 * - No valid rotation: returns false
 */
