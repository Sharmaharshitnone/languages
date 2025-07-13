#include <iostream>
#include <string>
#include <vector>
#include <climits>

int main()
{
 // Step 1: Read the input
 int n;
 std::cin >> n;

 std::string dominoes;
 std::cin >> dominoes;

 // Step 2: Calculate forces from the right (distance to nearest 'R' on the left)
 std::vector<int> right_forces(n, INT_MAX);
 int last_right_pos = -1;

 for (int i = 0; i < n; ++i)
 {
  if (dominoes[i] == 'R')
  {
   last_right_pos = i;
  }
  else if (dominoes[i] == 'L')
  {
   last_right_pos = -1; // 'L' blocks rightward force
  }

  if (last_right_pos != -1)
  {
   right_forces[i] = i - last_right_pos;
  }
 }

 // Step 3: Calculate forces from the left (distance to nearest 'L' on the right)
 std::vector<int> left_forces(n, INT_MAX);
 int last_left_pos = -1;

 for (int i = n - 1; i >= 0; --i)
 {
  if (dominoes[i] == 'L')
  {
   last_left_pos = i;
  }
  else if (dominoes[i] == 'R')
  {
   last_left_pos = -1; // 'R' blocks leftward force
  }

  if (last_left_pos != -1)
  {
   left_forces[i] = last_left_pos - i;
  }
 }

 // Step 4: Determine final state based on forces
 std::string result = "";

 for (int i = 0; i < n; ++i)
 {
  if (right_forces[i] < left_forces[i])
  {
   // Rightward force is stronger
   result += 'R';
  }
  else if (left_forces[i] < right_forces[i])
  {
   // Leftward force is stronger
   result += 'L';
  }
  else
  {
   // Forces are equal or both infinite - domino stays upright
   result += '.';
  }
 }

 // Step 5: Output the result
 std::cout << result << std::endl;

 return 0;
}
