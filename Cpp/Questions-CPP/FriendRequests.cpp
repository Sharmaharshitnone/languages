#include <bits/stdc++.h>
using namespace std;

int numberOfFriendRequest(vector<int> &ages)
{
    // Step 1. Create a frequency map to count how many people have each age.
    // Ages are from 1 to 120, so an array of size 121 is perfect.
    vector<int> ageCounts(121, 0);
    for (int age : ages)
    {
        ageCounts[age]++;
    }

    // Step 2. Create a prefix sum array to quickly find the number of people
    // in an age range. agePrefixSum[i] = total people with age <= i.
    vector<int> agePrefixSum(121, 0);
    for (int i = 1; i <= 120; i++)
    {
        agePrefixSum[i] = agePrefixSum[i - 1] + ageCounts[i];
    }

    // Step 3. Initialize our total request counter.
    int totalRequests = 0;

    // Step 4. Iterate through each possible age for person 'A' (the sender).
    for (int ageA = 1; ageA <= 120; ageA++)
    {
        // Step 5. If no one has this age, there's nothing to do, so we skip.
        if (ageCounts[ageA] == 0)
        {
            continue;
        }

        // Step 6. Calculate the lower age limit for a valid friend request from ageA.
        // A person 'B' must be older than this limit.
        int lowerBound = (0.5 * ageA) + 7;

        // Step 7. If the lower bound is already greater than or equal to ageA,
        // no one can satisfy the conditions (ageB > lowerBound and ageB <= ageA).
        if (lowerBound >= ageA)
        {
            continue;
        }

        // Step 8. Use the prefix sum array to find how many people are in the valid age range.
        // The range is (lowerBound, ageA].
        int countInRange = agePrefixSum[ageA] - agePrefixSum[lowerBound];

        // Step 9. The countInRange includes people of ageA themselves.
        // For each person of ageA, they can send requests to everyone in the range,
        // *except* for themselves. So we subtract 1.
        int validFriendsCount = countInRange - 1;

        // Step 10. Calculate the total requests sent by ALL people of ageA.
        // It's the number of people with ageA multiplied by the number of valid friends each can have.
        totalRequests += validFriendsCount * ageCounts[ageA];
    }

    // Step 11. Return the final calculated total.
    return totalRequests;
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

    int ans = numberOfFriendRequest(arr);
    cout << ans;
}