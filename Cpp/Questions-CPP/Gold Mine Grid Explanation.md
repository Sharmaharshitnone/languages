#6th-belt #cpp #languages 
This problem asks us to find the most gold we can collect from a grid. Imagine a minefield where some spots have gold, and some are empty. We can walk around (up, down, left, or right) and collect gold from each spot we step on. There are a few important rules:

- **Collect all gold:** When you step on a gold-filled spot, you take all the gold there.
- **One step at a time:** You can only move to an adjacent spot (not diagonally).
- **No revisiting:** You cannot step on the same spot twice in a single path.
- **Avoid empty spots:** You can never step on a spot with 0 gold.
- **Start anywhere:** You can begin your gold-collecting journey from any spot that has gold.
- **End anywhere:** You can stop collecting gold whenever you want.

Our goal is to find a path that lets us collect the maximum total amount of gold.

Let's break down the key ideas with examples:

**1. Grid:** Think of the mine as a grid, like a checkerboard. Each square in the grid can either have a certain amount of gold or be empty (0 gold).

For example:

```
[[0, 6, 0],
 [5, 8, 7],
 [0, 9, 0]]
```

Here, the grid has 3 rows and 3 columns. The number in each cell tells us how much gold is there.

**2. Movement:** From any cell with gold, you can move to the cell directly above, below, to the left, or to the right, as long as that new cell is within the grid boundaries and also has gold (not 0).

In our example, if you are at the cell with '8' gold (in the middle), you can move to the cell with '6' (up), '5' (left), '7' (right), or '9' (down).

**3. Collecting Gold:** When you land on a cell with gold, you automatically collect it. This gold is added to your total for the current path.

If you start at '9' in our example, you collect 9 gold. If you then move to '8', you collect another 8, and your total becomes 9 + 8 = 17.

**4. No Revisiting:** Once you've stepped on a cell, you cannot go back to it in the same sequence of moves. This prevents you from collecting the gold from the same spot multiple times in one path.

If you go from '9' to '8', you cannot immediately go back from '8' to '9' in the same path.

**5. Starting and Stopping Anywhere:** You can begin your gold collection from any cell that has gold. Similarly, you can stop your movement at any point. You don't have to visit all the gold cells.

In the first example, the best path starts at '9', then goes to '8', and then to '7', collecting a total of 9 + 8 + 7 = 24 gold. We could have started at '6' and gone to '8' and then '5' (6 + 8 + 5 = 19), which is less. We could have even just started at '8' and stopped there, collecting only 8 gold.

**The Goal:** We need to explore all possible paths of collecting gold, following the rules, and find the path that gives us the highest total amount of gold.

This problem often involves exploring different paths through the grid. Since we can start from any gold-containing cell and stop at any point, we need to consider all possible starting points and all possible valid paths from each starting point. We then keep track of the maximum gold collected among all these paths.

You can solve this problem in C++ using a technique called **Depth-First Search (DFS)**. Here's a breakdown of how you can approach it:

**Core Idea:**

The main idea is to explore all possible paths of collecting gold starting from each cell that contains gold. For each path, we keep track of the gold collected. Since we can start from any gold cell, we'll iterate through all the cells in the grid. If a cell has gold, we'll initiate a DFS from that cell to explore all reachable gold cells without revisiting any. We'll maintain a global variable to store the maximum gold found so far across all these explorations.

**Steps:**

1. **`is_valid(row, col, m, n)` function:**
    
    - This helper function will check if a given `(row, col)` is within the bounds of the grid (0 to `m-1` for rows and 0 to `n-1` for columns).
    - It will return `true` if the coordinates are valid, and `false` otherwise.
2. **`dfs(row, col, grid, visited, current_gold)` function:**
    
    - This is the recursive function that performs the Depth-First Search.
    - **Parameters:**
        - `row`, `col`: The current cell's row and column.
        - `grid`: The 2D vector representing the gold mine.
        - `visited`: A 2D boolean vector of the same size as `grid`, used to keep track of visited cells in the current path. Initialize it to `false` before starting a DFS from a new starting cell.
        - `current_gold`: The amount of gold collected so far in the current path.
    - **Base Case (Implicit):** The recursion stops when there are no more valid and unvisited adjacent cells with gold.
    - **Logic:**
        - Mark the current cell `(row, col)` as visited (`visited[row][col] = true`).
        - Add the gold in the current cell (`grid[row][col]`) to `current_gold`.
        - Update the global `max_gold` if `current_gold` is greater than the current `max_gold`.
        - Explore the four neighboring cells (up, down, left, right):
            - For each neighbor `(new_row, new_col)`:
                - Check if `(new_row, new_col)` is within the grid boundaries using `is_valid()`.
                - Check if the neighbor has gold (`grid[new_row][new_col] > 0`).
                - Check if the neighbor has not been visited in the current path (`!visited[new_row][new_col]`).
                - If all conditions are true, recursively call `dfs(new_row, new_col, grid, visited, current_gold)`.
        - **Backtrack:** After exploring all neighbors, mark the current cell as unvisited again (`visited[row][col] = false`). This is crucial so that this cell can be part of other possible paths starting from different cells.
3. **`main()` function:**
    
    - Read the dimensions of the grid `m` and `n`.
    - Create a 2D vector `grid` of size `m x n` to store the gold amounts.
    - Read the gold amounts for each cell from the input.
    - Initialize a variable `max_gold` to 0.
    - Iterate through each cell `(i, j)` of the `grid`.
    - If `grid[i][j]` has gold (greater than 0):
        - Create a 2D boolean vector `visited` of size `m x n` and initialize all elements to `false`.
        - Call the `dfs(i, j, grid, visited, 0)` function to start exploring paths from this cell.
    - After iterating through all starting gold cells, print the final value of `max_gold`.

**C++ Code Example:**

C++

```
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_gold = 0;

bool is_valid(int row, int col, int m, int n) {
    return row >= 0 && row < m && col >= 0 && col < n;
}

void dfs(int row, int col, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>& visited, int current_gold) {
    visited[row][col] = true;
    current_gold += grid[row][col];
    max_gold = max(max_gold, current_gold);

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; ++i) {
        int new_row = row + dr[i];
        int new_col = col + dc[i];

        if (is_valid(new_row, new_col, m, n) && grid[new_row][new_col] > 0 && !visited[new_row][new_col]) {
            dfs(new_row, new_col, m, n, grid, visited, current_gold);
        }
    }

    visited[row][col] = false; // Backtrack
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] > 0) {
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                dfs(i, j, m, n, grid, visited, 0);
            }
        }
    }

    cout << max_gold << endl;

    return 0;
}
```

**Explanation of the Code:**

- **`is_valid` Function:** Checks if a given row and column are within the grid boundaries.
- **`dfs` Function:**
    - Takes the current cell's coordinates, the grid, the visited array, and the current gold collected as input.
    - Marks the current cell as visited.
    - Adds the gold in the current cell to `current_gold`.
    - Updates `max_gold` if the `current_gold` is greater.
    - Iterates through the four possible neighbors (up, down, left, right).
    - For each neighbor, it checks if it's valid, has gold, and hasn't been visited. If all conditions are met, it recursively calls `dfs` for that neighbor.
    - **Crucially, after exploring all neighbors of a cell, it marks the cell as unvisited (`visited[row][col] = false`).** This backtracking step allows other paths to potentially include this cell later.
- **`main` Function:**
    - Reads the grid dimensions and the gold values.
    - Initializes `max_gold` to 0.
    - Iterates through each cell of the grid.
    - If a cell has gold, it creates a `visited` array and starts the DFS from that cell with an initial `current_gold` of 0.
    - Finally, it prints the `max_gold` found.

This DFS approach explores all possible valid paths starting from every gold-containing cell, ensuring that you find the maximum amount of gold that can be collected. The backtracking step is essential to correctly explore all combinations of paths.