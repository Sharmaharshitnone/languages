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

    // Step 2: Try all possible subarrays (brute force approach)
    int max_length = 0;

    for (int start = 0; start < n; ++start)
    {
        int zero_count = 0;

        for (int end = start; end < n; ++end)
        {
            // Step 3: Count zeros in current subarray [start, end]
            if (nums[end] == 0)
            {
                zero_count++;
            }

            // Step 4: Check if this subarray is valid (can be made all 1s)
            if (zero_count <= k)
            {
                // We can flip all zeros in this subarray to make it all 1s
                int current_length = end - start + 1;
                max_length = std::max(max_length, current_length);
            }
            else
            {
                // Too many zeros, can't make this subarray all 1s with k flips
                // No point extending this subarray further
                break;
            }
        }
    }

    // Step 5: Output the result
    std::cout << max_length << std::endl;

    return 0;
}
