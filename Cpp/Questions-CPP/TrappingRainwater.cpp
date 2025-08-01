#include <bits/stdc++.h>
using namespace std;

/*
  Question: Trapping Rain Water

  You are given n non-negative integers representing an elevation map where the width of each bar is 1.
  Compute how much water it is able to trap after raining.

  Input:
  - The first line contains an integer n, the number of bars.
  - The second line contains n space-separated non-negative integers representing the elevation map.

  Output:
  - An integer representing the total units of water that can be trapped.

  Example:
  Input: 12
         
  0 1 0 2 1 0 1 3 2 1 2 1
  Output: 6
  Explanation: The elevation map [0,1,0,2,1,0,1,3,2,1,2,1] can trap 6 units of water as shown in the diagram.
*/

// Step 1: Compute the maximum height to the left of each bar.
// Step 2: Compute the maximum height to the right of each bar.
// Step 3: For each bar, the water trapped above it is the minimum of left_max and right_max minus the bar's height.
// Step 4: Sum up the trapped water for all bars.1

int trap(vector<int> arr)
{
    int n = arr.size();
    vector<int> left_max(n), right_max(n);

    int trapped_water = 0;

    // Step 1: Fill left_max array where left_max[i] is the highest bar to the left of i (including i)
    left_max[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left_max[i] = max(left_max[i - 1], arr[i]);
    }
    // Step 2: Fill right_max array where right_max[i] is the highest bar to the right of i (including i)
    right_max[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right_max[i] = max(right_max[i + 1], arr[i]);
    }

    // Step 3: Calculate trapped water at each bar
    for (int i = 0; i < n; i++)
    {
        trapped_water += min(left_max[i], right_max[i]) - arr[i];
    }
   //turn the total trapped water
    return trapped_water;
}

// Step 0: Read input and output the result
int main()
{

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int water = trap(arr);

    cout << water;

    return 0;
}