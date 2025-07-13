#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    // Step 1: Read input
    int n;
    std::cin >> n;

    std::vector<std::string> arr(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    // Step 2: Convert strings to bitmasks for super fast processing
    std::vector<int> masks;
    std::vector<int> lengths;

    for (const std::string &s : arr)
    {
        int mask = 0;
        bool valid = true;

        // Step 2a: Create bitmask for this string
        for (char c : s)
        {
            int bit = c - 'a'; // Convert 'a' to 0, 'b' to 1, etc.

            // Check if this character already exists in the string
            if (mask & (1 << bit))
            {
                valid = false; // Duplicate character within string
                break;
            }

            mask |= (1 << bit); // Set the bit for this character
        }

        // Step 2b: Only keep strings with unique characters
        if (valid)
        {
            masks.push_back(mask);
            lengths.push_back(s.length());
        }
    }

    int max_length = 0;

    // Step 3: Use bit manipulation magic for super fast checking
    // Try all possible combinations using bit manipulation
    for (int combo = 0; combo < (1 << masks.size()); ++combo)
    {
        int combined_mask = 0;
        int total_length = 0;
        bool valid_combo = true;

        // Step 3a: Check each string in this combination
        for (int i = 0; i < masks.size(); ++i)
        {
            // Check if string i is included in this combination
            if (combo & (1 << i))
            {
                // Step 3b: Check if adding this string creates duplicates
                if (combined_mask & masks[i])
                {
                    valid_combo = false; // Overlapping characters
                    break;
                }

                combined_mask |= masks[i];
                total_length += lengths[i];
            }
        }

        // Step 3c: Update maximum if this combination is valid
        if (valid_combo)
        {
            max_length = std::max(max_length, total_length);
        }
    }

    // Step 4: Output the result
    std::cout << max_length << std::endl;

    return 0;
}

/*
OPTIMAL APPROACH EXPLANATION:

This solution uses bit manipulation for lightning-fast processing:

Key Insight: Since we only have 26 lowercase letters, we can represent each string
as a 32-bit integer (bitmask) where bit i represents whether character ('a' + i)
is present in the string.

How Bitmasks Work:
- "abc" → bits 0,1,2 set → mask = 7 (binary: 111)
- "def" → bits 3,4,5 set → mask = 56 (binary: 111000)
- To check overlap: mask1 & mask2 == 0 means no common characters

Algorithm Steps:
1. Convert each string to a bitmask (O(m) where m is string length)
2. Try all 2^n combinations of strings (same as backtracking)
3. For each combination, use bitwise AND to check conflicts in O(1) time
4. Track the maximum length found

Time Complexity: O(2^n + total_string_length)
- Converting to bitmasks: O(total_string_length)
- Trying combinations: O(2^n * n)
- But each character check is O(1) instead of O(m)
- Much faster in practice due to bitwise operations

Space Complexity: O(n)
- We store one bitmask and length per valid string
- Much less memory than storing actual strings during recursion

Why This Is Faster:
- Bitwise operations (& | ^) are extremely fast (single CPU instruction)
- No string copying or character-by-character checking
- Better cache locality (working with integers instead of strings)

Real-world Analogy:
- Instead of checking each letter individually (like reading a book page by page)
- We create a "fingerprint" for each word and compare fingerprints instantly
- Like comparing two ID cards instead of checking each detail separately

Edge Cases Handled:
- Empty input (max_length stays 0)
- Single string (returns its length if valid)
- All strings have conflicts (returns longest single string)
- All strings are compatible (returns sum of all lengths)
*/
