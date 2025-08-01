#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	int maximumGain(string s, int x, int y){
		int score = 0;
		char high_first, high_second, low_first, low_second;
		int high_score, low_score;

		if(x > y){
			high_score = x;
			high_first = 'a';
			high_second = 'b';
			low_score = y;
			low_first = 'b';
			low_second = 'a';
		}else{
			high_score = y;
			low_score = x;
			high_first = 'b';
			high_second = 'a';
			low_first = 'a';
			low_second = 'b';
		}

		string after_first_pass;
		for(char c : s){
			if(!after_first_pass.empty() && after_first_pass.back() == high_first && c == high_second){
				after_first_pass.pop_back();
				score += high_score;
			}
			else{
				after_first_pass.push_back(c);
			}
		}

		string after_second_pass;
		for (char c : after_first_pass){
			if(!after_second_pass.empty() && after_second_pass.back() == low_first && c == low_second){
				after_second_pass.pop_back();
				score += low_score;
			}else{
				after_second_pass.push_back(c);
			}
		}
		return score;
	}
};


int main() {
    // Speed up C++ I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Create an instance of the Solution class
    Solution sol;

    // --- Test Case 1 ---
    std::string s1 = "cdbcbbaaabab";
    int x1 = 4;
    int y1 = 5;
    int result1 = sol.maximumGain(s1, x1, y1);
    
    std::cout << "--- Example 1 ---" << std::endl;
    std::cout << "Input: s = \"" << s1 << "\", x = " << x1 << ", y = " << y1 << std::endl;
    std::cout << "Maximum Gain: " << result1 << " (Expected: 19)" << std::endl;
    std::cout << "-----------------" << std::endl << std::endl;

    // --- Test Case 2 ---
    std::string s2 = "aabbaaxybbaabb";
    int x2 = 5;
    int y2 = 4;
    int result2 = sol.maximumGain(s2, x2, y2);

    std::cout << "--- Example 2 ---" << std::endl;
    std::cout << "Input: s = \"" << s2 << "\", x = " << x2 << ", y = " << y2 << std::endl;
    std::cout << "Maximum Gain: " << result2 << " (Expected: 20)" << std::endl;
    std::cout << "-----------------" << std::endl;

    return 0;
};
