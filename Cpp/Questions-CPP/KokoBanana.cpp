#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the maximum pile size in the array of banana piles
 * 
 * @param arr Vector containing the number of bananas in each pile
 * @return int The size of the largest pile
 * @time_complexity O(n) where n is the number of piles
 * @space_complexity O(1)
 */
int maxPile(vector <int> arr){
    int maxSize = INT_MIN; // setting maxSize to lowest possible value
    for (int pile : arr) {
        maxSize = max(maxSize, pile); // trying to get the biggest size of the pile 
    }
    return maxSize;
}

/**
 * @brief Calculates the minimum eating speed required for Koko to eat all banana piles within h hours
 * 
 * This function uses binary search to efficiently find the minimum speed K at which
 * Koko can eat all piles of bananas within the given time constraint.
 * For each pile, Koko takes ceil(pile_size/K) hours to finish.
 * 
 * @param arr Vector containing the number of bananas in each pile
 * @param h The maximum number of hours available to eat all bananas
 * @return int The minimum eating speed required, or -1 if impossible
 * 
 * @time_complexity O(n * log(max_pile)) where n is the number of piles
 * @space_complexity O(1)
 */
int minSpeed(vector <int> arr, int h){
    int left = 1;
    int right = maxPile(arr);
    
    // If hours are less than number of piles, it's impossible
    if (h < arr.size()) {
        return -1;
    }
    
    // Binary search for the minimum valid speed
    while (left < right) {
        int mid = left + (right - left) / 2;
        long long totalHours = 0;
        
        for (int pile : arr) {
            totalHours += (pile + mid - 1) / mid; // Ceiling division
        }
        
        if (totalHours <= h) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}


int main(){
    int n;
    cin >> n;
    vector <int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int h;
    cin >> h;

    int ans = minSpeed(arr,h);
    cout << ans;

    return 0;
}
