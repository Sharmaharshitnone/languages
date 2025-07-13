#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // Step 1: Read input
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> nums[i];
    }

    int k;
    std::cin >> k;

    // Step 2: Initialize sliding window variables
    int left = 0;       // Left boundary of our sliding window
    int zero_count = 0; // Count of zeros in current window
    int max_length = 0; // Maximum valid window size found so far

    // Step 3: Expand the window using the right pointer
    for (int right = 0; right < n; ++right)
    {
        // Add the current element to our window
        if (nums[right] == 0)
        {
            zero_count++;
        }

        // Step 4: Shrink the window if it has too many zeros
        // We need to maintain the invariant: zero_count <= k
        while (zero_count > k)
        {
            // Remove the leftmost element from our window
            if (nums[left] == 0)
            {
                zero_count--;
            }
            left++;
        }

        // Step 5: Update the maximum window size
        // Current window size = right - left + 1
        // This window contains at most k zeros, so we can flip them all
        int current_length = right - left + 1;
        max_length = std::max(max_length, current_length);
    }

    // Step 6: Output the result
    std::cout << max_length << std::endl;

    return 0;
}
