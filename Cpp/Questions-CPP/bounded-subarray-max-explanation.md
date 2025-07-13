# Bounded Subarray Maximum Problem

## Problem Statement

Given an array of integers and two bounds (left and right), count the number of contiguous subarrays where the maximum element is between left and right (inclusive).

## Problem Breakdown

**Input:**

- Array of integers: `nums`
- Two integers: `left` and `right`

**Output:**

- Count of subarrays where `left ≤ max(subarray) ≤ right`

**Example:**

```
Array: [2, 1, 4, 3]
Range: [2, 3]
Answer: 3

Valid subarrays:
- [2] → max = 2 ✓
- [2, 1] → max = 2 ✓
- [3] → max = 3 ✓
```

## Visual Representation

```
Array: [2, 1, 4, 3]  Range: [2, 3]

All possible subarrays:
Index 0: [2] ✓, [2,1] ✓, [2,1,4] ✗, [2,1,4,3] ✗
Index 1: [1] ✗, [1,4] ✗, [1,4,3] ✗
Index 2: [4] ✗, [4,3] ✗
Index 3: [3] ✓

Legend: ✓ = valid (max in range), ✗ = invalid
```

## Approaches

### 1. Brute Force Approach O(n²)

**File:** `fast-bounded-subarray-max.cpp`

**Logic:** For each starting position, extend the subarray and track the maximum.

**Key Optimization:** Break early when maximum exceeds the right bound.

**Time Complexity:** O(n²)

- For each of n starting positions, we extend up to n positions
- Early termination reduces average case

**Space Complexity:** O(1) additional space

### 2. Contribution Counting O(n²)

**File:** `bounded-subarray-max.cpp`

**Logic:** For each element that can be a valid maximum, count how many subarrays it contributes to.

**Key Insight:** An element is the maximum of subarrays that include it but don't include any larger element.

**Time Complexity:** O(n²)

- For each element, scan left and right until finding a larger element
- Better than brute force for arrays with many large elements

**Space Complexity:** O(1) additional space

### 3. Optimal Sliding Window O(n)

**File:** `optimal-bounded-subarray-max.cpp`

**Logic:** Use inclusion-exclusion principle:

- Count subarrays with max ≤ right
- Subtract subarrays with max ≤ (left-1)
- Result = subarrays with max in [left, right]

**Key Technique:** Sliding window to count subarrays with max ≤ limit

**Time Complexity:** O(n)

- Two passes through the array
- Each element processed at most twice

**Space Complexity:** O(1) additional space

## Algorithm Comparison

| Approach     | Time  | Space | Best Case           | Worst Case                      |
| ------------ | ----- | ----- | ------------------- | ------------------------------- |
| Brute Force  | O(n²) | O(1)  | Many large elements | All elements in range           |
| Contribution | O(n²) | O(1)  | Few valid elements  | Many consecutive valid elements |
| Optimal      | O(n)  | O(1)  | Always optimal      | Always optimal                  |

## Real-World Analogies

**Brute Force:** Like checking every possible pizza slice size in a restaurant menu individually.

**Contribution Counting:** Like counting how many customers each pizza size can satisfy (based on their preferences).

**Optimal:** Like using mathematics to calculate the answer without checking every possibility - similar to using formulas instead of counting by hand.

## Edge Cases Handled

1. **Single element arrays**
2. **All elements outside range**
3. **All elements inside range**
4. **Empty arrays** (handled by input constraints)
5. **Range with left > right** (handled by input constraints)
6. **Large numbers** (using long long for counts)

## Test Cases

```cpp
// Test Case 1: Given example
Array: [2, 1, 4, 3], left = 2, right = 3
Expected: 3

// Test Case 2: All elements in range
Array: [2, 3, 2], left = 2, right = 3
Expected: 6 (all subarrays valid)

// Test Case 3: No elements in range
Array: [1, 5, 6], left = 2, right = 4
Expected: 0

// Test Case 4: Single element
Array: [3], left = 2, right = 4
Expected: 1
```

## When to Use Each Approach

- **Use Brute Force** when learning the problem or for small inputs
- **Use Contribution Counting** when you need to understand the mathematical structure
- **Use Optimal** for large inputs or when performance matters

The optimal O(n) solution is always preferred for competitive programming and production code.
