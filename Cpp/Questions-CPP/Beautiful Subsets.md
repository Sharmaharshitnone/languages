#6th-belt #cpp #languages 

Alright, let's think about how you could approach this in C++. Since the number of elements in `nums` is small (at most 18), a common technique for exploring all possible subsets is using **bit manipulation**.

**The Core Idea: Representing Subsets with Bits**

Imagine you have `n` numbers in your `nums` array. You can represent each subset by a binary number with `n` bits. Each bit in the binary number corresponds to an element in the original array.

- If the ith bit is 1, it means the ith element of `nums` is included in the current subset.
- If the ith bit is 0, it means the ith element is not included.

Since there are n elements, there are 2n possible binary numbers from 0 to 2n−1. Each of these numbers uniquely represents one of the possible subsets of `nums`.

**Steps to Implement in C++**

1. **Include Headers:** You'll likely need `<iostream>`, `<vector>`, and `<cmath>` (for `abs`).
    
2. **Read Input:** Read the values of `n` and `k`, and then read the `n` integers into a `std::vector<int> nums`.
    
3. **Iterate Through All Possible Subsets:**
    
    - Use a `for` loop that goes from 1 to 2n−1. We start from 1 to exclude the empty subset (represented by 0).
    - Inside the loop, each integer `i` in this range represents a subset.
4. **Construct the Current Subset:**
    
    - For each value of `i`, you need to figure out which elements from the original `nums` array are included in the current subset. You can do this by checking the bits of `i`.
    - Use a nested `for` loop that goes from 0 to `n - 1` (the indices of `nums`).
    - Inside this inner loop, use the bitwise AND operator (`&`) to check if the jth bit of `i` is set (equal to 1). The expression `(i >> j) & 1` will give you 1 if the jth bit is set, and 0 otherwise.
    - If the jth bit is 1, it means `nums[j]` is part of the current subset. Store these elements in a temporary `std::vector<int>` representing the current subset.
5. **Check if the Current Subset is Beautiful:**
    
    - Once you have the current subset, you need to check if it's beautiful.
    - Iterate through all pairs of elements within the current subset.
    - For each pair of elements, calculate their absolute difference using `std::abs()`.
    - If you find any pair whose absolute difference is equal to `k`, then this subset is not beautiful. You can use a boolean flag to keep track of this. If the flag becomes true, you can stop checking the rest of the pairs in the current subset.
6. **Count Beautiful Subsets:**
    
    - If, after checking all pairs in the current subset, you find that no two elements have an absolute difference equal to `k`, then this subset is beautiful. Increment a counter variable that keeps track of the number of beautiful subsets found so far.
7. **Output the Result:** After iterating through all possible non-empty subsets, print the final value of the counter.
    

**C++ Code Snippet (Illustrative)**

C++

```
#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    int beautifulSubsetCount = 0;
    int totalSubsets = 1 << n; // 2^n

    for (int i = 1; i < totalSubsets; ++i) { // Iterate through all non-empty subsets
        std::vector<int> currentSubset;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                currentSubset.push_back(nums[j]);
            }
        }

        bool isBeautiful = true;
        for (size_t j = 0; j < currentSubset.size(); ++j) {
            for (size_t l = j + 1; l < currentSubset.size(); ++l) {
                if (std::abs(currentSubset[j] - currentSubset[l]) == k) {
                    isBeautiful = false;
                    break;
                }
            }
            if (!isBeautiful) {
                break;
            }
        }

        if (isBeautiful) {
            beautifulSubsetCount++;
        }
    }

    std::cout << beautifulSubsetCount << std::endl;

    return 0;
}
```

**Explanation of the Code:**

- **`1 << n`:** This is a bitwise left shift, equivalent to 2n, which gives the total number of possible subsets.
- **`for (int i = 1; i < totalSubsets; ++i)`:** This loop iterates through all numbers from 1 to 2n−1, each representing a non-empty subset.
- **`if ((i >> j) & 1)`:** This checks if the jth bit of `i` is 1. If it is, the jth element of `nums` is added to the `currentSubset`.
- **Nested loops for `isBeautiful` check:** These loops iterate through all pairs of elements in the `currentSubset` to see if their absolute difference equals `k`.
- **`beautifulSubsetCount++`:** If the `isBeautiful` flag remains `true` after checking all pairs, the counter is incremented.

This approach systematically generates every non-empty subset and checks if it satisfies the "beautiful" condition. Given the constraint on the size of `nums`, this O(2n⋅n2) time complexity should be acceptable. Remember that the inner loop for checking the beautiful condition can go up to O(n2) in the worst case (when the subset contains many elements).