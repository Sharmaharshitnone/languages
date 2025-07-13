#include <bits/stdc++.h>
using namespace std;

void helper(vector <int> &arr, int target, int idx, vector<int> &combin, vector<vector<int>> &res){
    if(target == 0){
        res.push_back(combin);
        return;
    }

    for(int i = idx; i < arr.size(); i++){
        if(i > idx && arr[i] == arr[i-1]){
            continue;
        }
        if(arr[i] > target){
            break;
        }
        combin.push_back(arr[i]);
        helper(arr,target-arr[i],i+1,combin,res);
        combin.pop_back();
    }
}

vector<vector<int>> ans(vector<int> arr, int target){
    vector <int> combin;
    vector<vector<int>> res;

    sort(arr.begin(), arr.end());

    helper(arr,target,0,combin,res);
    return res;

}


int main(){
    int n,target;
    cin >> n;

    vector <int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cin >> target;

    vector<vector<int>> res = ans(arr,target);

    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << ',';
    }
}