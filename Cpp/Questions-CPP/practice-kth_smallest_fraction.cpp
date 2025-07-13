#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// A structure to hold a fraction, making the code cleaner.

struct Fraction{
	int num;
	int den;
};

void kthSmallestFraction(const vector<int>& arr, int k){
	vector<Fraction>fractions;

	for (size_t i = 0; i < arr.size(); ++i){
		for(size_t = i + 1; j< arr.size(); ++j){
			fractions.push_back({arr[i], arr[j]});
		}
	}
	sort(fractions.begin(), fractions.end(), [](const Fractions& a, const Fractions& b){
		return a.num * b. den < b.num * a.den;
	})

	Fraction result = fractions[k - 1];
	cout << result.num << " " << result.den << endl;
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
