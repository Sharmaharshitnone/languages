/*
  Question: Sum of Subarray Minimums

  Given an array of integers, find the sum of the minimum element of every possible subarray.
  A subarray is a contiguous part of the array.

  Input:
  - The first line contains an integer n, the size of the array.
  - The second line contains n space-separated integers representing the array.

  Output:
  - An integer representing the sum of the minimum element of every subarray.

  Example:
  Input: 3
         3 1 2
  Output: 8
  Explanation: The subarrays are [3], [1], [2], [3,1], [1,2], [3,1,2]. Their minimums are 3, 1, 2, 1, 1, 1. The sum is 3+1+2+1+1+1=9.
*/

#include <bits/stdc++.h>
using namespace std;

int mini(vector<int> arr, int start, int end)
{
    int minimum = INT_MAX;

    for (int i = start; i <= end; i++)
    {
        minimum = min(minimum, arr[i]);
    }
    return minimum;
}

int minimumSum(vector<int> arr)
{
    int sum = 0;
    int n = arr.size();

    // Step 1: For every possible subarray, find its minimum element.
    // Step 2: To do this, iterate over all possible starting indices of subarrays.
    for (int i = 0; i < n; i++)
    {
        // Step 3: For each starting index, iterate over all possible ending indices.
        for (int j = i; j < n; j++)
        {

            // Step 4: For each subarray, use a helper function to find the minimum element in that range.
            int minElement = mini(arr, i, j);
            // Step 5: Add the minimum element to the running sum.
            sum += minElement;
        }
    }
    // Step 6: After checking all subarrays, return the total sum.
    return sum;
}

int main()
{
    int n;
    // Step 7: In main, read the input, call the function, and print the result.
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum = minimumSum(arr);

    cout << sum;

    return 0;
}