#include <bits/stdc++.h>
using namespace std;

int trap(vector <int> arr){
    int n = arr.size();
    vector<int> left_max(n), right_max(n);

    int trapped_water = 0;

    left_max[0] = arr[0];
    for(int i = 1; i < n; i++){
        left_max[i] = max(left_max[i-1], arr[i]);
    }

    
    right_max[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--){
        right_max[i] = max(right_max[i+1], arr[i]);
    }

    for(int i = 0; i < n; i++){
        trapped_water += min(left_max[i], right_max[i]) - arr[i];
    }

    return trapped_water;


}

int main(){

    int n;
    cin >> n;

    vector <int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int water = trap(arr);

    cout << water;



    return 0;
}