#include <bits/stdc++.h>
using namespace std;

// Step 1. Create a helper function to count subarrays with AT MOST k odd numbers.
// This is a standard sliding window problem.
int atMostK(vector<int> &nums, int k)
{
    // Step 2. Initialize window pointers and counters.
    int left = 0;
    int count = 0;
    int subarrayCount = 0;

    // Step 3. The 'right' pointer expands the window from left to right.
    for (int right = 0; right < nums.size(); right++)
    {
        // Step 4. If the new element is odd, increment our odd number counter.
        if (nums[right] % 2 != 0)
        {
            count++;
        }

        // Step 5. If the window is invalid (too many odds), shrink it from the left.
        while (count > k)
        {
            // Step 6. If the element we're removing was odd, decrement the counter.
            if (nums[left] % 2 != 0)
            {
                count--;
            }
            // Step 7. Shrink the window.
            left++;
        }

        // Step 8. At this point, the window [left...right] is valid.
        // All subarrays ending at 'right' within this window are also valid.
        // The number of such subarrays is (right - left + 1).
        subarrayCount += (right - left + 1);
    }
    return subarrayCount;
}

// Step 9. The main function that uses the "at most" logic.
int numberOfSubarrays(vector<int> &nums, int k)
{
    // Step 10. The number of subarrays with EXACTLY k odds is equal to
    // (number of subarrays with AT MOST k odds) - (number of subarrays with AT MOST k-1 odds).
    return atMostK(nums, k) - atMostK(nums, k - 1);
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = numberOfSubarrays(arr, k);
    cout << ans;
}