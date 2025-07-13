#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

/**
 * ALL SUBSEQUENCES OF A STRING - SIMPLE APPROACH
 *
 * Problem in simple terms:
 * Given a string, find all possible subsequences (non-empty sequences you can make
 * by deleting some or no characters without changing the order of remaining ones).
 *
 * Examples:
 * 1. "abc" → subsequences: "a", "ab", "abc", "ac", "b", "bc", "c" (7 total)
 * 2. "aa" → subsequences: "a", "a", "aa" (3 total, includes duplicates)
 *
 * Key insight: For each character, we have 2 choices - include it or skip it.
 * This gives us 2^n total possibilities (includin1g empty subsequence).
 *
 * Constraints:
 * - String contains only lowercase English letters a-z
 * - Need to find all non-empty subsequences
 */

std::vector<std::string> findAllSubsequences(const std::string &input_string)
{
    std::set<std::string> unique_subsequences; // Use set to handle duplicates
    int string_length = input_string.length();

    // Step 1: Generate all possible subsequences using bit manipulation
    // We'll use numbers from 1 to 2^n - 1 (excluding 0 which represents empty subsequence)
    int total_subsequences = (1 << string_length) - 1; // 2^n - 1

    for (int subsequence_mask = 1; subsequence_mask <= total_subsequences; ++subsequence_mask)
    {
        std::string current_subsequence = "";

        // Step 2: For each bit position, check if we should include that character
        for (int character_position = 0; character_position < string_length; ++character_position)
        {
            // Step 2a: Check if bit at position 'character_position' is set
            if (subsequence_mask & (1 << character_position))
            {
                // Include this character in the subsequence
                current_subsequence += input_string[character_position];
            }
        }

        // Step 3: Add the subsequence to our set (automatically handles duplicates)
        unique_subsequences.insert(current_subsequence);
    }

    // Step 4: Convert set to vector for easier output
    std::vector<std::string> result_subsequences;
    for (const std::string &subsequence : unique_subsequences)
    {
        result_subsequences.push_back(subsequence);
    }

    return result_subsequences;
}

int main()
{
    std::string input_string;

    // Step 5: Read input
    std::cin >> input_string;

    // Step 6: Find all subsequences
    std::vector<std::string> all_subsequences = findAllSubsequences(input_string);

    // Step 7: Output all subsequences
    for (const std::string &subsequence : all_subsequences)
    {
        std::cout << subsequence << std::endl;
    }

    return 0;
}

/**
 * ALGORITHM EXPLANATION WITH VISUAL EXAMPLE:
 *
 * For input "abc":
 *
 * We use bit manipulation where each bit represents whether to include a character:
 *
 * Binary representation:
 * 001 → include only 'a' → "a"
 * 010 → include only 'b' → "b"
 * 011 → include 'a' and 'b' → "ab"
 * 100 → include only 'c' → "c"
 * 101 → include 'a' and 'c' → "ac"
 * 110 → include 'b' and 'c' → "bc"
 * 111 → include all → "abc"
 *
 * Step-by-step for subsequence_mask = 5 (binary 101):
 *
 * String: "abc"
 * Positions: 0 1 2
 *
 * Mask 5 = 101 in binary
 *
 * Position 0: 101 & 001 = 001 (true) → include 'a'
 * Position 1: 101 & 010 = 000 (false) → skip 'b'
 * Position 2: 101 & 100 = 100 (true) → include 'c'
 *
 * Result: "ac"
 *
 * BIT MANIPULATION TRICKS:
 *
 * 1. (1 << n) gives us 2^n (left shift = multiply by 2)
 * 2. (mask & (1 << pos)) checks if bit at position 'pos' is set
 * 3. We start from 1 to skip empty subsequence (mask 0)
 *
 * TIME COMPLEXITY: O(n * 2^n)
 * - We generate 2^n subsequences (exponential in string length)
 * - Each subsequence takes O(n) time to build
 * - Set operations add O(log k) where k is number of unique subsequences
 * - Total: O(n * 2^n * log k)
 *
 * Real-world analogy: Like choosing toppings for a pizza. With n toppings,
 * you have 2^n ways to choose (include or exclude each topping).
 * With 10 toppings, that's 1024 different pizzas!
 *
 * SPACE COMPLEXITY: O(k * n) where k is number of unique subsequences
 * - We store all unique subsequences in a set
 * - Each subsequence can be up to n characters long
 * - In worst case (no duplicates), k = 2^n - 1
 *
 * EDGE CASES HANDLED:
 * - Empty string: no subsequences
 * - Single character: one subsequence (the character itself)
 * - All same characters: handles duplicates correctly using set
 * - Maximum string length: works for reasonable input sizes
 */
