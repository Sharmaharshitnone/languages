/*
 * ## Problem: Non-decreasing Subsequences
 *
 * Given an integer array `nums`, find all the different possible
 * non-decreasing subsequences of the given array that have at least two elements.
 * The result should be in lexicographically sorted order.
 *
 * Example:
 * Input: nums = [4, 6, 7, 7]
 * Output:
 * 4 6
 * 4 6 7
 * 4 6 7 7
 * 4 7
 * 4 7 7
 * 6 7
 * 6 7 7
 * 7 7
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

// Main function to find all subsequences
std::vector<std::vector<int>> findSubsequences(std::vector<int>& nums);

// Recursive helper function to perform backtracking
void solve(int startIndex, std::vector<int>& currentSub, std::vector<int>& nums, std::set<std::vector<int>>& resultSet);

int main() {
    // Read input length and array
    int n;
    std::cin >> n;
    std::vector<int> input(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> input[i];
    }

    // Generate and print subsequences
    std::vector<std::vector<int>> allSubsequences = findSubsequences(input);
    for (const auto& one_subsequence : allSubsequences) {
        for (size_t i = 0; i < one_subsequence.size(); ++i) {
            std::cout << one_subsequence[i] << (i == one_subsequence.size() - 1 ? "" : " ");
        }
        std::cout << "\n";
    }

    return 0;
}

// Main function that sets up the process
std::vector<std::vector<int>> findSubsequences(std::vector<int>& nums) {
    // A set automatically handles duplicates and keeps subsequences sorted lexicographically.
    std::set<std::vector<int>> resultSet;
    std::vector<int> currentSub;

    // Start the recursive backtracking process from the beginning of the array.
    solve(0, currentSub, nums, resultSet);

    // Convert the set to a vector for the final return type.
    return std::vector<std::vector<int>>(resultSet.begin(), resultSet.end());
}

// The recursive backtracking function
void solve(int startIndex, std::vector<int>& currentSub, std::vector<int>& nums, std::set<std::vector<int>>& resultSet) {
    // If the current subsequence has at least 2 elements, it's a valid answer.
    if (currentSub.size() >= 2) {
        resultSet.insert(currentSub);
    }

    // Iterate through the array starting from 'startIndex'
    for (int i = startIndex; i < nums.size(); ++i) {
        // This is the non-decreasing condition:
        // The subsequence is either empty or the new number is >= the last number.
        if (currentSub.empty() || nums[i] >= currentSub.back()) {
            
            // 1. Choose: Add the current number to the subsequence.
            currentSub.push_back(nums[i]);

            // 2. Explore: Recurse to find longer subsequences starting from the next index.
            solve(i + 1, currentSub, nums, resultSet);

            // 3. Unchoose (Backtrack): Remove the number to explore other possibilities.
            currentSub.pop_back();
        }
    }
}