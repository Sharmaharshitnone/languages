#include <iostream>
#include <vector>
#include <stack>

using namespace std;

long long sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    long long MOD = 1e9 + 7; // Use modulo for large sums to prevent overflow

    // left[i] = distance to the previous less element
    // right[i] = distance to the next less or equal element
    vector<long long> left(n), right(n);

    // --- Step 1: Calculate left boundaries ---
    // For each arr[i], find the first element to its left that is smaller than it.
    // We use a monotonic stack that stores indices of elements in increasing order.
    stack<pair<int, int>> s1;
    for (int i = 0; i < n; ++i)
    {
        int count = 1;
        // If the stack top is greater than the current element, it means the current
        // element's left boundary extends beyond the stack top's boundary.
        while (!s1.empty() && s1.top().first > arr[i])
        {
            count += s1.top().second;
            s1.pop();
        }
        s1.push({arr[i], count});
        left[i] = count;
    }

    // --- Step 2: Calculate right boundaries ---
    // For each arr[i], find the first element to its right that is smaller or equal.
    // We use "smaller or equal" on one side to handle duplicates correctly, ensuring
    // each subarray is counted for exactly one of its minimums.
    stack<pair<int, int>> s2;
    for (int i = n - 1; i >= 0; --i)
    {
        int count = 1;
        while (!s2.empty() && s2.top().first >= arr[i])
        {
            count += s2.top().second;
            s2.pop();
        }
        s2.push({arr[i], count});
        right[i] = count;
    }

    // --- Step 3: Calculate the final sum ---
    // The total contribution for arr[i] is arr[i] * left[i] * right[i].
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans = (ans + (long long)arr[i] * left[i] * right[i]) % MOD;
    }

    return ans;
}

int main()
{
    // Speed up C++ I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << sumSubarrayMins(arr) << endl;

    return 0;
}