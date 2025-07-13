#include <bits/stdc++.h>
using namespace std;

// This is your original, excellent solution
int celebrity(vector<vector<int>> mat){
    // ... your existing code ...
}

// Here is the alternative optimal solution using a stack
int celebrityWithStack(vector<vector<int>>& mat) {
    int n = mat.size();
    stack<int> st;

    // Step 1: Push all potential candidates onto the stack.
    for (int i = 0; i < n; i++) {
        st.push(i);
    }

    // Step 2: Eliminate candidates until only one remains.
    // (This is the fun part!)
    while (st.size() > 1) {
        int personA = st.top();
        st.pop();
        int personB = st.top();
        st.pop();

        // If A knows B, A is not a celebrity. B might be.
        if (mat[personA][personB] == 1) {
            st.push(personB);
        } 
        // If A does NOT know B, B is not a celebrity. A might be.
        else {
            st.push(personA);
        }
    }

    // If the stack is empty after all that, something is wrong (or n=0)
    if (st.empty()) {
        return -1;
    }

    // Step 3: Verify the final candidate.
    int candidate = st.top();
    for (int i = 0; i < n; i++) {
        // We don't check the candidate against themself
        if (i != candidate) {
            // Check the two celebrity conditions:
            // 1. The candidate must not know person 'i'.
            // 2. Person 'i' must know the candidate.
            if (mat[candidate][i] == 1 || mat[i][candidate] == 0) {
                return -1; // This candidate is a fraud!
            }
        }
    }

    return candidate; // We found them!
}


int main(){
    int n;
    cin >> n;

    vector<vector<int>> mat(n,vector<int>(n,0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }

    // You could call either function here!
    int celebrety = celebrityWithStack(mat);

    cout << celebrety;

    return 0;
}