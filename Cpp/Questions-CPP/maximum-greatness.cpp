/*
 You are given a 0-indexed integer array nums. You are allowed to permute nums into a new array perm of your choosing. We define the greatness of nums as the number of indices 0 <= i < nums.length for which perm[i] > nums[i]. Your task is to return the maximum possible greatness you can achieve after permuting nums.

Input Format

The first line contains a single integer n, the length of the array nums.
The second line contains n integers, the elements of the array nums.
Output Format

Return the maximum possible greatness you can achieve after permuting nums.
Example 1

Input:
7
1 3 5 2 1 3 1

Output:
4

Explanation:
One of the optimal rearrangements is perm = [2,5,1,3,3,1,1]. At indices 0, 1, 3, and 4, perm[i] > nums[i]. Hence, we return 4.

Example 2

Input:
4
1 2 3 4

Output:
3

Explanation:
We can prove the optimal perm is [2,3,4,1]. At indices 0, 1, and 2, perm[i] > nums[i]. Hence, we return 3.

Constraints

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^9
Do not use inbuilt or library functions that directly solve the problem. Implement the logic manually





*/
#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort

// Function to find the maximum greatness
int maximizeGreatness(std::vector<int>& nums) {
    // Step 1: Sort the array.
    // This allows us to use a greedy approach by pairing the smallest available
    // 'target' elements with the smallest possible 'candidate' elements that are greater.
    std::sort(nums.begin(), nums.end());

    int n = nums.size();
    if (n <= 1) {
        return 0; // Can't find a greater element if there's only one or zero elements.
    }

    int greatness = 0;

    // Step 2: Use a two-pointer approach.
    // 'i' points to the 'target' element from the original sorted array.
    // 'j' points to the 'candidate' element we are trying to use for the permutation.
    int i = 0; // Pointer for the target element
    int j = 1; // Pointer for the candidate element

    // Step 3: Iterate through the array to find matches.
    while (j < n) {
        // If the candidate (nums[j]) is greater than the target (nums[i])
        if (nums[j] > nums[i]) {
            // We found a valid pair.
            greatness++; // Increment the greatness count.
            i++;          // Move to the next target, as this one is satisfied.
            j++;          // Move to the next candidate, as this one is used.
        } else {
            // The candidate nums[j] is not large enough to beat nums[i].
            // We need a larger candidate for the same target.
            j++;          // Move only the candidate pointer forward.
        }
    }

    return greatness;
}

int main() {
    // --- Boilerplate for handling input ---
    // This part is for reading the input as described in the problem.
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    
    // Call the function and print the output
    int result = maximizeGreatness(nums);
    std::cout << result << std::endl;

    return 0;
}
