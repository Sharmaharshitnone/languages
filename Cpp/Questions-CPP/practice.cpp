#include <bits/stdc++.h>
using namespace std;

int maxPile(const vector<int>&arr){
	int maxSize = INT_MIN;
	for(int pile : arr){
		maxSize = max(maxSize, pile);
	}
	return maxSize;
}

int minSpeed(const vector<int>&arr, int h){
	int left = 1;
	int right = maxPile(arr);
	if(h < arr.size()){
		return -1;
	}
	while(left < right){
		int mid = left + (right - left) / 2;
		long long totalHour = 0;

		for(int pile: arr){
			totalHour += (pile + mid - 1) /mid;
		}

		if(totalHour <= h){
			right = mid;
		}else{
			left = mid + 1;
		}
	}
	return left;
}
