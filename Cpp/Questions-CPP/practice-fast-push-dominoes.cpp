#include <iostream>
#include <string>
#include <vector>
#include <climits>

int main()
{
 // Step 1: Read the input
 int n;
 std::cin >> n;

 std::string dominoes;
 std::cin >> dominoes;

	vector<int> right_forces(n, INT_MAX);
	vector<int> left_forces(n, INT_MAX);
	int last_right_pos = -1;
	int last_left_pos = -1;

	for(int i = 0 ; i < n; ++i){
		if(dominos[i] == 'R'){
			last_right_pos = i;
		}else if (dominos[i] == 'L'){
			last_right_pos = -1;
		}
		if(last_right_pos != -1){
			right_forces[i] = i - last_right_pos;
		}
	}

	for(int i = 0 ; i < n; ++i){

		if(dominos[i] == 'L'){
			last_right_pos = i;
		}else if (dominos[i] == 'R'){
			last_right_pos = -1;
		}
		if(last_right_pos != -1){
			right_forces[i] = last_right_pos - i;
		}
	}

	string result = "";

	for(int i = 0 < n ; ++i){
		if(right_fores[i] < left_forces[i]){
			result += 'R';
		}
		else if(left_forces[i] < right_forces[i]){
			result += 'L';
		}
		else{
			result += '.';
		}
	}

// Step 5: Output the result
 std::cout << result << std::endl;

 return 0;
}
