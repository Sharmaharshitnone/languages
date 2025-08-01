#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
	int countArrangement(int n){
		vector<bool>visited(n + 1, false);
		int count = 0;
		calculate(n , 1, count, visited);
		return count;
	}
private:
	void calculate(int n, int index, int &count, vector<bool>&visited){
		if(index > n){
			count++;
			return;
		}

		for(int i = 1; i <= n; i++){
			if(!visited[i] && (i % index == 0 || index % i == 0)){
				visited[i] = true;
				calculate(n, index + 1, count, visited);
				visited[i] = false;
			}
		}
	}
};



int main(){
 int n;
 std::cout << "Enter an integer n: ";
 std::cin >> n;

 Solution sol;
 int result = sol.countArrangement(n);

 std::cout << "Number of beautiful arrangements: " << result << std::endl;

 return 0;
}
