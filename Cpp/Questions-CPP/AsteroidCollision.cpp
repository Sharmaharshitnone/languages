#include <bits/stdc++.h> // Includes all standard C++ libraries
using namespace std;

int main()
{
    // 1. Read Input
    int n;
    cin >> n; // Read the number of elements (asteroids)

    std::vector<int> arr(n); // Use a std::vector for safe dynamic allocation

    for (int i = 0; i < n; i++) // Reading into vector is the same
    {
        cin >> arr[i]; // Read each element into the array
    }

    // 2. Process Asteroids using a Stack
    stack<int> st; // This stack will store the asteroids that survive collisions

    for (const int& current_asteroid : arr)
    {
        // If the current asteroid is positive (moving right), it can't collide with
        // anything in the stack yet, so just push it.
        if (current_asteroid > 0)
        {
            st.push(current_asteroid);
        }
        // If the current asteroid is negative (moving left), it might collide.
        else
        {
            // Collision check loop:
            // This loop runs as long as the stack is not empty, the asteroid at the top
            // is positive (moving right), and the current negative asteroid is stronger
            // (larger in absolute value).
            while (!st.empty() && st.top() > 0 && abs(current_asteroid) > st.top())
            {
                st.pop(); // The smaller positive asteroid at the top is destroyed.
            }

            // After the loop, check the state of the stack top.
            // If the top is a positive asteroid of the same size, both are destroyed.
            if (!st.empty() && st.top() > 0 && abs(current_asteroid) == st.top())
            {
                st.pop(); // Annihilate both.
            }
            // If the stack is empty or the top is a negative asteroid, the current
            // negative asteroid survives as there's no oncoming collision.
            else if (st.empty() || st.top() < 0)
            {
                st.push(current_asteroid);
            }
        }
    }

    // 3. Print the Result
    // If the stack is empty, all asteroids were destroyed.
    if (st.empty())
    {
        cout << "Everything Destroyed";
    }
    else
    {
        // To print in the correct order, we need to reverse the stack.
        // A temporary stack `ans` is used for this.
        stack<int> ans;
        while (!st.empty())
        {
            ans.push(st.top()); // Move elements from `st` to `ans`.
            st.pop();
        }

        // Print the final surviving asteroids from the reversed stack.
        while (!ans.empty())
        {
            cout << ans.top() << " ";
            ans.pop();
        }
    }

    return 0; // End of the program
}