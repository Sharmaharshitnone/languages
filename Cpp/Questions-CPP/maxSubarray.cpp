/*
 * QUESTION: Sliding Window Maximum
 *
 * You are given an array of integers `nums` and an integer `k` representing the size of a sliding window.
 * This window moves from the very left of the array to the very right. You can only see the `k`
 * numbers in the window at a time. The window slides one position to the right at each step.
 *
 * Your task is to return a vector containing the maximum value for each sliding window.
 *
 * For example:
 * nums = [1, 3, -1, -3, 5, 3, 6, 7], k = 3
 * Output: [3, 3, 5, 5, 6, 7]
 *
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * 1 [3  -1  -3] 5  3  6  7       3
 * 1  3 [-1  -3  5] 3  6  7       5
 * 1  3  -1 [-3  5  3] 6  7       5
 * 1  3  -1  -3 [5  3  6] 7       6
 * 1  3  -1  -3  5 [3  6  7]      7
 */

#include <bits/stdc++.h> // Includes all standard C++ libraries
using namespace std;

// This function finds the maximum element in each subarray of size k
vector<int> maxSubstring(vector<int> nums, int k)
{
  // Step 1: Get the size of the input array.
  int n = nums.size();

  // Step 2: Create a vector to store the results (the max of each window).
  vector<int> ans;

  // Step 3: Iterate through the array to define the start of each window.
  // The loop runs from the first element up to the last possible start of a k-sized window.
  for (int i = 0; i <= n - k; i++)
  {
    // Step 4: Initialize a variable to hold the maximum element for the current window.
    // INT_MIN is the smallest possible integer value, ensuring any array element will be larger.
    int maxEle = INT_MIN;

    // Step 5: Create an inner loop to iterate through the elements *within* the current window.
    // This loop runs from the start of the window (i) to the end (i + k - 1).
    for (int j = i; j <= i + k - 1; j++)
    {
      // Step 6: Find the maximum element in the current window.
      // Compare the current maximum (`maxEle`) with the current element (`nums[j]`) and update if necessary.
      maxEle = max(maxEle, nums[j]);
    }
    // Step 7: After checking all elements in the window, add the found maximum to our answer vector.
    ans.push_back(maxEle);
  }
  // Step 8: Return the vector containing all the maximums.
  return ans;
}

int main()
{
  // Step 9: Read the total number of elements.
  int n, k;
  cin >> n;

  // Step 10: Create a vector of size 'n' to store the input numbers.
  vector<int> arr(n);

  // Step 11: Read each number into the vector.
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  // Step 12: Read the window size 'k'.
  cin >> k;

  // Step 13: Call the function to get the sliding window maximums.
  vector<int> ans = maxSubstring(arr, k);

  // Step 14: Iterate through the result vector and print each maximum value.
  for (auto it : ans)
  {
    cout << it << " ";
  }

  return 0; // End of program
}