#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <chrono>

/**
 * ALL SUBSEQUENCES - COMPREHENSIVE DEMONSTRATION
 *
 * This program demonstrates all three approaches for generating subsequences
 * and compares their performance and output.
 */

// Approach 1: Bit Manipulation
std::vector<std::string> generateSubsequencesBitManipulation(const std::string &str, bool show_steps = false)
{
    if (show_steps)
    {
        std::cout << "\n=== BIT MANIPULATION APPROACH ===" << std::endl;
        std::cout << "String: \"" << str << "\"" << std::endl;
        std::cout << "Length: " << str.length() << std::endl;
        std::cout << "Total combinations: 2^" << str.length() << " - 1 = " << ((1 << str.length()) - 1) << std::endl;
        std::cout << std::endl;
    }

    std::set<std::string> unique_subsequences;
    int n = str.length();
    int total_combinations = (1 << n) - 1;

    for (int mask = 1; mask <= total_combinations; ++mask)
    {
        std::string subsequence = "";

        if (show_steps)
        {
            std::cout << "Mask " << mask << " (binary: ";
            for (int i = n - 1; i >= 0; --i)
            {
                std::cout << ((mask & (1 << i)) ? '1' : '0');
            }
            std::cout << "): ";
        }

        for (int i = 0; i < n; ++i)
        {
            if (mask & (1 << i))
            {
                subsequence += str[i];
                if (show_steps)
                {
                    std::cout << str[i];
                }
            }
            else if (show_steps)
            {
                std::cout << "-";
            }
        }

        if (show_steps)
        {
            std::cout << " → \"" << subsequence << "\"" << std::endl;
        }

        unique_subsequences.insert(subsequence);
    }

    return std::vector<std::string>(unique_subsequences.begin(), unique_subsequences.end());
}

// Approach 2: Recursion
void generateSubsequencesRecursiveHelper(const std::string &str, int pos, std::string current,
                                         std::set<std::string> &result, bool show_steps = false)
{
    if (pos == str.length())
    {
        if (!current.empty())
        {
            result.insert(current);
            if (show_steps)
            {
                std::cout << "Generated: \"" << current << "\"" << std::endl;
            }
        }
        return;
    }

    // Exclude current character
    generateSubsequencesRecursiveHelper(str, pos + 1, current, result, show_steps);

    // Include current character
    generateSubsequencesRecursiveHelper(str, pos + 1, current + str[pos], result, show_steps);
}

std::vector<std::string> generateSubsequencesRecursive(const std::string &str, bool show_steps = false)
{
    if (show_steps)
    {
        std::cout << "\n=== RECURSIVE APPROACH ===" << std::endl;
        std::cout << "String: \"" << str << "\"" << std::endl;
        std::cout << "Generating all subsequences recursively..." << std::endl;
        std::cout << std::endl;
    }

    std::set<std::string> unique_subsequences;
    generateSubsequencesRecursiveHelper(str, 0, "", unique_subsequences, show_steps);

    return std::vector<std::string>(unique_subsequences.begin(), unique_subsequences.end());
}

// Approach 3: Iterative Building
std::vector<std::string> generateSubsequencesIterative(const std::string &str, bool show_steps = false)
{
    if (show_steps)
    {
        std::cout << "\n=== ITERATIVE BUILDING APPROACH ===" << std::endl;
        std::cout << "String: \"" << str << "\"" << std::endl;
        std::cout << "Building subsequences step by step..." << std::endl;
        std::cout << std::endl;
    }

    std::vector<std::string> current_subsequences = {""};

    if (show_steps)
    {
        std::cout << "Initial: [\"\"]" << std::endl;
    }

    for (int i = 0; i < str.length(); ++i)
    {
        char current_char = str[i];
        std::vector<std::string> new_subsequences;

        // Keep all existing subsequences
        for (const std::string &subseq : current_subsequences)
        {
            new_subsequences.push_back(subseq);
        }

        // Add current character to all existing subsequences
        for (const std::string &subseq : current_subsequences)
        {
            new_subsequences.push_back(subseq + current_char);
        }

        current_subsequences = new_subsequences;

        if (show_steps)
        {
            std::cout << "After adding '" << current_char << "': [";
            for (int j = 0; j < current_subsequences.size(); ++j)
            {
                std::cout << "\"" << current_subsequences[j] << "\"";
                if (j < current_subsequences.size() - 1)
                    std::cout << ", ";
            }
            std::cout << "]" << std::endl;
        }
    }

    // Remove empty subsequence and handle duplicates
    std::set<std::string> unique_subsequences;
    for (const std::string &subseq : current_subsequences)
    {
        if (!subseq.empty())
        {
            unique_subsequences.insert(subseq);
        }
    }

    return std::vector<std::string>(unique_subsequences.begin(), unique_subsequences.end());
}

// Function to measure execution time
template <typename Func>
double measureTime(Func func)
{
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    return duration.count() / 1000.0; // Convert to milliseconds
}

int main()
{
    std::vector<std::string> test_cases = {"abc", "aa", "abcd", "xyz", "aab"};

    std::cout << "ALL SUBSEQUENCES - COMPREHENSIVE DEMONSTRATION" << std::endl;
    std::cout << "=============================================" << std::endl;

    for (const std::string &test_case : test_cases)
    {
        std::cout << "\n"
                  << std::string(60, '=') << std::endl;
        std::cout << "TEST CASE: \"" << test_case << "\"" << std::endl;
        std::cout << std::string(60, '=') << std::endl;

        // Show detailed steps for first test case
        bool show_steps = (test_case == "abc");

        // Test all three approaches
        std::vector<std::string> result1, result2, result3;
        double time1, time2, time3;

        time1 = measureTime([&]()
                            { result1 = generateSubsequencesBitManipulation(test_case, show_steps); });
        time2 = measureTime([&]()
                            { result2 = generateSubsequencesRecursive(test_case, show_steps); });
        time3 = measureTime([&]()
                            { result3 = generateSubsequencesIterative(test_case, show_steps); });

        // Display results
        std::cout << "\n=== RESULTS COMPARISON ===" << std::endl;
        std::cout << "Bit Manipulation: " << result1.size() << " subsequences (" << time1 << " ms)" << std::endl;
        std::cout << "Recursive:        " << result2.size() << " subsequences (" << time2 << " ms)" << std::endl;
        std::cout << "Iterative:        " << result3.size() << " subsequences (" << time3 << " ms)" << std::endl;

        // Verify all approaches give same results
        if (result1 == result2 && result2 == result3)
        {
            std::cout << "✅ All approaches agree!" << std::endl;
        }
        else
        {
            std::cout << "❌ Results differ - check implementation!" << std::endl;
        }

        // Show the actual subsequences
        std::cout << "\nSubsequences: ";
        for (int i = 0; i < result1.size(); ++i)
        {
            std::cout << result1[i];
            if (i < result1.size() - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
    }

    // Performance analysis
    std::cout << "\n"
              << std::string(60, '=') << std::endl;
    std::cout << "PERFORMANCE ANALYSIS" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::cout << "Time Complexity:  O(n × 2^n) for all approaches" << std::endl;
    std::cout << "Space Complexity: O(2^n × n) for storing results" << std::endl;
    std::cout << std::endl;
    std::cout << "Growth rate examples:" << std::endl;
    std::cout << "- 3 characters: 7 subsequences" << std::endl;
    std::cout << "- 4 characters: 15 subsequences" << std::endl;
    std::cout << "- 5 characters: 31 subsequences" << std::endl;
    std::cout << "- 10 characters: 1,023 subsequences" << std::endl;
    std::cout << "- 20 characters: 1,048,575 subsequences (!)" << std::endl;
    std::cout << std::endl;
    std::cout << "Real-world analogy: Like choosing toppings for pizza" << std::endl;
    std::cout << "With n toppings, you have 2^n - 1 non-empty combinations!" << std::endl;

    return 0;
}

/**
 * EXPECTED OUTPUT HIGHLIGHTS:
 *
 * For "abc":
 * - All three approaches will show step-by-step generation
 * - Bit manipulation shows binary masks
 * - Recursive shows the call tree implicitly
 * - Iterative shows building process explicitly
 * - All produce same result: a ab abc ac b bc c
 *
 * Performance observations:
 * - All approaches have same time complexity O(n × 2^n)
 * - Bit manipulation might be slightly faster for small inputs
 * - Recursive has stack overhead
 * - Iterative has predictable memory usage
 * - Differences become negligible for larger inputs due to exponential growth
 *
 * Educational value:
 * - Shows multiple ways to solve the same problem
 * - Demonstrates bit manipulation techniques
 * - Illustrates recursion vs iteration trade-offs
 * - Highlights the exponential nature of the problem
 */
