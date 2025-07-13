#include <iostream>
#include <vector>
#include <algorithm>

// Function to try all possible pairings using backtracking
bool findPairing(std::vector<int> &skill, std::vector<bool> &used, int target_sum,
                 int current_team, int total_teams, long long &chemistry)
{
 // Step 1: Base case - if we've formed all teams successfully
 if (current_team == total_teams)
 {
  return true;
 }

 // Step 2: Find the first unused player
 int first_player = -1;
 for (int i = 0; i < skill.size(); ++i)
 {
  if (!used[i])
  {
   first_player = i;
   break;
  }
 }

 // Step 3: Try pairing this player with every other unused player
 for (int i = first_player + 1; i < skill.size(); ++i)
 {
  if (!used[i] && skill[first_player] + skill[i] == target_sum)
  {
   // Mark both players as used
   used[first_player] = true;
   used[i] = true;

   // Add their chemistry to the total
   chemistry += (long long)skill[first_player] * skill[i];

   // Recursively try to form the remaining teams
   if (findPairing(skill, used, target_sum, current_team + 1, total_teams, chemistry))
   {
    return true;
   }

   // Backtrack - remove the chemistry and mark players as unused
   chemistry -= (long long)skill[first_player] * skill[i];
   used[first_player] = false;
   used[i] = false;
  }
 }

 return false;
}

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

 // Step 2: Check if pairing is possible
 if (n % 2 != 0)
 {
  std::cout << -1 << std::endl;
  return 0;
 }

 // Step 3: Calculate target sum for each team
 long long total_skill = 0;
 for (int i = 0; i < n; ++i)
 {
  total_skill += skill[i];
 }

 int num_teams = n / 2;
 if (total_skill % num_teams != 0)
 {
  std::cout << -1 << std::endl;
  return 0;
 }

 int target_sum = total_skill / num_teams;

 // Step 4: Try to find a valid pairing
 std::vector<bool> used(n, false);
 long long chemistry = 0;

 if (findPairing(skill, used, target_sum, 0, num_teams, chemistry))
 {
  std::cout << chemistry << std::endl;
 }
 else
 {
  std::cout << -1 << std::endl;
 }

 return 0;
}
