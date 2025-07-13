#include <iostream>
#include <string>

/**
 * ROTATED PALINDROME - OPTIMAL SOLUTION
 *
 * Building up from the simple approach, here's the most efficient way:
 * Instead of creating new strings for each rotation, we can check palindromes
 * directly using modular arithmetic (circular array access).
 *
 * Key insight: We don't need to actually create rotated strings!
 * We can just pretend the string is circular and check palindromes directly.
 */

// Step 1: Optimal palindrome check without creating new strings
bool isPalindromeAtRotation(const std::string &original_string, int start_position)
{
    int string_length = original_string.length();

    // Step 1a: Check from both ends of the "virtual" rotated string
    for (int check_distance = 0; check_distance < string_length / 2; ++check_distance)
    {
        // Step 1b: Calculate actual positions in original string using modular arithmetic
        // This is like wrapping around a circular array
        int left_actual_index = (start_position + check_distance) % string_length;
        int right_actual_index = (start_position + string_length - 1 - check_distance) % string_length;

        // Step 1c: Compare characters at symmetric positions
        if (original_string[left_actual_index] != original_string[right_actual_index])
        {
            return false; // Found mismatch, not palindrome
        }
    }

    return true; // All positions matched, it's a palindrome
}

int main()
{
    std::string input_string;

    // Step 2: Read input
    std::cin >> input_string;

    int string_length = input_string.length();
    bool found_palindromic_rotation = false;

    // Step 3: Handle edge cases
    if (string_length <= 1)
    {
        found_palindromic_rotation = true;
    }
    else
    {
        // Step 4: Try each possible starting position (rotation)
        for (int start_pos = 0; start_pos < string_length; ++start_pos)
        {
            // Step 4a: Check if rotation starting at 'start_pos' is palindrome
            if (isPalindromeAtRotation(input_string, start_pos))
            {
                found_palindromic_rotation = true;
                break; // Found one! Early exit to save time
            }
        }
    }

    // Step 5: Output result
    if (found_palindromic_rotation)
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
 * OPTIMAL ALGORITHM EXPLANATION:
 *
 * Visual example for "aab" with start_position = 1:
 *
 * Original string: a a b
 *                 ↑ ↑ ↑
 *                 0 1 2
 *
 * Virtual rotation starting at position 1: "aba"
 * But we don't create this string! Instead:
 *
 * Check distance 0:
 * - left_index = (1 + 0) % 3 = 1 → 'a'
 * - right_index = (1 + 3 - 1 - 0) % 3 = 0 → 'a'
 * - Match! ✓
 *
 * Check distance 1:
 * - left_index = (1 + 1) % 3 = 2 → 'b'
 * - right_index = (1 + 3 - 1 - 1) % 3 = 1 → 'a'
 * - We only check up to length/2, so we're done
 *
 * Middle character (index 1) doesn't need checking in palindrome
 * Result: Palindrome found!
 *
 * WHY THIS IS BETTER:
 *
 * TIME COMPLEXITY: O(n²) - same as before
 * - Still n rotations to try
 * - Each palindrome check is O(n)
 * - But we avoid string creation overhead
 *
 * SPACE COMPLEXITY: O(1) - much better!
 * - No temporary strings created
 * - Only use a few integer variables
 * - Constant extra space regardless of input size
 *
 * Real-world analogy: Like checking a circular necklace without taking it apart.
 * Instead of making n copies of the necklace, we just look at it from different
 * starting positions. Same time to check, but no extra storage needed!
 *
 * MODULAR ARITHMETIC TRICK:
 * (start_position + offset) % string_length
 *
 * This wraps around when we go past the end:
 * For string length 3:
 * - Position 2 + 1 = 3 → 3 % 3 = 0 (wraps to start)
 * - Position 1 + 2 = 3 → 3 % 3 = 0 (wraps to start)
 *
 * It's like a clock face - after 12 comes 1 again!
 */
