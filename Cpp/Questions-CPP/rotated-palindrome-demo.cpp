#include <iostream>
#include <string>
#include <vector>

// Helper function to check if string is palindrome
bool isPalindrome(const std::string &s)
{
    int left = 0, right = s.length() - 1;
    while (left < right)
    {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

// Function to demonstrate all rotations
void demonstrateRotations(const std::string &s)
{
    std::cout << "=== ROTATED PALINDROME DEMONSTRATION ===" << std::endl;
    std::cout << "Original string: \"" << s << "\"" << std::endl;
    std::cout << std::endl;

    if (s.empty())
    {
        std::cout << "Empty string is considered a palindrome." << std::endl;
        return;
    }

    if (s.length() == 1)
    {
        std::cout << "Single character is always a palindrome." << std::endl;
        return;
    }

    std::cout << "Checking all possible rotations:" << std::endl;
    std::cout << std::endl;

    int n = s.length();
    bool found_palindrome = false;
    std::vector<std::string> palindromic_rotations;

    // Show all rotations
    for (int i = 0; i < n; ++i)
    {
        // Create rotation by cutting at position i
        std::string rotation = s.substr(i) + s.substr(0, i);
        bool is_palin = isPalindrome(rotation);

        std::cout << "Rotation " << i << ": \"" << rotation << "\"";

        if (is_palin)
        {
            std::cout << " ✅ PALINDROME!";
            found_palindrome = true;
            palindromic_rotations.push_back(rotation);
        }
        else
        {
            std::cout << " ❌ Not a palindrome";
        }
        std::cout << std::endl;

        // Show how this rotation was created
        if (i > 0)
        {
            std::cout << "   (Created by moving first " << i << " character(s) to the end)" << std::endl;
        }
        else
        {
            std::cout << "   (Original string)" << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << "=== RESULT ===" << std::endl;
    if (found_palindrome)
    {
        std::cout << "✅ YES! Found " << palindromic_rotations.size() << " palindromic rotation(s):" << std::endl;
        for (const auto &p : palindromic_rotations)
        {
            std::cout << "   \"" << p << "\"" << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Answer: Yes, the rotated string is a palindrome." << std::endl;
    }
    else
    {
        std::cout << "❌ NO! No rotation forms a palindrome." << std::endl;
        std::cout << "Answer: No, the rotated string is not a palindrome." << std::endl;
    }
}

// Function to show how the optimal algorithm works
void demonstrateOptimalAlgorithm(const std::string &s)
{
    std::cout << std::endl;
    std::cout << "=== OPTIMAL ALGORITHM WALKTHROUGH ===" << std::endl;
    std::cout << "Instead of creating new strings, we use index calculations:" << std::endl;
    std::cout << std::endl;

    int n = s.length();

    for (int start = 0; start < n && start < 3; ++start)
    { // Show first 3 for demo
        std::cout << "Checking rotation starting at position " << start << ":" << std::endl;

        bool is_palindrome = true;
        for (int i = 0; i < n / 2; ++i)
        {
            int left_idx = (start + i) % n;
            int right_idx = (start + n - 1 - i) % n;

            std::cout << "  Compare s[" << left_idx << "]='" << s[left_idx]
                      << "' with s[" << right_idx << "]='" << s[right_idx] << "'";

            if (s[left_idx] != s[right_idx])
            {
                std::cout << " ❌ Mismatch!" << std::endl;
                is_palindrome = false;
                break;
            }
            else
            {
                std::cout << " ✅ Match!" << std::endl;
            }
        }

        std::cout << "  Result: " << (is_palindrome ? "PALINDROME" : "Not palindrome") << std::endl;
        std::cout << std::endl;

        if (is_palindrome)
        {
            std::cout << "Found palindrome! Algorithm can stop here." << std::endl;
            break;
        }
    }
}

int main()
{
    std::vector<std::string> test_cases = {"aab", "abc", "a", "abcba", "racecar"};

    for (const auto &test : test_cases)
    {
        demonstrateRotations(test);
        if (test.length() > 1 && test.length() <= 5)
        {
            demonstrateOptimalAlgorithm(test);
        }
        std::cout << std::string(60, '=') << std::endl;
        std::cout << std::endl;
    }

    return 0;
}

/*
This demonstration shows:

1. How rotations are created by moving characters from start to end
2. Which rotations form palindromes
3. How the optimal algorithm works with index calculations
4. Why the optimal approach is more efficient

Key insights:
- Rotation at position i: s.substr(i) + s.substr(0, i)
- Optimal check uses: (start + offset) % n for index calculation
- We can stop as soon as we find one palindromic rotation
- No need to create new strings, just calculate indices
*/
