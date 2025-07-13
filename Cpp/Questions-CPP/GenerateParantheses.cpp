#include <bits/stdc++.h>
using namespace std;

// Step 1. Define the recursive helper function that does the backtracking.
// 'open' and 'close' track the number of open and close parentheses used so far.
void generateParanthesesHelper(int open, int close, int n, string current, vector<string> &result)
{
    // Step 2. Base Case: If our string has reached the full length (2*n),
    // it's a valid combination, so we add it to our results and stop this path.
    if (current.length() == 2 * n)
    {
        result.push_back(current);
        return;
    }

    // Step 3. First choice: Can we add an opening parenthesis?
    // We can if we haven't used all 'n' of them yet.
    if (open < n)
    {
        // If so, we explore this path by adding '(' and incrementing the 'open' count.
        generateParanthesesHelper(open + 1, close, n, current + '(', result);
    }

    // Step 4. Second choice: Can we add a closing parenthesis?
    // We can only if the number of closing brackets is less than the number of open ones.
    // This rule is the key to keeping the parentheses balanced.
    if (close < open)
    {
        // If so, we explore this path by adding ')' and incrementing the 'close' count.
        generateParanthesesHelper(open, close + 1, n, current + ')', result);
    }
}

// Step 5. The main function to kick off the process.
vector<string> generateParentheses(int n)
{
    vector<string> result;

    // Step 6. Start the recursion with 0 open, 0 close, and an empty string.
    generateParanthesesHelper(0, 0, n, "", result);
    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<string> answer = generateParentheses(n);

    // Step 7. Print the results in the required format.
    cout << '[';
    for (int i = 0; i < answer.size(); i++)
    {
        cout << '"' << answer[i] << '"';
        if (i != answer.size() - 1)
        {
            cout << ',';
        }
    }
    cout << ']' << endl;
}