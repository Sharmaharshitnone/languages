/*
 * ## Problem: Beautiful Arrangement (LeetCode #526)
 *
 * You are given an integer `n`. A permutation of the integers from 1 to `n`
 * is considered a "beautiful arrangement" if for every position `i` (from 1 to `n`),
 * one of the following two conditions is true:
 *
 * 1. The number at the `i`-th position is divisible by `i`.
 * 2. `i` is divisible by the number at the `i`-th position.
 *
 * Your task is to return the total number of beautiful arrangements that can be constructed.
 *
 * ### Example 1:
 * Input: n = 2
 * Output: 2
 * Explanation:
 * The two beautiful arrangements are:
 * - [1, 2]:
 * - At position i=1, perm[1]=1, and 1 is divisible by 1.
 * - At position i=2, perm[2]=2, and 2 is divisible by 2.
 * - [2, 1]:
 * - At position i=1, perm[1]=2, and 2 is divisible by 1.
 * - At position i=2, perm[2]=1, and 2 is divisible by 1.
 *
 * ### Example 2:
 * Input: n = 1
 * Output: 1
 * Explanation:
 * The only beautiful arrangement is [1].
 */

#include <iostream>
#include <vector>

// This class encapsulates the solution logic.
class Solution
{
public:
 // This is the main function that will be called to start the process.
 // It sets up the necessary variables and initiates the recursive backtracking.
 int countArrangement(int n)
 {
  // 'visited' is a boolean vector to keep track of which numbers (from 1 to n)
  // have already been placed in the current arrangement.
  // We use size n+1 for 1-based indexing (e.g., visited[1], visited[2], ...).
  std::vector<bool> visited(n + 1, false);
  int count = 0; // This variable will store the total number of beautiful arrangements found.

  // Start the backtracking process from the first position (pos = 1).
  calculate(n, 1, count, visited);

  return count;
 }

private:
 // This is the recursive helper function that performs the backtracking.
 // n: The target number.
 // pos: The current position in the arrangement we are trying to fill (from 1 to n).
 // count: A reference to our counter, so we can increment it when a solution is found.
 // visited: A reference to the vector tracking used numbers.
 void calculate(int n, int pos, int &count, std::vector<bool> &visited)
 {
  // === Base Case ===
  // If the current position 'pos' is greater than 'n', it means we have successfully
  // placed a valid number in all positions from 1 to n.
  // We have found one complete beautiful arrangement.
  if (pos > n)
  {
   count++; // Increment the solution counter.
   return;  // Return to explore other possibilities.
  }

  // === Recursive Step ===
  // Iterate through all possible numbers 'i' from 1 to n to try and place at the current 'pos'.
  for (int i = 1; i <= n; ++i)
  {
   // Check two conditions before placing the number 'i' at 'pos':
   // 1. !visited[i]: The number 'i' has not been used yet in this arrangement.
   // 2. (i % pos == 0 || pos % i == 0): The number 'i' and position 'pos' satisfy the "beautiful" rule.
   if (!visited[i] && (i % pos == 0 || pos % i == 0))
   {

    // --- Action ---
    // If the conditions are met, place 'i' at 'pos' by marking it as visited.
    visited[i] = true;

    // --- Recurse ---
    // Move to the next position to continue building the arrangement.
    calculate(n, pos + 1, count, visited);

    // --- Backtrack ---
    // After the recursive call returns (meaning it has explored all possibilities from this point),
    // we "undo" our choice. We mark 'i' as not visited so it can be used
    // in a different position for another potential arrangement. This is the core of backtracking.
    visited[i] = false;
   }
  }
 }
};

// Main function to test the solution.
int main()
{
 int n;
 std::cout << "Enter an integer n: ";
 std::cin >> n;

 Solution sol;
 int result = sol.countArrangement(n);

 std::cout << "Number of beautiful arrangements: " << result << std::endl;

 return 0;
}