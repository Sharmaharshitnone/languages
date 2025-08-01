#include <bits/stdc++.h>
using namespace std;

// This function uses a sliding window to find the longest substring of a single character ('T' or 'F')
// that we can create by flipping at most 'k' other characters.
int longestConsecutive(string str, int k, char target)
{
    // Step 1: Initialize our variables.
    // 'left' is the starting point of our window.
    // 'maxLength' will store our final answer.
    // 'flips' counts how many characters we've flipped in the current window.
    int left = 0, maxLength = 0, flips = 0;

    // Step 2: Iterate through the string with the 'right' pointer to expand the window.
    for (int right = 0; right < str.length(); right++)
    {
        
        // Step 3: If the current character is NOT our target, we need to use one of our flips.
        if (str[right] != target)
        {
            flips++;
        }

        // Step 4: Check if our window is now invalid (too many flips).
        // If 'flips' is greater than 'k', we must shrink the window from the left.
        while (flips > k)
        {
            // Step 5: If the character we are about to remove from the window was a flipped one...
            if (str[left] != target)
            {
                // ...we get a flip back.
                flips--;
            }
            // Step 6: Shrink the window by moving the 'left' pointer forward.
            left++;
        }

        // Step 7: The current window [left, right] is now valid.
        // Calculate its length and update 'maxLength' if it's the biggest we've seen so far.
        maxLength = max(maxLength, right - left + 1);
    }

    // Step 8: After the loop finishes, return the maximum length found.
    return maxLength;
}

int main()
{
    // Step 9: Read the answer key string and the number of allowed flips 'k'.
    string str;
    cin >> str;

    int k;
    cin >> k;

    // Step 10: Calculate the longest possible run of 'T's by calling our function.
    int len1 = longestConsecutive(str, k, 'T');
    // Step 11: Calculate the longest possible run of 'F's.
    int len2 = longestConsecutive(str, k, 'F');

    // Step 12: The final answer is the best of the two possibilities.
    int ans = max(len1, len2);

    // Step 13: Print the final answer.
    cout << ans;
    return 0;
}
