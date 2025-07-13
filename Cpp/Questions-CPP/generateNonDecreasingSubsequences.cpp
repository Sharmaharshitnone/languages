#include <bits/stdc++.h>
using namespace std;

void helper(vector <int> &arr, int idx, vector <int> curr, vector<vector<int>> &res){
    if(curr.size() >= 2){
        res.push_back(curr);
        return;
    }

    for(int i = idx; i < arr.size(); i++){
        if(curr.empty() || arr[i] > curr.back()){
            curr.push_back(arr[i]);
            helper(arr,i+1,curr,res);
            curr.pop_back();
        }
    }
}

vector <vector <int>> subseq(vector <int> arr){
    vector<int> curr;
    vector<vector<int>> res;

    helper(arr,0,curr,res);

    return res;
}