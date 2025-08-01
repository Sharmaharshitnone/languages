/*
 * Question: Find Minimum in Rotated Sorted Array
 *
 * You are given an array of length n which was originally sorted in ascending order.
 * It has now been rotated between 1 and n times. For example, the array
 * nums = [1,2,3,4,5,6] might become:
 *
 * [3,4,5,6,1,2] if it was rotated 4 times.
 * [1,2,3,4,5,6] if it was rotated 6 times.
 *
 * Notice that rotating the array 4 times moves the last four elements of the array
 * to the beginning. Rotating the array 6 times produces the original array.
 *
 * Assuming all elements in the rotated sorted array nums are unique, return the
 * minimum element of this array.
 *
 * A solution that runs in O(n) time is trivial, can you write an algorithm that
 * runs in O(log n) time?
 *
 * Example 1:
 * Input: nums = [3,4,5,6,1,2]
 * Output: 1
 *
 * Example 2:
 * Input: nums = [4,5,0,1,2,3]
 * Output: 0
 *
 * Example 3:
 * Input: nums = [4,5,6,7]
 * Output: 4
 *
 * Constraints:
 * 1 <= nums.length <= 1000
 * -1000 <= nums[i] <= 1000
 */

#include <iostream>
#include <vector>
#include <algorithm>

int findMin(const std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    // Perform binary search to find the pivot point (the minimum element).
    while (left < right) {
        int mid = left + (right - left) / 2; // prevents overflow

        // The key comparison is with the rightmost element.
        // This tells us which side of 'mid' is sorted.
        if (nums[mid] < nums[right]) {
            // Case 1: The right half (from mid to right) is sorted.
            // This means the minimum element could be nums[mid] itself
            // or an element to its left. We discard the part to the right of mid.
            right = mid;
        } else {
            // Case 2: The pivot point is in the right half.
            // nums[mid] is greater than elements on the right (like nums[right]),
            // so it can't be the minimum. We search to the right of mid.
            left = mid + 1;
        }
    }

    // When the loop terminates, 'left' will point to the minimum element.
    return nums[left];
}

// Example Usage
int main() {
    std::vector<int> nums1 = {3, 4, 5, 6, 1, 2};
    std::cout << "Example 1 Output: " << findMin(nums1) << std::endl;

    std::vector<int> nums2 = {4, 5, 0, 1, 2, 3};
    std::cout << "Example 2 Output: " << findMin(nums2) << std::endl;

    std::vector<int> nums3 = {4, 5, 6, 7};
    std::cout << "Example 3 Output: " << findMin(nums3) << std::endl;

    return 0;
}
