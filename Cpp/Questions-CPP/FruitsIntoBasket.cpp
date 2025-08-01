/*
 * QUESTION: Fruit Into Baskets (Sliding Window Maximum)
 *
 * You are visiting a farm with a single row of fruit trees, represented by an
 * integer array `fruits` where `fruits[i]` is the type of fruit the i-th tree produces.
 *
 * You want to collect as much fruit as possible, but you are subject to some rules:
 * - You only have two baskets, and each basket can only hold a single type of fruit.
 * - Starting from any tree of your choice, you must pick one fruit from every
 * tree (including the start tree) while moving to the right. The picked fruits
 * must fit in one of your two baskets.
 * - Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
 *
 * Given the integer array `fruits`, return the maximum number of fruits you can pick.
 * This problem is equivalent to finding the length of the longest subarray that
 * contains at most two distinct integers.
 *
 * Example:
 * fruits = [1, 2, 1, 3, 2, 2]
 * Output: 4 (The subarray is [2, 1, 3, 2])
 *
 * Example 2:
 * fruits = [3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4]
 * Output: 5 (The subarray is [1, 2, 1, 1, 2])
 */

#include <bits/stdc++.h> // Includes all standard C++ libraries
using namespace std;

// This version includes detailed print statements to explain the process.
int maxFruitsOptimized(vector<int> &arr, int n)
{
    // Step 1: Initialize sliding window pointers and max counter.
    // 'left' and 'right' define the boundaries of our current window.
    int left = 0;
    int maxFruits = 0;

    // Step 2: Use a hash map to store the frequency of fruit types in the current window.
    // This allows O(1) lookup, insertion, and deletion on average.
    unordered_map<int, int> fruitCount;

    cout << "\n=== Sliding Window Process ===\n";

    // Step 3: Iterate through the array with the 'right' pointer to expand the window.
    for (int right = 0; right < n; right++)
    {
        // Step 4: Add the current fruit to our window and update its count in the map.
        fruitCount[arr[right]]++;
        cout << "Adding fruit " << arr[right] << " at position " << right << ". Window: [" << left << "," << right << "]\n";

        // Step 5: Check if the window is now invalid (contains more than 2 fruit types).
        // If so, shrink the window from the left until it becomes valid again.
        while (fruitCount.size() > 2)
        {
            cout << "  -> Window invalid (size " << fruitCount.size() << "). Shrinking from left...\n";

            // Step 6: Decrement the count of the fruit at the 'left' pointer.
            fruitCount[arr[left]]--;

            // Step 7: If the count of that fruit becomes zero, remove it from the map completely
            // to accurately reflect the number of distinct fruit types.
            if (fruitCount[arr[left]] == 0)
            {
                fruitCount.erase(arr[left]);
            }
            // Step 8: Move the left pointer one step to the right to shrink the window.
            left++;
        }

        // Step 9: At this point, the window [left, right] is valid.
        // Update the maximum number of fruits collected so far.
        maxFruits = max(maxFruits, right - left + 1);
        cout << "  -> Window valid. Current length: " << (right - left + 1) << ". Max so far: " << maxFruits << "\n\n";
    }

    // Step 10: Return the final maximum count found.
    return maxFruits;
}

// This is a clean version of the same logic without the print statements.
int maxFruitsClean(vector<int> &arr, int n)
{
    // Initialize window pointers, max counter, and frequency map.
    int left = 0;
    int maxFruits = 0;
    unordered_map<int, int> fruitCount;

    // Expand the window with the right pointer.
    for (int right = 0; right < n; right++)
    {
        // Add the new fruit to the window.
        fruitCount[arr[right]]++;

        // If the window becomes invalid (more than 2 distinct fruits),
        // shrink it from the left until it's valid again.
        while (fruitCount.size() > 2)
        {
            fruitCount[arr[left]]--;
            if (fruitCount[arr[left]] == 0)
            {
                fruitCount.erase(arr[left]);
            }
            left++;
        }

        // The window is now valid, so update the maximum length.
        maxFruits = max(maxFruits, right - left + 1);
    }

    return maxFruits;
}

int main()
{
    // Step 11: Read input size and array elements.
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Array: ";
    for (int x : arr)
        cout << x << " ";
    cout << "\n";

    // Step 12: Run the function with detailed output to show the process.
    int result1 = maxFruitsOptimized(arr, n);
    cout << "Final Optimized Result: " << result1 << "\n\n";

    // Step 13: Run the clean function to get the final result directly.
    int result2 = maxFruitsClean(arr, n);
    cout << "Clean Version Result: " << result2 << "\n";

    return 0;
}