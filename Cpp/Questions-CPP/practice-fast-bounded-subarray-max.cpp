#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Step 1: Read input
    int n;
    std::cin >> n;
    
    int left, right;
    std::cin >> left >> right;
    
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    
    // Step 2: Count valid subarrays using brute force
    int count = 0;
    
    // Try all possible subarrays
    for(int start = 0 ; start < n ; start++){
		int current_max = nums[start];

		for(int end = start; end < n ; ++end){
			current_max = max(current_max, nums[end]);
			if(current_max >= left && current_max <= right){
				count++;
			}
			if(current_max > right){
				break;
			}
		}
	}
    // Step 5: Output the result
    std::cout << count << std::endl;
    
    return 0;
}
