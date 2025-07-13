
#include <iostream>
#include <vector>
#include <algorithm>

// A simple structure to hold our fractions
struct Fraction
{
 int numerator;
 int denominator;
 double value;
};

// A helper function to compare two fractions
bool compareFractions(const Fraction &a, const Fraction &b)
{
 return a.value < b.value;
} 

int main()
{
 // Reading the input values for n and k
 int n, k;
 std::cin >> n >> k;

 // Reading the array elements
 std::vector<int> arr(n);
 for (int i = 0; i < n; ++i)
 {
  std::cin >> arr[i];
 }

 // This vector will store all the possible fractions
 std::vector<Fraction> fractions;

 // Loop through the array to generate all pairs (i, j) where i < j
 for (int i = 0; i < n; ++i)
 {
  for (int j = i + 1; j < n; ++j)
  {
   // Create a new fraction and add it to our list
   fractions.push_back({arr[i], arr[j], (double)arr[i] / arr[j]});
  }
 }

 // Sort the fractions based on their decimal value
 std::sort(fractions.begin(), fractions.end(), compareFractions);

 // Print the numerator and denominator of the k-th smallest fraction
 // k is 1-based, so we access the element at index k-1
 std::cout << fractions[k - 1].numerator << " " << fractions[k - 1].denominator << std::endl;

 return 0;
}
