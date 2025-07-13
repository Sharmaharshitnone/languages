#include <bits/stdc++.h>
using namespace std;

void helper(string &str, int idx, string current, vector<string> &ans) {
  if (idx == str.length()) {
    ans.push_back(current);
    return;
  }

  helper(str, idx + 1, current + str[idx], ans);
  helper(str, idx + 1, current, ans);
}

vector<string> subsquences(string str) {
  sort(str.begin(), str.end());
  vector<string> ans;

  helper(str, 0, "", ans);
  return ans;
}

int main() {
  string str;
  cin >> str;

  vector<string> ans = subsquences(str);

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}  
