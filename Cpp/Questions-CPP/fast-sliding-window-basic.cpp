#include <bits/stdc++.h>
using namespace std;

// Step 1: Current approach (Brute Force) - O(n*k)
vector<int> slidingWindowMaxBasic(vector<int> nums, int k)
{
 int n = nums.size();
 vector<int> result;

 // Step 1: Go through each possible window position
 for (int i = 0; i <= n - k; i++)
 {
  int maxElement = INT_MIN;

  // Step 2: Check all k elements in current window
  for (int j = i; j <= i + k - 1; j++)
  {
   maxElement = max(maxElement, nums[j]);
  }

  // Step 3: Store the maximum of current window
  result.push_back(maxElement);
 }

 return result;
}

int main()
{
 // Example: [1,2,3,1,4,5,2,3,6] with k=3
 vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
 int k = 3;

 cout << "Array: ";
 for (int x : arr)
  cout << x << " ";
 cout << "\nWindow size: " << k << "\n";

 vector<int> result = slidingWindowMaxBasic(arr, k);

 cout << "Maximum in each window: ";
 for (int x : result)
  cout << x << " ";
 cout << "\n";

 return 0;
}
