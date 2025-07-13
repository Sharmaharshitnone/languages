#include <bits/stdc++.h>
using namespace std;

// Step 1: Optimized approach using sliding window - O(n)
int maxFruitsOptimized(vector<int> &arr, int n)
{
    // Step 2: Use sliding window with two pointers
    int left = 0, right = 0;
    int maxFruits = 0;
    
    // Step 3: Use map to count frequency of each fruit type in current window
    unordered_map<int, int> fruitCount;
    
    cout << "\n=== Sliding Window Process ===\n";
    
    // Step 4: Expand window with right pointer
    while (right < n)
    {
        // Step 5: Add current fruit to window
        fruitCount[arr[right]]++;
        cout << "Adding fruit " << arr[right] << " at position " << right << "\n";
        
        // Step 6: If we have more than 2 fruit types, shrink window from left
        while (fruitCount.size() > 2)
        {
            cout << "  Too many fruit types (" << fruitCount.size() << "), removing from left\n";
            fruitCount[arr[left]]--;
            
            // Step 7: Remove fruit type completely if count becomes 0
            if (fruitCount[arr[left]] == 0)
            {
                fruitCount.erase(arr[left]);
            }
            left++;
        }
        
        // Step 8: Update maximum fruits collected
        maxFruits = max(maxFruits, right - left + 1);
        cout << "  Current window: [" << left << "," << right << "] = " 
             << (right - left + 1) << " fruits\n";
        cout << "  Max so far: " << maxFruits << "\n\n";
        
        right++;
    }
    
    return maxFruits;
}

// Step 9: Clean version without debug output
int maxFruitsClean(vector<int> &arr, int n)
{
    int left = 0, right = 0;
    int maxFruits = 0;
    unordered_map<int, int> fruitCount;
    
    while (right < n)
    {
        // Add current fruit to window
        fruitCount[arr[right]]++;
        
        // Shrink window if more than 2 fruit types
        while (fruitCount.size() > 2)
        {
            fruitCount[arr[left]]--;
            if (fruitCount[arr[left]] == 0)
            {
                fruitCount.erase(arr[left]);
            }
            left++;
        }
        
        // Update maximum
        maxFruits = max(maxFruits, right - left + 1);
        right++;
    }
    
    return maxFruits;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";
    
    // Step 10: Show optimized process
    int result1 = maxFruitsOptimized(arr, n);
    cout << "Optimized result: " << result1 << "\n\n";
    
    // Step 11: Verify with clean version
    int result2 = maxFruitsClean(arr, n);
    cout << "Clean version result: " << result2 << "\n";
    
    return 0;
}