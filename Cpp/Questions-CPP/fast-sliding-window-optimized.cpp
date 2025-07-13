#include <bits/stdc++.h>
using namespace std;

// Step 1: Optimized approach using Deque - O(n)
vector<int> slidingWindowMaxOptimized(vector<int> nums, int k)
{
 int n = nums.size();
 vector<int> result;

 // Step 1: Create a deque to store indices (not values!)
 // We store indices so we can check if they're still in current window
 deque<int> dq;

 cout << "\n=== Detailed Step-by-Step Process ===\n";

 // Step 2: Process each element
 for (int i = 0; i < n; i++)
 {
  cout << "\nProcessing element " << nums[i] << " at index " << i << "\n";

  // Step 3: Remove indices that are out of current window
  // If front element is too far (more than k positions back), remove it
  while (!dq.empty() && dq.front() <= i - k)
  {
   cout << "  Removing index " << dq.front() << " (too far back)\n";
   dq.pop_front();
  }

  // Step 4: Remove elements from back that are smaller than current element
  // Why? Because they can never be maximum while current element is in window
  while (!dq.empty() && nums[dq.back()] <= nums[i])
  {
   cout << "  Removing index " << dq.back() << " (value " << nums[dq.back()]
        << " is smaller than current " << nums[i] << ")\n";
   dq.pop_back();
  }

  // Step 5: Add current element index to back
  dq.push_back(i);
  cout << "  Added index " << i << " to deque\n";

  // Step 6: If we have processed at least k elements, record the maximum
  if (i >= k - 1)
  {
   // Front of deque always contains index of maximum element in current window
   result.push_back(nums[dq.front()]);
   cout << "  Window [" << (i - k + 1) << " to " << i << "]: max = "
        << nums[dq.front()] << " (at index " << dq.front() << ")\n";
  }

  // Show current deque state
  cout << "  Current deque indices: ";
  for (int idx : dq)
   cout << idx << " ";
  cout << "\n";
 }

 return result;
}

// Step 2: Clean optimized version without debug output
vector<int> slidingWindowMaxClean(vector<int> nums, int k)
{
 int n = nums.size();
 vector<int> result;
 deque<int> dq; // Store indices

 for (int i = 0; i < n; i++)
 {
  // Remove indices outside current window
  while (!dq.empty() && dq.front() <= i - k)
  {
   dq.pop_front();
  }

  // Remove smaller elements from back (they can't be maximum)
  while (!dq.empty() && nums[dq.back()] <= nums[i])
  {
   dq.pop_back();
  }

  // Add current index
  dq.push_back(i);

  // Record maximum if we have a complete window
  if (i >= k - 1)
  {
   result.push_back(nums[dq.front()]);
  }
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

 // Step 1: Show detailed process
 vector<int> result1 = slidingWindowMaxOptimized(arr, k);
 cout << "\nFinal result: ";
 for (int x : result1)
  cout << x << " ";
 cout << "\n";

 // Step 2: Verify with clean version
 vector<int> result2 = slidingWindowMaxClean(arr, k);
 cout << "\nClean version result: ";
 for (int x : result2)
  cout << x << " ";
 cout << "\n";

 return 0;
}
