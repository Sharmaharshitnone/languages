#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> // For std::sort (optional, but good practice for consistent output)

void generateSubsetsBitManipulation(const std::vector<int>& nums) {
    int n = nums.size();
    int num_subsets = 1 << n; // Equivalent to pow(2, n)

    std::cout << "Subsets using Bit Manipulation:" << std::endl;
    for (int i = 0; i < num_subsets; ++i) {
        std::vector<int> current_subset;
        for (int j = 0; j < n; ++j) {
            // Check if the j-th bit of 'i' is set
            if ((i >> j) & 1) {
                current_subset.push_back(nums[j]);
            }
        }

        // Print the current subset
        std::cout << "[";
        for (size_t k = 0; k < current_subset.size(); ++k) {
            std::cout << current_subset[k];
            if (k < current_subset.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
}

int main() {
    std::vector<int> nums = {1, 2, 3};
    generateSubsetsBitManipulation(nums);
    return 0;
}
