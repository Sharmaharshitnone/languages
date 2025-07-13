#include <iostream>
#include <vector>

int main() {
    // Step 1: Read input from user
    int n;
    std::cin >> n;  // How many numbers in the array
    
    int left, right;
    std::cin >> left >> right;  // The range [left, right] we want
    
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];  // Read each number into the array
    }
    
    // Step 2: THE MAGIC TRICK! 
    // Instead of checking every subarray individually (which is slow),
    // we use a clever math trick called "inclusion-exclusion"
    
    // CORE IDEA: 
    // Subarrays with max between [left, right] = 
    // (All subarrays with max ≤ right) - (All subarrays with max ≤ left-1)
    
    // Think of it like this:
    // - If we want numbers between 5 and 10
    // - Count everything ≤ 10, then subtract everything ≤ 4
    // - What's left? Numbers between 5 and 10!
    
    // This helper function counts subarrays where maximum ≤ limit
    auto countSubarraysWithMaxAtMost = [&](int limit) -> long long {
        long long count = 0;
        int start = 0;  // Left edge of our "sliding window"
        
        // Step 2a: Use sliding window technique
        for (int end = 0; end < n; ++end) {
            // If current number is too big, it breaks our rule
            if (nums[end] > limit) {
                // Reset! Start a new window after this bad number
                start = end + 1;
            } else {
                // Current number is good! 
                // Count all valid subarrays ending at position 'end'
                
                // THINK: How many subarrays end at position 'end'?
                // They can start at: start, start+1, start+2, ..., end
                // That's (end - start + 1) different subarrays!
                
                // Example: start=1, end=3
                // Subarrays: [1,3], [2,3], [3,3] = 3 subarrays = (3-1+1)
                count += (end - start + 1);
            }
        }
        
        return count;
    };
    
    // Step 3: Apply our magic formula
    // Count subarrays with max ≤ right
    long long result = countSubarraysWithMaxAtMost(right);
    
    // Subtract subarrays with max ≤ (left-1)
    if (left > 0) {
        result -= countSubarraysWithMaxAtMost(left - 1);
    }
    
    // Step 4: Output the final answer
    std::cout << result << std::endl;
    
    return 0;
}

/*
DETAILED WALKTHROUGH WITH EXAMPLE:
================================

Array: [2, 1, 4, 3], Range: [2, 3]

Step 1: Count subarrays with max ≤ 3
- Position 0: nums[0]=2 ≤ 3 ✓, start=0, end=0
  Subarrays ending at 0: [2] = 1 subarray
- Position 1: nums[1]=1 ≤ 3 ✓, start=0, end=1  
  Subarrays ending at 1: [2,1], [1] = 2 subarrays
- Position 2: nums[2]=4 > 3 ✗, reset start=3
- Position 3: nums[3]=3 ≤ 3 ✓, start=3, end=3
  Subarrays ending at 3: [3] = 1 subarray
Total with max ≤ 3: 1 + 2 + 1 = 4

Step 2: Count subarrays with max ≤ 1  
- Position 0: nums[0]=2 > 1 ✗, reset start=1
- Position 1: nums[1]=1 ≤ 1 ✓, start=1, end=1
  Subarrays ending at 1: [1] = 1 subarray
- Position 2: nums[2]=4 > 1 ✗, reset start=3
- Position 3: nums[3]=3 > 1 ✗, reset start=4
Total with max ≤ 1: 1

Step 3: Final answer = 4 - 1 = 3

The 3 subarrays with max in [2,3] are: [2], [2,1], [3]

WHY THIS WORKS:
- "Max ≤ 3" includes: [2], [2,1], [1], [3]
- "Max ≤ 1" includes: [1] 
- Subtracting gives us: [2], [2,1], [3]
- These are exactly the subarrays with max between 2 and 3!

TIME COMPLEXITY: O(n)
- We scan the array twice (once for each function call)
- Each element is processed in constant time
- Much faster than checking every subarray individually!

SPACE COMPLEXITY: O(1)
- Only using a few variables, no extra arrays needed
*/
