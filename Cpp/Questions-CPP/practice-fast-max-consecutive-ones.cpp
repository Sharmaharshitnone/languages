#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int>nums(n);
	for (int i = 0 ; i < n ; ++i){
		cin >> nums[i];
	}
	int k;
	cin >> k;

	int left = 0;
	int zero_count = 0;
	int max_length = 0;

	for(int right = 0; right < n ; ++right){
		if(nums[right] == 0){
			zero_count++;
		}
		while(zero_count > k){
			if(nums[left] == 0){
				zero_count--;
			}
			left++;
		}
		int current_length = right - left + 1;
		max_length = max(max_length, current_length);
	}


	cout << max_length<<endl;
	return 0;
}
