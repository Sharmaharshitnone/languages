#include <iostream>
#include <vector>

using namespace std;



int main(){
	int n, k;
	cin >> n >> k;

	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	kthsmallestFraction(arr, k);
	return 0;

}
