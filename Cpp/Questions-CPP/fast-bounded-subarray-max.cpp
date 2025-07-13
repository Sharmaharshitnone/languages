#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // Step 1: Read input
    int n;
    std::cin >> n;

    int left, right;
    std::cin >> left >> right;

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> nums[i];
    }

    // Step 2: Count valid subarrays using brute force
    int count = 0;

    // Try all possible subarrays
    for (int start = 0; start < n; ++start)
    {
        int current_max = nums[start];

        for (int end = start; end < n; ++end)
        {
            // Update the maximum for current subarray [start, end]
            current_max = std::max(current_max, nums[end]);

            // Step 3: Check if this subarray's maximum is in range
            if (current_max >= left && current_max <= right)
            {
                count++;
            }

            // Step 4: Optimization - if max exceeds right, no point extending this subarray
            if (current_max > right)
            {
                break;
            }
        }
    }

    // Step 5: Output the result
    std::cout << count << std::endl;

    return 0;
}
