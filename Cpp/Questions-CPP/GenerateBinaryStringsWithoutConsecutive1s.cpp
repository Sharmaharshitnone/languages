/*
 * QUESTION: Generate All Binary Strings Without Consecutive 1s
 *
 * Write a program that takes an integer `n` as input and generates all
 * possible binary strings of length `n` that do not contain consecutive ones.
 *
 * For example:
 * If n = 2, the valid strings are "00", "01", "10". "11" is invalid.
 * If n = 3, the valid strings are "000", "001", "010", "100", "101".
 */

#include <bits/stdc++.h> // Includes all standard C++ libraries
using namespace std;

/**
 * @brief A recursive helper function to generate binary strings.
 *
 * @param current The string built so far.
 * @param n The target length of the string.
 * @param result A reference to the vector storing the final valid strings.
 * @param lastCharIsOne A boolean flag to track if the last character added was a '1'.
 */
void generateBinaryStrings(string current, int n, vector<string> &result, bool lastCharIsOne)
{
    // Step 1: Base Case
    // If the current string has reached the desired length 'n', it's a valid solution.
    // Add it to our result list and stop this recursive path.
    if (current.length() == n)
    {
        result.push_back(current);
        return;
    }

    // Step 2: Option A - Add '0'
    // We can always append a '0' because it will never create consecutive '1's.
    // Make a recursive call with the updated string ("current" + '0') and set
    // the lastCharIsOne flag to 'false' for the next level of recursion.
    generateBinaryStrings(current + '0', n, result, false);

    // Step 3: Option B - Add '1'
    // We can only append a '1' if the last character added was not a '1'.
    // This is the core constraint of the problem.
    if (!lastCharIsOne)
    {
        // Make a recursive call with the updated string ("current" + '1') and
        // set the lastCharIsOne flag to 'true'.
        generateBinaryStrings(current + '1', n, result, true);
    }
}

/**
 * @brief Main function to initialize the process of generating strings.
 *
 * @param n The desired length of the binary strings.
 * @return A vector of strings containing all valid binary strings.
 */
vector<string> getAllValidBinaryStrings(int n)
{
    // Step 4: Create a vector to hold the final results.
    vector<string> result;

    // Step 5: Start the recursion.
    // We begin with an empty string "" and since there's no previous character,
    // we can safely say the last character was not '1' (lastCharIsOne = false).
    generateBinaryStrings("", n, result, false);

    // Step 6: Return the completed list of valid strings.
    return result;
}

int main()
{
    // Step 7: Read the desired length 'n' from the user.
    int n;
    cin >> n;

    // Step 8: Call the function to generate all valid binary strings of length 'n'.
    vector<string> validStrings = getAllValidBinaryStrings(n);

    // Step 9: Print all the generated valid strings, separated by spaces.
    for (int i = 0; i < validStrings.size(); i++)
    {
        cout << validStrings[i] << " ";
    }
    cout << endl; // Print a newline at the end for clean output.

    return 0; // Indicate successful execution.
}