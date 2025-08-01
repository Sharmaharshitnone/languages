/*
 * ## Problem: Next Greater Element I
 *
 * You are given two distinct integer arrays, `nums1` and `nums2`,
 * where `nums1` is a subset of `nums2`.
 *
 * For each element in `nums1`, find its "next greater element" in `nums2`.
 * The next greater element for a number `x` in `nums2` is the first
 * number to its right that is greater than `x`.
 *
 * If no such element exists, the answer for that number is -1.
 *
 * Example:
 * nums1 = [4, 1, 2]
 * nums2 = [1, 3, 4, 2]
 * Output: [-1, 3, -1]
 */

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // 1. READ INPUT
    int n1_len, n2_len;

    std::cin >> n1_len;
    std::vector<int> nums1(n1_len);
 
    for (int i = 0; i < n1_len; ++i) {
        std::cin >> nums1[i];
    }

    std::cin >> n2_len;
    std::vector<int> nums2(n2_len);
    for (int i = 0; i < n2_len; ++i) {
        std::cin >> nums2[i];
    }

    // 2. CORE LOGIC: PRE-CALCULATE USING STACK AND MAP
    std::unordered_map<int, int> next_greater_map;
    std::stack<int> s;

    // Iterate through the second array to find the next greater element for each number
    for (int current_num : nums2) {
        // While stack is not empty and the current number is greater than the stack's top element
        while (!s.empty() && current_num > s.top()) {
            // The current number is the next greater element for the number at the top of the stack
            next_greater_map[s.top()] = current_num;
            s.pop(); // We've found the answer for this element, so pop it
        }
        // Push the current number onto the stack, waiting for its next greater element
        s.push(current_num);
    }

    // 3. BUILD AND PRINT THE RESULT
    std::vector<int> result;
    for (int num : nums1) {
        // Check if the number from nums1 exists as a key in our map
        if (next_greater_map.count(num)) {
            result.push_back(next_greater_map[num]);
        } else {
            // If not found, it means no next greater element exists
            result.push_back(-1);
        }
    }

    // Print the final result array
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}