#include <bits/stdc++.h>
using namespace std;

int mini(vector <int> arr, int start, int end){
    int minimum = INT_MAX;

    for(int i = start; i <= end; i++){
       minimum =  min(minimum, arr[i]);
    }
    return minimum;
}

int minimumSum(vector <int> arr){
    int sum = 0;
    int n = arr.size();

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){

          
            int minElement = mini(arr, i, j);
            sum += minElement;
        }
    }
    return sum;
}

int main(){
    int n;
    cin >> n;

    vector <int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int sum = minimumSum(arr);

    cout << sum;

    return 0;
}