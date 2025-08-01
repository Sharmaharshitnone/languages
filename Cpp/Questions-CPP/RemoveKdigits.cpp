// Question:
// Given a non-negative integer represented as a string 'nums' and an integer 'k',
// remove 'k' digits from the number so that the new number is the smallest possible.
// Return the resulting number as a string. If the result has leading zeros, remove them.
// If the result is an empty string, return "0".
#include <bits/stdc++.h>
using namespace std;
string smallestNumber(string nums, int k){
    int n = nums.size();
    stack <char> st;
// to get the smallest number , we will remove the bigger digits first by checking the top of the stack and the current digit, if the current digit is smaller than the top of the stack, we pop the stack and decrement k
    for(int i = 0; i < n; i++){
        while(!st.empty() && k > 0 && nums[i] - '0' < st.top() - '0'){
            st.pop();
            k--;
        }
        st.push(nums[i]);
    }

    while(k > 0){
        st.pop();
        k--;
    }

    string ans = "";
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    while(!ans.empty() && ans.back() == '0'){
        ans.pop_back();
    }

    if(ans.size() == 0) return "0";

    reverse(ans.begin(), ans.end());

    return ans;
}

int main(){
    string str;
    cin >> str;
    int k;
    cin >> k;

    string ans = smallestNumber(str,k);

    cout << ans;

    return 0;
}
