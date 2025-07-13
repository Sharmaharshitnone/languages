#include <bits/stdc++.h>
using namespace std;

// Step 1. Define the recursive helper function.
void findCombinations(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &currentCombination)
{
    // Step 2. Base Case: If the target is 0, we found a valid combination.
    if (target == 0)
    {
        ans.push_back(currentCombination);
        return;
    }

    // Step 3. Iterate through the candidates starting from the current index.
    for (int i = index; i < arr.size(); i++)
    {
        // Step 4. The key optimization to avoid duplicates.
        // If the current element is the same as the previous one, and we are not
        // at the very start of this level's loop (i > index), we skip it.
        // This ensures that for a block of duplicate numbers, we only start a
        // recursive path with the FIRST one.
        if (i > index && arr[i] == arr[i - 1])
        {
            continue;
        }

        // Step 5. If the current candidate is larger than the remaining target,
        // any further candidates will also be too large (since the array is sorted).
        // So we can stop exploring this path.
        if (arr[i] > target)
        {
            break;
        }

        // Step 6. "Choose" the current element.
        currentCombination.push_back(arr[i]);
        // Recurse, starting from the NEXT element (i + 1).
        findCombinations(i + 1, target - arr[i], arr, ans, currentCombination);
        // Step 7. "Unchoose" (backtrack) to explore other possibilities.
        currentCombination.pop_back();
    }
}

int main()
{
    int n, target;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> target;

    // Step 8. Sort the array. This is essential for the duplicate-skipping logic.
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;
    vector<int> currentCombination;

    // Step 9. Start the recursion from the beginning.
    findCombinations(0, target, arr, ans, currentCombination);

    // Print the result
    for (const auto &comb : ans)
    {
        cout << "[";
        for (size_t i = 0; i < comb.size(); ++i)
        {
            cout << comb[i] << (i == comb.size() - 1 ? "" : ",");
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}