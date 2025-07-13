#include <bits/stdc++.h>
using namespace std;

vector<int> maxSubstring(vector<int> nums, int k)
{
    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i <= n - k; i++)
    {
        int maxEle = INT_MIN;
        for (int j = i; j <= i + k - 1; j++)
        {
            maxEle = max(maxEle, nums[j]);
        }
        ans.push_back(maxEle);
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> k;

    vector<int> ans = maxSubstring(arr, k);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}
