#include <iostream>
#include <vector>
#include <string>

int main()
{
 // Step 1: Read the input values from the user.
 int size;
 std::cin >> size;

 int n;
 std::cin >> n;

 std::vector<int> flowerbed(size);
 for (int i = 0; i < size; ++i)
 {
  std::cin >> flowerbed[i];
 }

 // Step 2: Handle the simple case where we don't need to plant any flowers.
 if (n == 0)
 {
  std::cout << "true" << std::endl;
  return 0;
 }

 // Step 3: Iterate through the flowerbed to find valid spots.
 for (int i = 0; i < size; ++i)
 {
  // A spot is valid if the plot itself is empty (0),
  // and its neighbors are also empty.
  if (flowerbed[i] == 0)
  {
   // Check the left neighbor.
   // It's considered empty if we are at the very beginning (i == 0)
   // or if the plot to the left (i - 1) is 0.
   bool left_is_empty = (i == 0) || (flowerbed[i - 1] == 0);

   // Check the right neighbor.
   // It's considered empty if we are at the very end (i == size - 1)
   // or if the plot to the right (i + 1) is 0.
   bool right_is_empty = (i == size - 1) || (flowerbed[i + 1] == 0);

   // If both sides are clear, we can plant a flower.
   if (left_is_empty && right_is_empty)
   {
    // Plant the flower by updating the plot to 1.
    flowerbed[i] = 1;
    // Decrement the count of flowers we still need to plant.
    n--;

    // An optimization: if we've planted all flowers, we can stop early.
    if (n == 0)
    {
     break;
    }
   }
  }
 }

 // Step 4: After checking all plots, see if we planted all required flowers.
 // If n is 0, it means we succeeded.
 if (n == 0)
 {
  std::cout << "true" << std::endl;
 }
 else
 {
  std::cout << "false" << std::endl;
 }

 return 0;
}
