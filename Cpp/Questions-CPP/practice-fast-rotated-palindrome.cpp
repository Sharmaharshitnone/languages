#include <iostream>
#include <string>
#include <algorithm> // Used for the std::reverse function, though a manual check is also easy
using namespace std;

bool isPalindrome(const string &str){
	string reversed_str = str;
	reverse(reversed_str.begin(), reversed_str.end());
	return str == reversed_str;

}

int main(){
	string s;
	cin >> s;
	int n = s.length();
	bool found_palindrome = false;
	if (n <= 1){
		found_palindrome = true;
	}else{
		for(int i = 0; i < n ; ++i){
			string rotated_string = s.substr(i) + s.substr(0, i);

			if(isPalindrome(rotated_string)){
				found_palindrome = true;
				break;
			}			
		}
	}
	if(found_palindrome){
		cout<<"Yes, it is a palindrome";
	}else{
		cout<<"No, the rotated string is not a palindrome";
	}
	return 0;
}


