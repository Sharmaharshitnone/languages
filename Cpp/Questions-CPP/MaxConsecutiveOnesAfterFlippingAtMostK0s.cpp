#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(vector<int> arr, int k)
{
    // Step 1. Initialize our window pointers and counters.
    int left = 0;      // The left edge of our sliding window.
    int maxlen = 0;    // Stores the maximum valid window size found.
    int zero_count = 0; // Counts the number of zeros in the current window.

    // Step 2. The 'right' pointer expands the window from left to right.
    for (int right = 0; right < arr.size(); right++)
    {
        // Step 3. If the new element entering the window is a zero, increment our count.
        if (arr[right] == 0)
        {
            zero_count++;
        }

        // Step 4. Check if the window has become invalid (too many zeros).
        // If so, we need to shrink it from the left until it's valid again.
        while (zero_count > k)
        {
            // Step 5. If the element we're about to remove from the left is a zero...
            if (arr[left] == 0)
            {
                // ...decrement the zero count, as it's no longer in the window.
                zero_count--;
            }
            // Step 6. Shrink the window by moving the left pointer forward.
            left++;
        }

        // Step 7. At this point, the window [left...right] is guaranteed to be valid.
        // Calculate its size and update our overall max length.
        int len = right - left + 1;
        maxlen = max(maxlen, len);
    }

    // Step 8. After the loop finishes, return the best length we found.
    return maxlen;
}

int main()
{
    int n, k;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> k;

    int ans = maxConsecutiveOnes(arr, k);
    cout << ans;
    return 0;
}