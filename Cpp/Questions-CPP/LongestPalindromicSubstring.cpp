#include <bits/stdc++.h>
using namespace std;

int expandAroundCenter(int left, int right, const string &s){
    while(left >= 0 && right < s.size() && s[left] == s[right]){
        left--;
        right++;
    }
    return right-left-1;
}

string longestPalindromeSubstring(string str){
   int n = str.size();

   if(n == 0) return "";

   int start = 0;
   int maxLength = 0;

   for(int i = 0; i < n; i++){
    int len1 = expandAroundCenter(i,i,str);
    int len2 = expandAroundCenter(i,i+1,str);

    int maxLen = max(len1,len2);

    if(maxLen > maxLength){
        maxLength = maxLen;
        start = i- (maxLength-1)/2;
    }
   }
   return str.substr(start,maxLength);
}

int main(){
    string str;
    cin >> str;

    string res = longestPalindromeSubstring(str);
    cout << res;
}