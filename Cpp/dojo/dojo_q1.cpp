/*
You are given a positive integer array skill of even length n where skill[i] denotes the skill of the i-th player. Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.

The chemistry of a team is equal to the product of the skills of the players on that team.

Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.

Input Format
The first line contains an integer n, the number of players (always even).
The second line contains n integers, which represent the skill levels of the players.

Output Format
Return a single integer: the sum of the chemistry of all the teams, or -1 if it's not possible to divide the players into teams with equal total skill.

Example 1
Input:
6
3 2 5 1 3 4
Output:
22
Explanation:
Divide the players into the following teams: (1, 5), (2, 4), (3, 3), where each team has a total skill of 6. The sum of the chemistry of all the teams is: 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8 + 9 = 22.

Example 2
Input:
2
3 4
Output:
12
Explanation:
The two players form a team with a total skill of 7. The chemistry of the team is 3 * 4 = 12.

Constraints
n == skill.length
2 <= n <= 10^5
n is even.
1 <= skill[i] <= 1000
Do not use inbuilt or library functions that directly solve the problem. Implement the logic manually.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
 int n;
 cin >> n;
 vector<int> skill(n);
 for (int i = 0; i < n; ++i)
  cin >> skill[i];
 sort(skill.begin(), skill.end());
 int total = skill[0] + skill[n - 1];
 int sum = 0;
 for (int i = 0; i < n / 2; ++i)
 {
  if (skill[i] + skill[n - 1 - i] != total)
  {
   cout << -1 << endl;
   return 0;
  }
  sum += skill[i] * skill[n - 1 - i];
 }
 cout << sum << endl;
 return 0;
}
