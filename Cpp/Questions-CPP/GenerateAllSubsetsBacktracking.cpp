#include <iostream>
#include <vector>
#include <algorithm>

// Function to generate subsets using backtracking
void backtrack(const std::vector<int>& nums, int index, std::vector<int>& current_subset, std::vector<std::vector<int>>& all_subsets) {
    // Base case: If we have considered all elements
    if (index == nums.size()) {
        all_subsets.push_back(current_subset);
        return;
    }

    // Choice 1: Include the current element
    current_subset.push_back(nums[index]);
    backtrack(nums, index + 1, current_subset, all_subsets);
    current_subset.pop_back(); // Backtrack: remove the element to explore other paths

    // Choice 2: Exclude the current element
    backtrack(nums, index + 1, current_subset, all_subsets);
}

void generateSubsetsBacktracking(const std::vector<int>& nums) {
    std::vector<std::vector<int>> all_subsets;
    std::vector<int> current_subset;
    backtrack(nums, 0, current_subset, all_subsets);

    std::cout << "Subsets using Backtracking:" << std::endl;
    for (const auto& subset : all_subsets) {
        std::cout << "[";
        for (size_t i = 0; i < subset.size(); ++i) {
            std::cout << subset[i];
            if (i < subset.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
}

int main() {
    std::vector<int> nums = {1, 2, 3};
    generateSubsetsBacktracking(nums);
    return 0;
}
