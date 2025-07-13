#include <iostream>
#include <vector>
#include <string>

// Helper function to print array nicely
void printArray(const std::vector<int> &arr)
{
    std::cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i];
        if (i < arr.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]";
}

// Helper function to print subarray
void printSubarray(const std::vector<int> &arr, int start, int end)
{
    std::cout << "[";
    for (int i = start; i <= end; i++)
    {
        std::cout << arr[i];
        if (i < end)
            std::cout << ", ";
    }
    std::cout << "]";
}

int main()
{
    // Fixed example for learning
    std::vector<int> nums = {2, 1, 4, 3};
    int left = 2, right = 3;

    std::cout << "=== BOUNDED SUBARRAY MAXIMUM - STEP BY STEP ===" << std::endl;
    std::cout << "Array: ";
    printArray(nums);
    std::cout << std::endl;
    std::cout << "Range: [" << left << ", " << right << "]" << std::endl;
    std::cout << std::endl;

    // Helper function with detailed logging
    auto countSubarraysWithMaxAtMost = [&](int limit) -> long long
    {
        std::cout << "📊 COUNTING SUBARRAYS WITH MAX ≤ " << limit << std::endl;
        std::cout << "----------------------------------------" << std::endl;

        long long count = 0;
        int start = 0;

        for (int end = 0; end < nums.size(); ++end)
        {
            std::cout << "Step " << (end + 1) << ": ";
            std::cout << "Looking at nums[" << end << "] = " << nums[end] << std::endl;

            if (nums[end] > limit)
            {
                std::cout << "  ❌ " << nums[end] << " > " << limit << " (too big!)";
                std::cout << " → Reset window, start = " << (end + 1) << std::endl;
                start = end + 1;
            }
            else
            {
                std::cout << "  ✅ " << nums[end] << " ≤ " << limit << " (good!)";
                std::cout << " → Window: [" << start << ", " << end << "]" << std::endl;

                // Show all subarrays ending at this position
                int subarrays_ending_here = end - start + 1;
                std::cout << "  📝 Subarrays ending at position " << end << ": ";

                for (int i = start; i <= end; i++)
                {
                    printSubarray(nums, i, end);
                    if (i < end)
                        std::cout << ", ";
                }
                std::cout << " = " << subarrays_ending_here << " subarrays" << std::endl;

                count += subarrays_ending_here;
            }

            std::cout << "  📈 Running total: " << count << std::endl;
            std::cout << std::endl;
        }

        std::cout << "🎯 FINAL COUNT FOR MAX ≤ " << limit << ": " << count << std::endl;
        std::cout << std::endl;
        return count;
    };

    // Phase 1: Count subarrays with max ≤ right
    std::cout << "🔍 PHASE 1: Find subarrays with max ≤ " << right << std::endl;
    std::cout << "=" << std::string(50, '=') << std::endl;
    long long count_right = countSubarraysWithMaxAtMost(right);

    // Phase 2: Count subarrays with max ≤ (left-1)
    std::cout << "🔍 PHASE 2: Find subarrays with max ≤ " << (left - 1) << std::endl;
    std::cout << "=" << std::string(50, '=') << std::endl;
    long long count_left = 0;
    if (left > 0)
    {
        count_left = countSubarraysWithMaxAtMost(left - 1);
    }
    else
    {
        std::cout << "left = 0, so no need to subtract anything!" << std::endl;
        std::cout << std::endl;
    }

    // Phase 3: Apply inclusion-exclusion
    std::cout << "🎯 PHASE 3: Apply inclusion-exclusion principle" << std::endl;
    std::cout << "=" << std::string(50, '=') << std::endl;
    std::cout << "Subarrays with max in [" << left << ", " << right << "] = " << std::endl;
    std::cout << "(Subarrays with max ≤ " << right << ") - (Subarrays with max ≤ " << (left - 1) << ")" << std::endl;
    std::cout << "= " << count_right << " - " << count_left << " = " << (count_right - count_left) << std::endl;
    std::cout << std::endl;

    // Verification: Show which subarrays are actually valid
    std::cout << "🔍 VERIFICATION: Let's check all subarrays manually" << std::endl;
    std::cout << "=" << std::string(50, '=') << std::endl;

    int manual_count = 0;
    std::vector<std::string> valid_subarrays;

    for (int start = 0; start < nums.size(); start++)
    {
        for (int end = start; end < nums.size(); end++)
        {
            // Find max in subarray [start, end]
            int max_val = nums[start];
            for (int k = start; k <= end; k++)
            {
                max_val = std::max(max_val, nums[k]);
            }

            // Check if max is in our range
            std::cout << "Subarray ";
            printSubarray(nums, start, end);
            std::cout << " → max = " << max_val;

            if (max_val >= left && max_val <= right)
            {
                std::cout << " ✅ (in range [" << left << ", " << right << "])";
                manual_count++;

                // Store for final summary
                std::string subarray_str = "[";
                for (int i = start; i <= end; i++)
                {
                    subarray_str += std::to_string(nums[i]);
                    if (i < end)
                        subarray_str += ",";
                }
                subarray_str += "]";
                valid_subarrays.push_back(subarray_str);
            }
            else
            {
                std::cout << " ❌ (not in range)";
            }
            std::cout << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "🎉 FINAL ANSWER: " << (count_right - count_left) << std::endl;
    std::cout << "✅ Manual verification: " << manual_count << std::endl;
    std::cout << "Valid subarrays: ";
    for (int i = 0; i < valid_subarrays.size(); i++)
    {
        std::cout << valid_subarrays[i];
        if (i < valid_subarrays.size() - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;

    if (count_right - count_left == manual_count)
    {
        std::cout << "🎊 SUCCESS! Both methods give the same answer!" << std::endl;
    }
    else
    {
        std::cout << "❌ ERROR! Something went wrong..." << std::endl;
    }

    return 0;
}

/*
This program shows you EXACTLY how the algorithm works step by step!

Compile and run:
g++ -o debug debug-bounded-subarray.cpp && ./debug

You'll see:
1. How the sliding window moves
2. Which subarrays are counted at each step
3. How inclusion-exclusion works
4. Verification that our smart method gives the same answer as checking every subarray

Perfect for understanding the algorithm visually!
*/
