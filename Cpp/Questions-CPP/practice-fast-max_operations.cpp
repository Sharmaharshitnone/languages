
#include <iostream>
#include <vector>
#include <algorithm>

// This function calculates the maximum number of pairs that sum up to k.
// It uses the Two Pointers technique after sorting the array.
int maxOperations(std::vector<int>& nums, int k) {
    // First, sort the array. This allows us to use the two-pointer approach.
    std::sort(nums.begin(), nums.end());

    // Initialize two pointers, one at the beginning and one at the end.
    int left = 0;
    int right = nums.size() - 1;
    int operations = 0;

    // Loop until the two pointers meet or cross each other.
    while (left < right) {
        long long current_sum = (long long)nums[left] + nums[right];

        // Case 1: The sum of the two numbers is exactly k.
        if (current_sum == k) {
            // We found a pair!
            operations++;
            left++;   // Move the left pointer to the right.
            right--;  // Move the right pointer to the left.
        } 
        // Case 2: The sum is less than k.
        else if (current_sum < k) {
            // The sum is too small. We need a larger number, so we move the left pointer.
            left++;
        } 
        // Case 3: The sum is greater than k.
        else {
            // The sum is too big. We need a smaller number, so we move the right pointer.
            right--;
        }
    }

    return operations;
}

int main() {
    int n, k;
    // Read the size of the array and the target sum k.
    std::cin >> n >> k;

    // Create a vector of size n and read the elements from the input.
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    // Call the function and print the result.
    std::cout << maxOperations(nums, k) << std::endl;

    return 0;
}
