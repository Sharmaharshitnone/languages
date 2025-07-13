#include <iostream>
#include <vector>

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

    // Step 2: Use contribution counting approach
    long long total_count = 0;

    for (int i = 0; i < n; ++i)
    {
        // Only consider elements that can be valid maximums
        if (nums[i] >= left && nums[i] <= right)
        {

            // Step 3: Count elements to the left that are <= nums[i]
            int left_count = 0;
            for (int j = i - 1; j >= 0; --j)
            {
                if (nums[j] <= nums[i])
                {
                    left_count++;
                }
                else
                {
                    break; // Found a larger element, stop
                }
            }

            // Step 4: Count elements to the right that are <= nums[i]
            int right_count = 0;
            for (int j = i + 1; j < n; ++j)
            {
                if (nums[j] <= nums[i])
                {
                    right_count++;
                }
                else
                {
                    break; // Found a larger element, stop
                }
            }

            // Step 5: Calculate contribution of nums[i] as maximum
            // Total subarrays with nums[i] as max = (left_count + 1) * (right_count + 1)
            // +1 because we include the element itself
            long long contribution = (long long)(left_count + 1) * (right_count + 1);
            total_count += contribution;
        }
    }

    // Step 6: Handle overlapping - we need a more sophisticated approach
    // The above approach overcounts, so let's use a different strategy

    // Reset and use a simpler but correct approach
    total_count = 0;

    // For each position, count subarrays ending at that position
    for (int i = 0; i < n; ++i)
    {
        int current_max = nums[i];

        // Go backwards from position i
        for (int j = i; j >= 0; --j)
        {
            current_max = std::max(current_max, nums[j]);

            // Check if subarray [j, i] has valid maximum
            if (current_max >= left && current_max <= right)
            {
                total_count++;
            }

            // If maximum exceeds right, no point going further left
            if (current_max > right)
            {
                break;
            }
        }
    }

    // Step 7: Output the result
    std::cout << total_count << std::endl;

    return 0;
}
