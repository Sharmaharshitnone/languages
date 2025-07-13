#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

/**
 * ALL SUBSEQUENCES - OPTIMAL RECURSIVE APPROACH
 *
 * Building from the simple bit manipulation approach, here's a more intuitive
 * recursive solution that's easier to understand and extend.
 *
 * Key insight: At each character, we have 2 choices:
 * 1. Include the current character in subsequence
 * 2. Exclude the current character from subsequence
 *
 * This naturally leads to a recursive solution.
 */

// Helper function to generate subsequences recursively
void generateSubsequencesRecursive(const std::string &original_string,
                                   int current_position,
                                   std::string current_subsequence,
                                   std::set<std::string> &all_subsequences)
{

    // Step 1: Base case - we've processed all characters
    if (current_position == original_string.length())
    {
        // Step 1a: Add the current subsequence if it's not empty
        if (!current_subsequence.empty())
        {
            all_subsequences.insert(current_subsequence);
        }
        return;
    }

    // Step 2: Make two recursive calls - include and exclude current character

    // Step 2a: Exclude current character (don't add it to subsequence)
    generateSubsequencesRecursive(original_string, current_position + 1,
                                  current_subsequence, all_subsequences);

    // Step 2b: Include current character (add it to subsequence)
    generateSubsequencesRecursive(original_string, current_position + 1,
                                  current_subsequence + original_string[current_position],
                                  all_subsequences);
}

// More efficient version using iterative approach with stack simulation
std::vector<std::string> findAllSubsequencesOptimal(const std::string &input_string)
{
    std::set<std::string> unique_subsequences;

    // Step 1: Use recursive helper function
    generateSubsequencesRecursive(input_string, 0, "", unique_subsequences);

    // Step 2: Convert set to vector for output
    std::vector<std::string> result_subsequences;
    for (const std::string &subsequence : unique_subsequences)
    {
        result_subsequences.push_back(subsequence);
    }

    return result_subsequences;
}

// Alternative iterative approach using dynamic programming concept
std::vector<std::string> findAllSubsequencesIterative(const std::string &input_string)
{
    std::set<std::string> unique_subsequences;

    // Step 1: Start with empty set of subsequences
    std::vector<std::string> current_subsequences = {""};

    // Step 2: For each character, double the number of subsequences
    for (char current_char : input_string)
    {
        std::vector<std::string> new_subsequences;

        // Step 2a: Keep all existing subsequences (don't add current character)
        for (const std::string &existing_subseq : current_subsequences)
        {
            new_subsequences.push_back(existing_subseq);
        }

        // Step 2b: Add current character to all existing subsequences
        for (const std::string &existing_subseq : current_subsequences)
        {
            new_subsequences.push_back(existing_subseq + current_char);
        }

        current_subsequences = new_subsequences;
    }

    // Step 3: Remove empty subsequence and add to set to handle duplicates
    for (const std::string &subsequence : current_subsequences)
    {
        if (!subsequence.empty())
        {
            unique_subsequences.insert(subsequence);
        }
    }

    // Step 4: Convert to vector
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

    // Step 6: Find all subsequences using optimal approach
    std::vector<std::string> all_subsequences = findAllSubsequencesOptimal(input_string);

    // Step 7: Output results
    for (const std::string &subsequence : all_subsequences)
    {
        std::cout << subsequence << std::endl;
    }

    return 0;
}

/**
 * OPTIMAL ALGORITHM EXPLANATION:
 *
 * RECURSIVE APPROACH VISUALIZATION for "abc":
 *
 * generateSubsequences("abc", 0, "")
 * ├── generateSubsequences("abc", 1, "")     // Don't include 'a'
 * │   ├── generateSubsequences("abc", 2, "")     // Don't include 'b'
 * │   │   ├── generateSubsequences("abc", 3, "")     // Don't include 'c' → ""
 * │   │   └── generateSubsequences("abc", 3, "c")    // Include 'c' → "c"
 * │   └── generateSubsequences("abc", 2, "b")    // Include 'b'
 * │       ├── generateSubsequences("abc", 3, "b")    // Don't include 'c' → "b"
 * │       └── generateSubsequences("abc", 3, "bc")   // Include 'c' → "bc"
 * └── generateSubsequences("abc", 1, "a")    // Include 'a'
 *     ├── generateSubsequences("abc", 2, "a")     // Don't include 'b'
 *     │   ├── generateSubsequences("abc", 3, "a")     // Don't include 'c' → "a"
 *     │   └── generateSubsequences("abc", 3, "ac")    // Include 'c' → "ac"
 *     └── generateSubsequences("abc", 2, "ab")   // Include 'b'
 *         ├── generateSubsequences("abc", 3, "ab")   // Don't include 'c' → "ab"
 *         └── generateSubsequences("abc", 3, "abc")  // Include 'c' → "abc"
 *
 * ITERATIVE APPROACH VISUALIZATION for "abc":
 *
 * Start: current_subsequences = [""]
 *
 * Process 'a':
 * - Keep existing: [""]
 * - Add 'a' to existing: ["a"]
 * - Result: ["", "a"]
 *
 * Process 'b':
 * - Keep existing: ["", "a"]
 * - Add 'b' to existing: ["b", "ab"]
 * - Result: ["", "a", "b", "ab"]
 *
 * Process 'c':
 * - Keep existing: ["", "a", "b", "ab"]
 * - Add 'c' to existing: ["c", "ac", "bc", "abc"]
 * - Result: ["", "a", "b", "ab", "c", "ac", "bc", "abc"]
 *
 * Remove empty string: ["a", "b", "ab", "c", "ac", "bc", "abc"]
 *
 * WHY THIS IS OPTIMAL:
 *
 * TIME COMPLEXITY: O(n * 2^n)
 * - Still need to generate 2^n subsequences (this is unavoidable)
 * - Each subsequence generation takes O(n) time
 * - Recursive approach has cleaner logic and is easier to understand
 * - Iterative approach avoids recursion stack overhead
 *
 * SPACE COMPLEXITY: O(2^n * n)
 * - Must store all 2^n subsequences
 * - Each subsequence can be up to n characters
 * - Recursive approach uses O(n) stack space
 * - Iterative approach uses O(2^n) temporary space
 *
 * ADVANTAGES OF RECURSIVE APPROACH:
 * - More intuitive and easier to understand
 * - Easier to modify for variations (e.g., subsequences with constraints)
 * - Cleaner code structure
 * - Natural divide-and-conquer approach
 *
 * ADVANTAGES OF ITERATIVE APPROACH:
 * - No recursion stack overhead
 * - Can handle larger inputs without stack overflow
 * - More explicit about memory usage
 * - Can be optimized further with in-place operations
 *
 * Real-world analogy: Like building a family tree where each person
 * can either have children or not. The recursive approach follows each
 * branch naturally, while iterative approach builds level by level.
 */
