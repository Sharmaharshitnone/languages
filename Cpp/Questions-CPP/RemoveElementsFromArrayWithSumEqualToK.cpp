#include <bits/stdc++.h>
using namespace std;

int Operations(vector<int> &arr, int target)
{
    int noOfOp = 0;
    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum < target)
        {
            left++;
        }
        else if (sum > target)
        {
            right--;
        }
        else if (sum == target)
        {
            // Found a pair, so we "remove" them by moving both pointers
            left++;
            right--;
            noOfOp++;
        }
    }
    return noOfOp;
}

int main()
{
    int n, target;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> target;

    // BUG FIX 1: The array must be sorted for the two-pointer approach.
    sort(arr.begin(), arr.end());

    int res = Operations(arr, target);

    // BUG FIX 2: Print the result 'res', not the 'target'.
    cout << res;

    return 0;
}