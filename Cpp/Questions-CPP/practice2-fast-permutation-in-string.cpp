#include <iostream>
#include <string>
#include <vector>

int main()
{
    // Step 1: Read input strings
    std::string s1, s2;
    std::cin >> s1 >> s2;

    // Step 2: Early exit if s1 is longer than s2
    if (s1.length() > s2.length())
    {
        std::cout << "false" << std::endl;
        return 0;
    }

    // Step 3: Count character frequencies in s1 (target pattern)
    std::vector<int> s1_freq(26, 0); // 26 lowercase letters
    for (char c : s1)
    {
        s1_freq[c - 'a']++;
    }

    int window_size = s1.length();
    std::vector<int> window_freq(26, 0); // Current window frequencies

    // Step 4: Initialize the first window
    for (int i = 0; i < window_size; ++i)
    {
        window_freq[s2[i] - 'a']++;
    }

    // Step 5: Check if the first window matches
    if (s1_freq == window_freq)
    {
        std::cout << "true" << std::endl;
        return 0;
    }

    // Step 6: Slide the window through the rest of s2
    for (int i = window_size; i < s2.length(); ++i)
    {
        // Add the new character (right side of window)
        window_freq[s2[i] - 'a']++;

        // Remove the old character (left side of window)
        window_freq[s2[i - window_size] - 'a']--;

        // Check if current window matches s1's frequency pattern
        if (s1_freq == window_freq)
        {
            std::cout << "true" << std::endl;
            return 0;
        }
    }

    // Step 7: No matching window found
    std::cout << "false" << std::endl;
    return 0;
}
