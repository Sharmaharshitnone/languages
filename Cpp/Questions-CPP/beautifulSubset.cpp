#include <bits/stdc++.h>
using namespace std;

// Main function to find the number of beautiful subsets
int beautifulSubsets(vector<int>& nums, int k) {
    int n = nums.size();
    int beautifulSubsetCount = 0;
    int totalSubsets = 1 << n; // 2^n

    for (int i = 1; i < totalSubsets; ++i) { // Iterate through all non-empty subsets
        vector<int> currentSubset;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                currentSubset.push_back(nums[j]);
            }
        }

        bool isBeautiful = true
        ;
        for (size_t j = 0; j < currentSubset.size(); ++j) {
            for (size_t l = j + 1; l < currentSubset.size(); ++l) {
                if (abs(currentSubset[j] - currentSubset[l]) == k) {
                    isBeautiful = false;
                    break;
                }
            }
            if (!isBeautiful) {
                continue;
            } else {
                break;
            }
        }

        if (isBeautiful) {
            beautifulSubsetCount++;
        }
    }

    return beautifulSubsetCount;
}

int main() {
    int n, k;
    cin >> n >> k;  // Input the size of the array and k
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];  // Input the elements of the array
    }

    // Call beautifulSubsets and output the result
    cout << beautifulSubsets(arr, k) << endl;
    return 0;
}