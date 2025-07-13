#include <bits/stdc++.h>
using namespace std;

vector<int> kthSmallestFraction(vector<int> &arr, int k)
{
    int n = arr.size();

    // Step 1. Define a custom comparator for our min-heap
    auto compare = [&arr](pair<int, int> &a, pair<int, int> &b)
    {
        return arr[a.first] * arr[b.second] > arr[b.first] * arr[a.second];
    };

    // Step 2. Create a min-heap to store fraction indices (numerator_idx, denominator_idx)
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);

    // Step 3. Push all fractions with the smallest numerator (arr[0])
    for (int j = 1; j < n; j++)
    {
        pq.push({0, j});
    }

    // Step 4. Pop from the heap k-1 times
    for (int i = 1; i < k; i++)
    {
        auto [num_idx, den_idx] = pq.top();
        pq.pop();

        // Step 5. If there's a next fraction with the same denominator, add it to the heap
        if (num_idx + 1 < den_idx)
        {
            pq.push({num_idx + 1, den_idx});
        }
    }

    // Step 6. The k-th smallest fraction is at the top of the heap
    auto [num_idx, den_idx] = pq.top();
    return {arr[num_idx], arr[den_idx]};
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

    vector<int> result = kthSmallestFraction(arr, k);
    cout << result[0] << " " << result[1] << endl;

    return 0;
}