#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	vector<int> s1_freq(26, 0);
	for (char c : s1){
		s1_freq[c - 'a']++;
	}

	int window_size = s1.length();
	vector<int>window_freq(26, 0);
for(int i = window_size - 1; i < s2.length(); ++i){
    if(i >= window_size){ // This is the corrected condition
        window_freq[s2[i]-'a']++;
        window_freq[s2[i-window_size] - 'a']--;
    }
    
    if(s1_freq == window_freq){
        cout<<"true"<<endl;
        return 0;
    }
}

	cout <<"false"<<endl;

}

