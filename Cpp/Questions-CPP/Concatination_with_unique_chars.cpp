#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm> // For max

using namespace std;

// Global variable to store the maximum length found
int maxLength = 0;

// Helper function to check if adding 'nextStr' to the 'currentSet' is valid
bool canInclude(const string &nextStr, const unordered_set<char> &currentSet)
{
  unordered_set<char> nextStrChars;
  for (char c : nextStr)
  {
    if (currentSet.count(c) || nextStrChars.count(c))
    {
      return false;
    }
    nextStrChars.insert(c);
  }
  return true;
}

// Recursive backtracking function with print statements
void solve(const vector<string> &arr, int index, unordered_set<char> &currentSet, int currentLength)
{
  // --- Print current state ---
  cout << string(index * 2, ' ') << "-> Exploring at index " << index << ". Current Length: " << currentLength << ". Letters used: {";
  string sep = "";
  for (char c : currentSet)
  {
    cout << sep << c;
    sep = ", ";
  }
  cout << "}" << endl;

  // Update the overall maximum length found
  if (currentLength > maxLength)
  {
    cout << string(index * 2, ' ') << "   *** New Max Length Found: " << currentLength << " ***" << endl;
    maxLength = currentLength;
  }
  else
  {
    // Keep the original logic just in case, but mostly rely on the check above
    maxLength = max(maxLength, currentLength);
  }

  // Base case: If we've considered all strings
  if (index == arr.size())
  {
    cout << string(index * 2, ' ') << "   Reached end of blocks for this path." << endl;
    return;
  }

  const string &nextStr = arr[index];
  cout << string(index * 2, ' ') << "   Considering block: \"" << nextStr << "\"" << endl;

  // --- Option 1: Try to INCLUDE arr[index] ---
  bool can_add = canInclude(nextStr, currentSet);
  cout << string(index * 2, ' ') << "   Checking if we can include \"" << nextStr << "\": " << (can_add ? "Yes" : "No") << endl;

  if (can_add)
  {
    cout << string(index * 2, ' ') << "   YES, Including \"" << nextStr << "\". Adding its letters to checklist." << endl;
    // Add characters of nextStr to the set for the recursive call
    vector<char> added_chars; // Keep track of what we added for backtracking message
    for (char c : nextStr)
    {
      currentSet.insert(c);
      added_chars.push_back(c);
    }

    // Recurse: move to the next index with updated set and length
    solve(arr, index + 1, currentSet, currentLength + nextStr.length());

    // Backtrack: remove characters of nextStr from the set
    cout << string(index * 2, ' ') << "   <-- Backtracking from including \"" << nextStr << "\". Removing its letters: {";
    sep = "";
    for (char c : added_chars)
    {
      cout << sep << c;
      sep = ", ";
    }
    cout << "} from checklist." << endl;
    for (char c : added_chars)
    {
      currentSet.erase(c);
    }
  }

  // --- Option 2: EXCLUDE arr[index] ---
  cout << string(index * 2, ' ') << "   NO (or choosing not to), Skipping block \"" << nextStr << "\"." << endl;
  // Recurse: move to the next index without changing the set or length
  solve(arr, index + 1, currentSet, currentLength);

  cout << string(index * 2, ' ') << "<- Finished exploring options for index " << index << "." << endl;
}

int main()
{
  int n;
  cout << "Enter the number of strings: ";
  cin >> n;

  vector<string> arr(n);
  cout << "Enter the strings:" << endl;
  for (int i = 0; i < n; ++i)
  {
    cin >> arr[i];
  }

  unordered_set<char> currentSet;
  maxLength = 0; // Reset max length before solving

  cout << "\n--- Starting Exploration ---" << endl;
  // Start the backtracking process
  solve(arr, 0, currentSet, 0);
  cout << "--- Exploration Complete ---" << endl;

  cout << "\nMaximum possible length: " << maxLength << endl;

  return 0;
}