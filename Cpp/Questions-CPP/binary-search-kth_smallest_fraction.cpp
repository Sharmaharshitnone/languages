
#include <iostream>
#include <vector>
#include <algorithm>

// This function finds the k-th smallest fraction using binary search on the value.
// It's much more efficient than generating all fractions.
void kthSmallestFraction(const std::vector<int>& arr, int k) {
    int n = arr.size();
    // The value of the fraction is between 0 and 1. We binary search in this range.
    double low = 0.0;
    double high = 1.0;

    // Variables to store the numerator and denominator of the answer.
    int num_ans = 0;
    int den_ans = 1;

    // The binary search loop.
    while (low < high) {
        // Calculate the middle value to test.
        double mid = low + (high - low) / 2;

        // --- Count fractions smaller than or equal to 'mid' --- //
        long long count = 0;
        int max_num = 0;
        int max_den = 1;
        int j = 1; // Pointer for the denominator.

        // For each numerator arr[i]...
        for (int i = 0; i < n - 1; ++i) {
            // ...find how many denominators arr[j] create a fraction <= mid.
            while (j < n && arr[i] > mid * arr[j]) {
                j++;
            }
            // All denominators from arr[j] to arr[n-1] will form a fraction <= mid
            // with the current numerator arr[i].
            count += (n - j);

            // Keep track of the largest fraction found so far that is <= mid.
            // This is our best candidate for the answer in this iteration.
            if (j < n && (long long)max_num * arr[j] < (long long)arr[i] * max_den) {
                max_num = arr[i];
                max_den = arr[j];
            }
        }
        // --- End of counting --- //

        // Based on the count, adjust the binary search range.
        if (count == k) {
            // If we found exactly k smaller fractions, the largest of them is the answer.
            num_ans = max_num;
            den_ans = max_den;
            break; // Found it, exit loop.
        } else if (count < k) {
            // If the count is too small, our 'mid' value was too low.
            // We need to search for a larger value.
            low = mid;
        } else {
            // If the count is too high, 'mid' might be the answer, or it's too high.
            // We store the current best candidate and search in the lower half.
            num_ans = max_num;
            den_ans = max_den;
            high = mid;
        }
    }

    std::cout << num_ans << " " << den_ans << std::endl;
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
