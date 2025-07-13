//Done by me Harshit Sharma
#include <iostream>
#include <vector>
#include <algorithm>

// This function calculates the maximum number of pairs that sum up to k.
// It uses the Two Pointers technique after sorting the array.
int maxOperations(std::vector<int>& nums, int k) {
std:sort(nums.begin(), nums.end());
	int left = 0;
	int right = nums.size()
	int operation = 0;

	while (left < right){
		long long current_sum =(long long)nums[left]+nums[right];
		if(current_sum == k){
			operations++;
			left++;
			right--;
		}
		else if (current_sum < k){
			left++;
		}else{
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
