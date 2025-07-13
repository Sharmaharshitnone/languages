#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
	int n, k;
	cin >> n;
	cin >> k;

	vector<int> flowerbed(n);
	for (int i = 0; i < n; ++i){
		cin >> flowerbed[i];
	}
	if (k == 0) {
		cout << "true" << endl;
		return 0;
	}
	for (int i = 0; i < n; ++i){
		if (flowerbed[i] == 0) {
			bool left_is_empty = (i == 0) || (flowerbed[i - 1] == 0);
			bool right_is_empty = (i == n - 1) || (flowerbed[i + 1] == 0);
			if (left_is_empty && right_is_empty) {
				flowerbed[i] = 1;
				k--;
				if (k == 0) {
					cout << "true" << endl;
					return 0;
				}
			}
		}
	}
	cout<< "false" << endl;
	return 0;
	

}
