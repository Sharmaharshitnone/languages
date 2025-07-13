#include <bits/stdc++.h>
using namespace std;

string smallestNumber(string nums, int k){
    int n = nums.size();
    stack <char> st;

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