/*
You start with an initial power of power, an initial score of 0, and a bag of tokens given as an integer array tokens, where each tokens[i] denotes the value of token.
Your goal is to maximize the total score by strategically playing these tokens. In one move, you can play an unplayed token in one of the two ways (but not both for the same token):
- Face-up: If your current power is at least tokens[i], you may play token i, losing tokens[i] power and gaining 1 score.
- Face-down: If your current score is at least 1, you may play token i, gaining tokens[i] power and losing 1 score.
Return the maximum possible score you can achieve after playing any number of tokens.

Input Format
The first line contains an integer n, the number of tokens.
The second line contains n integers, which represent the values of the tokens.
The third line contains an integer power, representing the initial power.

Output Format
Return a single integer, the maximum possible score achievable.

Example 1
Input:
1
100
50
Output:
0

Example 2
Input:
2
200 100
150
Output:
1

Constraints
n == tokens.length
0 <= tokens.length <= 1000
0 <= tokens[i], power < 10^4
Do not use inbuilt or library functions that directly solve the problem. Implement the logic manually.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> tokens(n);
    for (int i = 0; i < n; ++i)
        cin >> tokens[i];
    int power;
    cin >> power;
    sort(tokens.begin(), tokens.end());
    int score = 0, maxScore = 0;
    int left = 0, right = n - 1;
    while (left <= right) {
        if (power >= tokens[left]) {
            power -= tokens[left++];
            score++;
            maxScore = max(maxScore, score);
        } else if (score > 0 && left < right) {
            power += tokens[right--];
            score--;
        } else {
            break;
        }
    }
    cout << maxScore << endl;
    return 0;
}
