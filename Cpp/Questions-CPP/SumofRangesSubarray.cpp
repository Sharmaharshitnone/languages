#include <bits/stdc++.h>
using namespace std;

long long sumOfSubarrayRanges(vector<int> &nums)
{
    int n = nums.size();
    long long totalSum = 0;

    // --- Step 1. Calculate the sum of all subarray MAXIMUMS ---
    stack<int> s_max;
    for (int i = 0; i <= n; i++)
    {
        // Find all elements on the stack that are smaller than the current element.
        // The current element nums[i] (or infinity if i==n) is the "Next Greater Element" for them.
        while (!s_max.empty() && (i == n || nums[s_max.top()] < nums[i]))
        {
            int j = s_max.top(); // This is the element that will be the maximum.
            s_max.pop();
            // Find the "Previous Greater Element" for j. It's the new top of the stack.
            int k = s_max.empty() ? -1 : s_max.top();
            // Number of subarrays where nums[j] is max is (j-k) * (i-j)
            totalSum += (long long)nums[j] * (j - k) * (i - j);
        }
        s_max.push(i);
    }

    // --- Step 2. Calculate the sum of all subarray MINIMUMS ---
    stack<int> s_min;
    for (int i = 0; i <= n; i++)
    {
        // Find all elements on the stack that are larger than the current element.
        // The current element nums[i] (or -infinity if i==n) is the "Next Smaller Element" for them.
        while (!s_min.empty() && (i == n || nums[s_min.top()] > nums[i]))
        {
            int j = s_min.top(); // This is the element that will be the minimum.
            s_min.pop();
            // Find the "Previous Smaller Element" for j. It's the new top of the stack.
            int k = s_min.empty() ? -1 : s_min.top();
            // Number of subarrays where nums[j] is min is (j-k) * (i-j)
            // We SUBTRACT this contribution from the total sum.
            totalSum -= (long long)nums[j] * (j - k) * (i - j);
        }
        s_min.push(i);
    }

    // Step 3. The final result is (sum of maxes) - (sum of mins).
    return totalSum;
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

    long long sum = sumOfSubarrayRanges(arr);

    cout << sum;

    return 0;
}