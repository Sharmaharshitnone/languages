#include <bits/stdc++.h>
using namespace std;

// Step 1: Helper function to generate subsets using backtracking
void helper(vector<int> &nums, int idx, vector<int> &current, vector<vector<int>> &res)
{
    // Step 2: Add current subset to result (this handles empty set and all partial sets)
    res.push_back(current);

    // Step 3: Try including each element from current index onwards
    for (int i = idx; i < nums.size(); i++)
    {
        // Step 4: Include current element in subset
        current.push_back(nums[i]);

        // Step 5: Recursively generate subsets starting from next index
        helper(nums, i + 1, current, res);

        // Step 6: Backtrack - remove current element to try other combinations
        current.pop_back();
    }
}

// Step 7: Main function to generate all subsets
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> current;     // Current subset being built
    vector<vector<int>> res; // Result containing all subsets

    // Step 8: Sort array to get lexicographically ordered subsets
    sort(nums.begin(), nums.end());

    // Step 9: Start recursion from index 0 with empty current subset
    helper(nums, 0, current, res);

    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Step 10: Generate all subsets
    vector<vector<int>> result = subsets(arr);

    // Step 11: Print in required format
    cout << '[';
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j != result[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i != result.size() - 1)
            cout << ',';
    }
    cout << ']' << endl;

    return 0;
}