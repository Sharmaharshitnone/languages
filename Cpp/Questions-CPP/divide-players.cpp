#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
 // Step 1: Read input
 int n;
 std::cin >> n;

 std::vector<int> skill(n);
 for (int i = 0; i < n; ++i)
 {
  std::cin >> skill[i];
 }

 // Step 2: Check if pairing is possible (n must be even)
 if (n % 2 != 0)
 {
  std::cout << -1 << std::endl;
  return 0;
 }

 // Step 3: Sort the skills to enable greedy pairing
 std::sort(skill.begin(), skill.end());

 // Step 4: Calculate target sum using the first and last players
 // If greedy pairing works, all pairs will have this sum
 int target_sum = skill[0] + skill[n - 1];

 // Step 5: Use two pointers to pair players and calculate chemistry
 long long total_chemistry = 0;
 int left = 0;
 int right = n - 1;

 while (left < right)
 {
  // Check if current pair has the target sum
  if (skill[left] + skill[right] != target_sum)
  {
   // If any pair doesn't match, it's impossible
   std::cout << -1 << std::endl;
   return 0;
  }

  // Add this pair's chemistry to the total
  total_chemistry += (long long)skill[left] * skill[right];

  // Move pointers inward to form the next pair
  left++;
  right--;
 }

 // Step 6: Output the total chemistry
 std::cout << total_chemistry << std::endl;

 return 0;
}
