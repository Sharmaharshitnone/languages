#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main()
{
 // Step 1: Read input
 int n;
 std::cin >> n;

 std::vector<int> stones(n);
 for (int i = 0; i < n; ++i)
 {
  std::cin >> stones[i];
 }

 // Step 2: Sort the stones to work with them in order
 std::sort(stones.begin(), stones.end());

 // Step 3: Calculate minimum moves
 int min_moves = INT_MAX;

 // Try to fit all stones in a window of size 3
 // We can achieve this by moving stones to fill gaps
 for (int i = 0; i <= n - 3; ++i)
 {
  // Count how many stones are already in positions [stones[i], stones[i] + 2]
  int stones_in_window = 0;
  for (int j = i; j < i + 3 && j < n; ++j)
  {
   if (stones[j] <= stones[i] + 2)
   {
    stones_in_window++;
   }
  }
  // We need to move (3 - stones_in_window) stones
  int moves_needed = 3 - stones_in_window;
  min_moves = std::min(min_moves, moves_needed);
 }

 // Special case: if stones are already in 3 consecutive positions
 bool already_consecutive = false;
 for (int i = 0; i <= n - 3; ++i)
 {
  if (stones[i + 2] - stones[i] == 2)
  {
   already_consecutive = true;
   break;
  }
 }

 if (already_consecutive)
 {
  min_moves = 0;
 }
 else
 {
  // If we can make it in 1 move (special cases)
  // Case 1: Two stones are consecutive and the third is far
  for (int i = 0; i < n - 1; ++i)
  {
   if (stones[i + 1] - stones[i] == 1)
   {
    min_moves = std::min(min_moves, 1);
    break;
   }
  }

  // Case 2: Two stones have exactly one gap between them
  for (int i = 0; i < n - 1; ++i)
  {
   if (stones[i + 1] - stones[i] == 2)
   {
    min_moves = std::min(min_moves, 1);
    break;
   }
  }
 }

 // Step 4: Calculate maximum moves
 // Maximum moves = total positions spanned - 3 - (stones we don't need to move)
 int total_span = stones[n - 1] - stones[0] + 1;
 int max_moves = total_span - 3;

 // But we can only move from endpoints, so we need to be more careful
 // The maximum is achieved by moving stones one by one from one end
 int left_gap = stones[1] - stones[0] - 1;
 int right_gap = stones[n - 1] - stones[n - 2] - 1;

 // We want to maximize the number of moves, so we move from the end with smaller gap
 max_moves = stones[n - 1] - stones[0] - 2 - std::min(left_gap, right_gap);

 // Step 5: Output the result
 std::cout << min_moves << " " << max_moves << std::endl;

 return 0;
}
