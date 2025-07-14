#include <iostream>
#include <vector>

using namespace std;

void findSubset(int index, vector<int>nums, vector<vector<int>> result, vector<int> currentSubset){

	result.push_back(currentSubset);

	for(int i = 0; i < nums.size() ; i++){
		currentSubset.push_back(nums[i]);

		findSubset(i + 1, nums, result, currentSubset);

		currentSubset.pop_back();
	}

}

int main(){
	vector<int>nums = {1, 2, 3};
	vector<vector<int>> result;
	vector<int>currentSubset;

	findSubset(0, nums, result,  currentSubset);

	for(const auto& subset : result){
		cout << "[";
		for (const auto& num : subset){
			cout << num << " ";
		}
		cout << "]";
		
	}
	return 0;
}
