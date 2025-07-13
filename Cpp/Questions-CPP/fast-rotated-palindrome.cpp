#include <iostream>
#include <string>
#include <algorithm> // Used for the std::reverse function, though a manual check is also easy

// A helper function to check if a string is a palindrome.
// It reads the same forwards and backwards.
bool isPalindrome(const std::string &str)
{
    // Step 1: Create a reversed version of the string.
    std::string reversed_str = str;
    std::reverse(reversed_str.begin(), reversed_str.end());

    // Step 2: Compare the original string with its reversed version.
    // If they are the same, it's a palindrome.
    return str == reversed_str;
}

int main()
{
    // Step 1: Read the input string from the user.
    std::string s;
    std::cin >> s;

    int n = s.length();
    bool found_palindrome = false;

    // A single character string is always a palindrome.
    if (n <= 1)
    {
        found_palindrome = true;
    }
    else
    {
        // Step 2: Loop through all possible rotations of the string.
        // A rotation is like cutting the string at index 'i' and moving the first part to the end.
        for (int i = 0; i < n; ++i)
        {
            // Step 2a: Create the rotated string.
            // s.substr(i) gets the part from index i to the end.
            // s.substr(0, i) gets the part from the beginning up to index i.
            std::string rotated_string = s.substr(i) + s.substr(0, i);

            // Step 2b: Check if this new rotation is a palindrome.
            if (isPalindrome(rotated_string))
            {
                // If we find one, we can set our flag and stop searching.
                found_palindrome = true;
                break;
            }
        }
    }

    // Step 3: Print the final result based on whether we found a palindrome.
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
