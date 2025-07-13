#include <bits/stdc++.h>
using namespace std;

// Brute Force: O(n*k) approach
vector<int> slidingWindowBruteForce(vector<int> nums, int k)
{
 int n = nums.size();
 vector<int> result;

 for (int i = 0; i <= n - k; i++)
 {
  int maxElement = INT_MIN;
  for (int j = i; j <= i + k - 1; j++)
  {
   maxElement = max(maxElement, nums[j]);
  }
  result.push_back(maxElement);
 }
 return result;
}

// Optimized: O(n) approach using deque
vector<int> slidingWindowOptimized(vector<int> nums, int k)
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

  // Remove smaller elements (they can't be maximum)
  while (!dq.empty() && nums[dq.back()] <= nums[i])
  {
   dq.pop_back();
  }

  // Add current index
  dq.push_back(i);

  // Record maximum if we have complete window
  if (i >= k - 1)
  {
   result.push_back(nums[dq.front()]);
  }
 }

 return result;
}

int main()
{
 // Test with different sizes to show performance difference
 cout << "=== Performance Comparison ===\n\n";

 // Small test
 vector<int> small_arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
 int k = 3;

 cout << "Small test (n=9, k=3):\n";
 cout << "Array: ";
 for (int x : small_arr)
  cout << x << " ";
 cout << "\n";

 auto start1 = chrono::high_resolution_clock::now();
 vector<int> result1 = slidingWindowBruteForce(small_arr, k);
 auto end1 = chrono::high_resolution_clock::now();
 auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);

 auto start2 = chrono::high_resolution_clock::now();
 vector<int> result2 = slidingWindowOptimized(small_arr, k);
 auto end2 = chrono::high_resolution_clock::now();
 auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);

 cout << "Brute Force result: ";
 for (int x : result1)
  cout << x << " ";
 cout << " (Time: " << duration1.count() << " microseconds)\n";

 cout << "Optimized result:   ";
 for (int x : result2)
  cout << x << " ";
 cout << " (Time: " << duration2.count() << " microseconds)\n\n";

 // Large test to show real performance difference
 cout << "Large test (n=10000, k=100):\n";
 vector<int> large_arr(10000);
 for (int i = 0; i < 10000; i++)
 {
  large_arr[i] = rand() % 1000;
 }

 start1 = chrono::high_resolution_clock::now();
 vector<int> large_result1 = slidingWindowBruteForce(large_arr, 100);
 end1 = chrono::high_resolution_clock::now();
 duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);

 start2 = chrono::high_resolution_clock::now();
 vector<int> large_result2 = slidingWindowOptimized(large_arr, 100);
 end2 = chrono::high_resolution_clock::now();
 duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);

 cout << "Brute Force: " << duration1.count() << " microseconds\n";
 cout << "Optimized:   " << duration2.count() << " microseconds\n";
 cout << "Speedup: " << (double)duration1.count() / duration2.count() << "x faster!\n\n";

 // Verify results are same
 bool same = (large_result1 == large_result2);
 cout << "Results match: " << (same ? "YES" : "NO") << "\n";

 return 0;
}
