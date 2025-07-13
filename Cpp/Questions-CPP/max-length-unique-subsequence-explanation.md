# Maximum Length of Unique Character Subsequence

## Problem Statement

Given an array of strings, find the maximum possible length of a string formed by concatenating a subsequence of strings where all characters are unique.

## Problem Breakdown

**Input:**

- Array of strings
- Each string contains only lowercase letters

**Output:**

- Maximum length of concatenated string with unique characters

**Example:**

```
Input: ["un", "iq", "ue"]
Output: 4

Valid concatenations:
- "" (length 0)
- "un" (length 2) ✓
- "iq" (length 2) ✓
- "ue" (length 2) ✓
- "uniq" (length 4) ✓ - all characters unique
- "ique" (length 4) ✓ - all characters unique
- "unue" (length 4) ❌ - 'u' appears twice

Maximum length: 4
```

## Visual Representation

```
Array: ["un", "iq", "ue"]

Step 1: Check internal uniqueness
"un" → u,n ✓ (unique)
"iq" → i,q ✓ (unique)
"ue" → u,e ✓ (unique)

Step 2: Try all combinations
∅           → ""     (length 0)
{0}         → "un"   (length 2) ✓
{1}         → "iq"   (length 2) ✓
{2}         → "ue"   (length 2) ✓
{0,1}       → "uniq" (length 4) ✓ (u,n,i,q all unique)
{0,2}       → "unue" (length 4) ❌ (u appears twice)
{1,2}       → "ique" (length 4) ✓ (i,q,u,e all unique)
{0,1,2}     → "unique" (length 6) ❌ (u appears twice)

Maximum: 4
```

## Approaches

### 1. Simple Backtracking Approach O(2^n)

**File:** `fast-max-length-unique-subsequence.cpp`

**Logic:**

- Try all possible subsequences using recursive backtracking
- For each subsequence, check if all characters are unique
- Track the maximum length found

**Key Steps:**

1. Filter strings with internal duplicate characters
2. Use backtracking to try all combinations
3. For each combination, check character uniqueness
4. Track maximum length

**Time Complexity:** O(2^n × m)

- 2^n possible subsequences to try
- m characters to check for each subsequence
- With 16 strings, that's 65,536 combinations maximum

**Space Complexity:** O(m)

- Recursion stack depth at most n
- Character set storage

### 2. Optimal Bit Manipulation Approach O(2^n)

**File:** `max-length-unique-subsequence.cpp`

**Logic:**

- Convert each string to a bitmask representing its characters
- Use bitwise operations for super-fast character conflict checking
- Try all combinations using bit manipulation

**Key Insight:** Since we only have 26 lowercase letters, we can represent each string as a 32-bit integer where bit i represents whether character ('a' + i) is present.

**Bitmask Example:**

```
"abc" → bits 0,1,2 set → mask = 7 (binary: 0000111)
"def" → bits 3,4,5 set → mask = 56 (binary: 0111000)
Overlap check: 7 & 56 = 0 (no common bits = no common characters)
```

**Time Complexity:** O(2^n + total_string_length)

- Converting to bitmasks: O(total_string_length)
- Trying combinations: O(2^n × n)
- But each character check is O(1) instead of O(m)

**Space Complexity:** O(n)

- One bitmask and length per string

## Algorithm Comparison

| Approach         | Time       | Space | Best For               |
| ---------------- | ---------- | ----- | ---------------------- |
| Backtracking     | O(2^n × m) | O(m)  | Learning/Understanding |
| Bit Manipulation | O(2^n)     | O(n)  | Performance            |

## Real-World Analogies

**Backtracking:** Like trying on different combinations of clothes and checking each outfit in the mirror individually.

**Bit Manipulation:** Like having a smart wardrobe system that instantly knows which clothes conflict based on pre-computed "style fingerprints."

## Edge Cases

1. **Empty array:** Return 0
2. **Single string:** Return its length if no internal duplicates
3. **All strings conflict:** Return length of longest single valid string
4. **All strings compatible:** Return sum of all string lengths
5. **Strings with internal duplicates:** Filter them out first

## Example Walkthrough

**Input:** ["un", "iq", "ue"]

**Step 1:** Convert to bitmasks

- "un" → u(bit 20) + n(bit 13) → mask = 2^20 + 2^13 = 1056768
- "iq" → i(bit 8) + q(bit 16) → mask = 2^8 + 2^16 = 65792
- "ue" → u(bit 20) + e(bit 4) → mask = 2^20 + 2^4 = 1048592

**Step 2:** Try combinations

- Combination 001 (binary) → "un" → length 2
- Combination 010 (binary) → "iq" → length 2
- Combination 100 (binary) → "ue" → length 2
- Combination 011 (binary) → "un" + "iq" → check: 1056768 & 65792 = 0 ✓ → length 4
- Combination 101 (binary) → "un" + "ue" → check: 1056768 & 1048592 ≠ 0 ❌ (u conflicts)
- Combination 110 (binary) → "iq" + "ue" → check: 65792 & 1048592 = 0 ✓ → length 4
- Combination 111 (binary) → all three → conflicts detected ❌

**Result:** Maximum length = 4

## When to Use Each Approach

- **Use Backtracking** when learning the problem or for small inputs
- **Use Bit Manipulation** for competitive programming or when performance matters
- **Both approaches** handle the same constraints (n ≤ 16) efficiently

The bit manipulation approach is significantly faster in practice due to the efficiency of bitwise operations and reduced memory allocation.
