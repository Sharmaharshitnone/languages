
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// This function calculates the maximum number of pairs in an array that sum up to k.
// It uses a hash map to store the frequency of each number.
int maxOperations(std::vector<int>& nums, int k) {
    // A hash map to store the frequency of each number in the array.
    // Key: number, Value: count of that number.
    std::unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }

    int operations = 0;

    // Iterate through the frequency map to find pairs.
    for (auto const& [num, count] : freq) {
        int complement = k - num;

        // Case 1: The number is its own complement (e.g., num = 3, k = 6)
        if (num == complement) {
            // We can form count / 2 pairs.
            // For example, if we have four 3s, we can make two pairs.
            operations += count / 2;
        } 
        // Case 2: The number and its complement are different.
        // We only process this case when num < complement to avoid double-counting pairs.
        // For example, we count (2, 4) but not (4, 2).
        else if (num < complement && freq.count(complement)) {
            // The number of pairs we can form is limited by the minimum count
            // of the two numbers.
            int complement_count = freq.at(complement);
            operations += std::min(count, complement_count);
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
