# Rotated Palindrome Problem - Complete Guide

## Problem Statement

Given a string, determine if it can be transformed into a palindrome by rotating it (moving characters from one end to the other).

### Examples:

- `"aab"` → `"aba"` (after 2 right rotations) → **YES**
- `"abc"` → No rotation makes it palindromic → **NO**

## Visual Understanding

### Example 1: "aab"

```
Original: a a b
         ↑ ↑ ↑
         0 1 2

Rotation 0: "aab" → NOT palindrome (a≠b)
Rotation 1: "aba" → IS palindrome! (a=a, b=b)
Rotation 2: "baa" → NOT palindrome (b≠a)

Answer: YES
```

### Example 2: "abc"

```
Original: a b c
         ↑ ↑ ↑
         0 1 2

Rotation 0: "abc" → NOT palindrome (a≠c)
Rotation 1: "bca" → NOT palindrome (b≠a)
Rotation 2: "cab" → NOT palindrome (c≠b)

Answer: NO
```

## Algorithm Approaches

### 1. Brute Force Approach

**Time Complexity:** O(n²) - We try n rotations, each taking O(n) to check palindrome  
**Space Complexity:** O(n) - For storing rotated strings

```
For each possible rotation:
  1. Create rotated string by cutting at position i
  2. Check if rotated string is palindrome
  3. If yes, return true
  4. If no rotation works, return false
```

### 2. Optimal Approach (String Concatenation)

**Time Complexity:** O(n²) - Same as brute force but with better constants  
**Space Complexity:** O(n) - For doubled string

```
Key insight: All rotations of string s are substrings of s+s
Example: "aab" → "aabaab" contains "aab", "aba", "baa"

1. Create doubled string: s + s
2. Check each substring of length n for palindrome
3. Return true if any substring is palindrome
```

### 3. Most Optimal Approach (No Extra Strings)

**Time Complexity:** O(n²) - Same time but minimal space  
**Space Complexity:** O(1) - No extra strings created

```
For each rotation starting position:
  1. Use modular arithmetic to access characters
  2. Check palindrome condition using two pointers
  3. Return true if any rotation is palindrome
```

## Real-World Analogy

Think of this like a **circular necklace** with lettered beads:

- **Rotation** = choosing a different starting bead
- **Palindrome check** = seeing if the sequence reads the same forwards and backwards
- **Solution** = finding if any starting position gives a symmetric pattern

## Implementation Notes

1. **Edge Cases:**

   - Empty string: considered palindrome
   - Single character: always palindrome
   - All same characters: always palindrome

2. **Common Pitfalls:**

   - Forgetting to handle edge cases
   - Not considering all n rotations
   - Creating unnecessary string copies

3. **Optimization Tips:**
   - Use modular arithmetic for circular access
   - Early termination when palindrome found
   - Avoid creating new strings when possible

## Pattern Recognition

This problem combines:

- **String manipulation** (rotations)
- **Palindrome checking** (two-pointer technique)
- **Optimization** (avoiding unnecessary allocations)

Similar problems:

- Circular array rotation
- String cycle detection
- Palindrome variations (longest palindromic substring, etc.)
