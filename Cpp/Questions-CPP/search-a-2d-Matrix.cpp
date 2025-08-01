// How It Works 🧐
//
//     Virtual Array: Don't actually create a new 1D array. Instead, use math to treat the mtimesn matrix as if it were a single array of size m * n. The search space will be from index 0 to (m * n) - 1.
//
//     Binary Search: Apply a classic binary search on this virtual array.
//
//         In each step, you'll calculate a mid index.
//
//         The key is to convert this 1D mid index back into 2D (row, col) coordinates.
//
//             row = mid / num_cols
//
//             col = mid % num_cols
//
//         Once you have the coordinates, you can access the element matrix[row][col] and compare it to the target to narrow your search space.
//
// This approach performs a single binary search over all mtimesn elements, achieving the required O(log(mcdotn)) time complexity.
#include <iostream>
#include <vector>

bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
    // Handle edge cases
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();
    
    // Treat the matrix as a virtual 1D array from index 0 to (rows * cols) - 1
    int low = 0;
    int high = (rows * cols) - 1;

    while (low <= high) {
        int mid_idx = low + (high - low) / 2;
        
        // Convert the 1D mid-point back to 2D coordinates
        int mid_val = matrix[mid_idx / cols][mid_idx % cols];

        if (mid_val == target) {
            return true; // Target found!
        } 
        
        if (mid_val < target) {
            low = mid_idx + 1; // Search in the right half
        } else {
            high = mid_idx - 1; // Search in the left half
        }
    }

    return false; // Target not found
}

// Example
int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 4, 8},
        {10, 11, 12, 13},
        {14, 20, 30, 40}
    };

    int target1 = 10;
    std::cout << "Target " << target1 << " found: " 
              << std::boolalpha << searchMatrix(matrix, target1) << std::endl;

    int target2 = 15;
    std::cout << "Target " << target2 << " found: " 
              << std::boolalpha << searchMatrix(matrix, target2) << std::endl;

    return 0;
}
