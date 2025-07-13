#include <bits/stdc++.h>
using namespace std;

// Step 1: Helper function to generate valid binary strings recursively
void generateBinaryStrings(string current, int n, vector<string> &result, bool lastCharIsOne)
{
    // Step 2: Base case - we've built a string of length n
    if (current.length() == n)
    {
        result.push_back(current);
        return;
    }
    
    // Step 3: We can always add '0' (doesn't create consecutive 1s)
    generateBinaryStrings(current + '0', n, result, false);
    
    // Step 4: We can only add '1' if the last character is NOT '1'
    if (!lastCharIsOne)
    {
        generateBinaryStrings(current + '1', n, result, true);
    }
}

// Step 5: Main function to get all valid binary strings
vector<string> getAllValidBinaryStrings(int n)
{
    vector<string> result;
    
    // Step 6: Start recursion with empty string and lastCharIsOne = false
    generateBinaryStrings("", n, result, false);
    
    return result;
}

int main()
{
    int n;
    cin >> n;
    
    // Step 7: Generate all valid binary strings
    vector<string> validStrings = getAllValidBinaryStrings(n);
    
    // Step 8: Print all valid strings
    for (int i = 0; i < validStrings.size(); i++)
    {
        cout << validStrings[i] << " ";
    }
    cout << endl;
    
    return 0;
}