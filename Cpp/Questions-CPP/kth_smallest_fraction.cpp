
#include <iostream>
#include <vector>
#include <algorithm>

// A structure to hold a fraction, making the code cleaner.
struct Fraction {
    int num; // Numerator
    int den; // Denominator
};

// This function finds the k-th smallest fraction that can be formed from the array.
// It generates all possible fractions, sorts them, and picks the k-th one.
void kthSmallestFraction(const std::vector<int>& arr, int k) {
    // A vector to store all possible fractions.
    std::vector<Fraction> fractions;

    // Generate all fractions arr[i] / arr[j] where i < j.
    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t j = i + 1; j < arr.size(); ++j) {
            fractions.push_back({arr[i], arr[j]});
        }
    }

    // Sort the fractions. We use a custom comparison function (a lambda) to avoid
    // floating-point inaccuracies. To compare a/b and c/d, we compare a*d and c*b.
    std::sort(fractions.begin(), fractions.end(), [](const Fraction& a, const Fraction& b) {
        return a.num * b.den < b.num * a.den;
    });

    // The k-th smallest fraction is at index k-1 in the sorted list.
    Fraction result = fractions[k - 1];
    std::cout << result.num << " " << result.den << std::endl;
}

int main() {
    int n, k;
    // Read the size of the array and the index k.
    std::cin >> n >> k;

    // Create a vector of size n and read the elements.
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Call the function to find and print the result.
    kthSmallestFraction(arr, k);

    return 0;
}
