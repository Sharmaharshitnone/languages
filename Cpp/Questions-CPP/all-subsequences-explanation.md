# All Subsequences of a String - Complete Guide

## Problem Statement in Simple Terms

Given a string, find all possible **non-empty subsequences**. A subsequence is formed by deleting some or no characters from the original string **without changing the order** of remaining characters.

## Examples with Visual Explanation

### Example 1: "abc"

```
Original string: "abc"

All possible subsequences:
- Include only 'a': "a"
- Include only 'b': "b"
- Include only 'c': "c"
- Include 'a' and 'b': "ab"
- Include 'a' and 'c': "ac"
- Include 'b' and 'c': "bc"
- Include all: "abc"

Total: 7 subsequences
Output: a ab abc ac b bc c
```

### Example 2: "aa"

```
Original string: "aa"

All possible subsequences:
- Include first 'a': "a"
- Include second 'a': "a"
- Include both 'a's: "aa"

But we have duplicates! After removing duplicates:
- "a" (appears twice, but we only count once)
- "aa"

Total: 2 unique subsequences
Output: a aa
```

## Algorithm Approaches

### Approach 1: Bit Manipulation (Simple)

**Time Complexity:** O(n × 2^n) - Like trying every combination of toppings on a pizza  
**Space Complexity:** O(2^n × n) - Store all possible subsequences

```
Key idea: Each character can be either included or excluded
For n characters, we have 2^n total combinations

Visual for "abc":
Binary    Characters    Subsequence
001       ..a           "a"
010       .b.           "b"
011       .ba           "ab"
100       c..           "c"
101       c.a           "ac"
110       cb.           "bc"
111       cba           "abc"
```

### Approach 2: Recursion (Optimal for Understanding)

**Time Complexity:** O(n × 2^n) - Same as bit manipulation  
**Space Complexity:** O(n) stack space + O(2^n × n) for results

```
Key idea: At each position, make 2 choices:
1. Include current character
2. Exclude current character

Recursive tree for "abc":
                    ""
                  /    \
               ""              "a"
              /  \            /    \
           ""      "b"     "a"      "ab"
          / \     /  \     / \      /   \
        ""  "c" "b" "bc" "a" "ac" "ab" "abc"
```

### Approach 3: Iterative Building (Most Efficient)

**Time Complexity:** O(n × 2^n) - Same time complexity  
**Space Complexity:** O(2^n × n) - More predictable memory usage

```
Key idea: Start with empty set, for each character double the possibilities

For "abc":
Step 1: Start with [""]
Step 2: Add 'a' → ["", "a"]
Step 3: Add 'b' → ["", "a", "b", "ab"]
Step 4: Add 'c' → ["", "a", "b", "ab", "c", "ac", "bc", "abc"]
Step 5: Remove empty string → ["a", "b", "ab", "c", "ac", "bc", "abc"]
```

## Visual Algorithm Trace

### Bit Manipulation Approach for "abc"

```
String: "abc"
Positions: 0 1 2

For each number from 1 to 7 (2^3 - 1):

Number 1 = 001 binary:
- Position 0: 001 & 001 = 1 → include 'a'
- Position 1: 001 & 010 = 0 → skip 'b'
- Position 2: 001 & 100 = 0 → skip 'c'
- Result: "a"

Number 5 = 101 binary:
- Position 0: 101 & 001 = 1 → include 'a'
- Position 1: 101 & 010 = 0 → skip 'b'
- Position 2: 101 & 100 = 1 → include 'c'
- Result: "ac"
```

### Recursive Approach for "abc"

```
generateSubsequences("abc", 0, "")
├── Don't include 'a': generateSubsequences("abc", 1, "")
│   ├── Don't include 'b': generateSubsequences("abc", 2, "")
│   │   ├── Don't include 'c': "" (empty, skip)
│   │   └── Include 'c': "c" ✓
│   └── Include 'b': generateSubsequences("abc", 2, "b")
│       ├── Don't include 'c': "b" ✓
│       └── Include 'c': "bc" ✓
└── Include 'a': generateSubsequences("abc", 1, "a")
    ├── Don't include 'b': generateSubsequences("abc", 2, "a")
    │   ├── Don't include 'c': "a" ✓
    │   └── Include 'c': "ac" ✓
    └── Include 'b': generateSubsequences("abc", 2, "ab")
        ├── Don't include 'c': "ab" ✓
        └── Include 'c': "abc" ✓
```

## Why This Problem is Exponential

### Mathematical Proof

- For each of n characters, we have 2 choices: include or exclude
- Total combinations = 2 × 2 × 2 × ... (n times) = 2^n
- Excluding empty subsequence = 2^n - 1
- Each subsequence takes O(n) time to generate
- **Total time: O(n × 2^n)**

### Real-World Analogy

Think of it like choosing items from a menu:

- With 1 item: 2 choices (take it or leave it) → 1 non-empty combination
- With 2 items: 4 choices → 3 non-empty combinations
- With 3 items: 8 choices → 7 non-empty combinations
- With 10 items: 1024 choices → 1023 non-empty combinations!

## Handling Duplicates

### The Challenge

When the input string has duplicate characters, we get duplicate subsequences.

- "aa" → raw subsequences: "a", "a", "aa"
- After removing duplicates: "a", "aa"

### Solutions

1. **Use std::set**: Automatically handles duplicates during insertion
2. **Use std::unordered_set**: Faster insertion but no ordering
3. **Sort and remove duplicates**: Manual approach

## Edge Cases

1. **Empty string**: No subsequences (return empty list)
2. **Single character**: One subsequence (the character itself)
3. **All same characters**: Handle duplicates properly
4. **Very long strings**: Exponential growth becomes impractical

## Performance Comparison

| Input Size | Subsequences | Bit Manipulation | Recursion | Iterative |
| ---------- | ------------ | ---------------- | --------- | --------- |
| 3 chars    | 7            | Fast             | Fast      | Fast      |
| 10 chars   | 1,023        | Good             | Good      | Good      |
| 20 chars   | 1,048,575    | Slow             | Slow      | Slow      |
| 25 chars   | 33,554,431   | Very Slow        | Very Slow | Very Slow |

## Common Mistakes to Avoid

1. **Including empty subsequence**: Problem asks for non-empty only
2. **Not handling duplicates**: Use set or similar data structure
3. **Wrong bit manipulation**: Make sure to check bits correctly
4. **Stack overflow**: Recursion depth can be large for long strings
5. **Memory issues**: 2^n subsequences can use enormous memory

## Pattern Recognition

This problem appears in various forms:

- **Subset generation**: Generate all subsets of a set
- **Power set**: Mathematical concept of all possible subsets
- **Combinatorial enumeration**: Counting and listing combinations
- **Dynamic programming**: Some variations can be optimized

## Code Implementation Tips

1. **Choose the right approach**:

   - Bit manipulation: Good for understanding binary operations
   - Recursion: Most intuitive and easy to modify
   - Iterative: Most predictable memory usage

2. **Handle duplicates**: Always use std::set or similar

3. **Memory management**: Be aware of exponential space requirements

4. **Input validation**: Check for reasonable string lengths

The key insight is that this problem is inherently exponential - there's no way to avoid generating 2^n subsequences for n characters. The different approaches just provide different ways to generate them efficiently.
