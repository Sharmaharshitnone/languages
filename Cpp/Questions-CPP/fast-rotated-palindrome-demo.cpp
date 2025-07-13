#include <iostream>
#include <string>
#include <vector>

/**
 * ROTATED PALINDROME - VISUAL DEMONSTRATION
 *
 * This program shows exactly how the algorithm works step by step
 * with ASCII diagrams to help understand the rotation process.
 */

// Helper function to check palindrome
bool isPalindrome(const std::string &str)
{
    int left = 0, right = str.length() - 1;
    while (left < right)
    {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
}

// Function to visualize all rotations
void visualizeRotations(const std::string &original)
{
    std::cout << "\n=== ROTATED PALINDROME VISUALIZATION ===" << std::endl;
    std::cout << "Original string: \"" << original << "\"" << std::endl;
    std::cout << std::endl;

    if (original.empty())
    {
        std::cout << "Empty string is considered a palindrome." << std::endl;
        return;
    }

    if (original.length() == 1)
    {
        std::cout << "Single character is always a palindrome." << std::endl;
        return;
    }

    int n = original.length();

    // Show string positions
    std::cout << "String positions:" << std::endl;
    std::cout << "Characters: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << original[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Positions:  ";
    for (int i = 0; i < n; i++)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    // Show all rotations
    std::cout << "All possible rotations:" << std::endl;
    std::cout << "========================" << std::endl;

    bool found_palindrome = false;

    for (int rotation = 0; rotation < n; rotation++)
    {
        // Create rotated string
        std::string rotated = original.substr(rotation) + original.substr(0, rotation);
        bool is_palindrome = isPalindrome(rotated);

        std::cout << "Rotation " << rotation << ": ";

        // Show the cutting process
        if (rotation == 0)
        {
            std::cout << "\"\" + \"" << original << "\" = ";
        }
        else
        {
            std::cout << "\"" << original.substr(rotation) << "\" + \""
                      << original.substr(0, rotation) << "\" = ";
        }

        std::cout << "\"" << rotated << "\"";

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

        // Show palindrome check process
        if (is_palindrome)
        {
            std::cout << "   Palindrome check: ";
            int left = 0, right = rotated.length() - 1;
            while (left < right)
            {
                std::cout << rotated[left] << "=" << rotated[right] << " ";
                left++;
                right--;
            }
            std::cout << "✓" << std::endl;
        }
        std::cout << std::endl;
    }

    // Final result
    std::cout << "=== FINAL RESULT ===" << std::endl;
    if (found_palindrome)
    {
        std::cout << "YES - At least one rotation forms a palindrome!" << std::endl;
    }
    else
    {
        std::cout << "NO - No rotation forms a palindrome." << std::endl;
    }
}

// Function to show the modular arithmetic approach
void showModularArithmetic(const std::string &original)
{
    std::cout << "\n=== MODULAR ARITHMETIC APPROACH ===" << std::endl;
    std::cout << "Instead of creating new strings, we use circular indexing:" << std::endl;
    std::cout << std::endl;

    int n = original.length();
    if (n <= 1)
        return;

    // Show one example rotation using modular arithmetic
    int example_start = 1; // Use rotation starting at position 1
    if (n <= 1)
        example_start = 0;

    std::cout << "Example: Checking rotation starting at position " << example_start << std::endl;
    std::cout << "Original string: \"" << original << "\"" << std::endl;
    std::cout << "Positions:       ";
    for (int i = 0; i < n; i++)
    {
        std::cout << " " << i;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Modular arithmetic for circular access:" << std::endl;
    for (int distance = 0; distance < n / 2; distance++)
    {
        int left_idx = (example_start + distance) % n;
        int right_idx = (example_start + n - 1 - distance) % n;

        std::cout << "Distance " << distance << ": ";
        std::cout << "left_idx = (" << example_start << " + " << distance << ") % " << n << " = " << left_idx;
        std::cout << " → '" << original[left_idx] << "'";
        std::cout << ", right_idx = (" << example_start << " + " << n << " - 1 - " << distance << ") % " << n << " = " << right_idx;
        std::cout << " → '" << original[right_idx] << "'";

        if (original[left_idx] == original[right_idx])
        {
            std::cout << " ✅ Match";
        }
        else
        {
            std::cout << " ❌ No match";
        }
        std::cout << std::endl;
    }
}

int main()
{
    // Test cases that demonstrate different scenarios
    std::vector<std::string> test_cases = {
        "aab",  // Can form palindrome
        "abc",  // Cannot form palindrome
        "aba",  // Already palindrome
        "abcd", // Cannot form palindrome
        "a",    // Single character
        ""      // Empty string
    };

    std::cout << "ROTATED PALINDROME STEP-BY-STEP DEMONSTRATION" << std::endl;
    std::cout << "=============================================" << std::endl;

    for (const std::string &test : test_cases)
    {
        visualizeRotations(test);

        if (test.length() > 1)
        {
            showModularArithmetic(test);
        }

        std::cout << "\n"
                  << std::string(60, '-') << std::endl;
    }

    std::cout << "\nKEY INSIGHTS:" << std::endl;
    std::cout << "• Rotation = cutting string at position i and swapping parts" << std::endl;
    std::cout << "• We try all n possible cut positions" << std::endl;
    std::cout << "• Palindrome check uses two pointers from ends" << std::endl;
    std::cout << "• Modular arithmetic (%) handles circular wrapping" << std::endl;
    std::cout << "• Time: O(n²), Space: O(1) with optimal approach" << std::endl;

    return 0;
}

/**
 * VISUAL EXAMPLE OUTPUT:
 *
 * For input "aab":
 *
 * Original string: "aab"
 *
 * String positions:
 * Characters: a a b
 * Positions:  0 1 2
 *
 * All possible rotations:
 * ========================
 * Rotation 0: "" + "aab" = "aab" ❌ Not palindrome
 *
 * Rotation 1: "ab" + "a" = "aba" ✅ PALINDROME!
 *    Palindrome check: a=a ✓
 *
 * Rotation 2: "b" + "aa" = "baa" ❌ Not palindrome
 *
 * === FINAL RESULT ===
 * YES - At least one rotation forms a palindrome!
 */
