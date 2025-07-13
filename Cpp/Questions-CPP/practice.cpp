#include<bits/stdc++.h>
using namespace std;

vector<int> kthSmallestFraction(vector<int>&arr, int k){
	int n = arr.size();

	auto compare = [&arr](pair<int, int> &a, pair<int, int>&b){
		return arr[a.first] * arr[b.second] > arr[b.first] * arr[a.second];
	};

	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare) > pq(compare);

	for(int j = 1; j < n; j++){
		pq.push({0, j});
	}

	for(int i = 1; i < k; i++){
		auto[num_idx, den_idx] = pq.top();

		if(num_idx + 1 < den_idx){
			pq.push({num_idx + 1, den_idx});
		}
	}

	auto[num_idx, den_idx] = pq.top();
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