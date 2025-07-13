# Boats to Save People - Complete Guide

## Problem Statement in Simple Terms

You have a group of people with different weights, and you need to transport them using boats. Each boat can carry **at most 2 people** and has a **weight limit**. Find the minimum number of boats needed to carry everyone.

## Examples with Visual Explanation

### Example 1: people = [1,2], limit = 3

```
People weights: [1, 2]
Boat capacity: 3

Can person 1 (weight 1) + person 2 (weight 2) fit together?
1 + 2 = 3 ≤ 3 ✓ YES!

Boat 1: [Person 1, Person 2] → Total weight: 3
Result: 1 boat needed
```

### Example 2: people = [3,2,2,1], limit = 3

```
People weights: [3, 2, 2, 1]
Boat capacity: 3

Trying to fit people:
- Person with weight 3: Can only fit alone (3 ≤ 3)
- Person with weight 2: Can fit with person weight 1 (2+1=3 ≤ 3)
- Remaining person with weight 2: Must go alone

Boat 1: [Person weight 3] → Total weight: 3
Boat 2: [Person weight 2, Person weight 1] → Total weight: 3
Boat 3: [Person weight 2] → Total weight: 2
Result: 3 boats needed
```

## Algorithm Approaches

### Approach 1: Simple Greedy (First-Fit)

**Time Complexity:** O(n²) - Like checking every person against every other person  
**Space Complexity:** O(n) - Need to track who's already in a boat

```
Step-by-step process:
1. For each person not yet in a boat:
   2. Give them a boat
   3. Try to find a partner who can fit with them
   4. If found, put partner in same boat
   5. Move to next person without a boat
```

### Approach 2: Optimal Greedy (Two-Pointer)

**Time Complexity:** O(n log n) - Sorting takes most time  
**Space Complexity:** O(1) - Only need a few variables

```
Step-by-step process:
1. Sort people by weight (lightest to heaviest)
2. Use two pointers: lightest and heaviest
3. For each boat:
   - Always put the heaviest person in boat
   - If lightest person can also fit, put them too
   - Otherwise, heaviest person goes alone
4. Move pointers inward and repeat
```

## Visual Algorithm Trace

### Example: people = [3,2,2,1], limit = 3

#### Step 1: Sort people

```
Original: [3, 2, 2, 1]
Sorted:   [1, 2, 2, 3]
          ↑           ↑
      lightest    heaviest
```

#### Step 2: Two-pointer approach

```
Iteration 1:
[1, 2, 2, 3]
 ↑        ↑
 L        H

Check: 1 + 3 = 4 > 3 ❌
Action: Person 3 goes alone
Boats: 1

Iteration 2:
[1, 2, 2, 3]
 ↑     ↑
 L     H

Check: 1 + 2 = 3 ≤ 3 ✅
Action: Person 1 and 2 go together
Boats: 2

Iteration 3:
[1, 2, 2, 3]
    ↑
   L&H

Action: Last person (weight 2) goes alone
Boats: 3
```

## Why the Optimal Approach Works

### Key Insight

If the **lightest** person can't pair with the **heaviest** person, then the heaviest person can't pair with **anyone**.

### Proof

- Suppose lightest person L can't pair with heaviest person H: `L + H > limit`
- But L can pair with someone heavier than H: `L + H' ≤ limit` where `H' > H`
- This means: `L + H' ≤ limit < L + H`
- Therefore: `H' < H`
- **Contradiction!** H' can't be both > H and < H
- Conclusion: If L can't pair with H, then H must go alone

## Real-World Analogies

### Time Complexity Comparison

- **Simple O(n²):** Like checking every person at a party against every other person to see if they can share a table
- **Optimal O(n log n):** Like lining people up by height first, then pairing shortest with tallest

### Growth Rates

- With 10× more people:
  - Simple approach: ~100× longer (n² growth)
  - Optimal approach: ~33× longer (n log n growth)

## Edge Cases Handled

1. **Single person:** Gets their own boat
2. **Everyone same weight:** Pairs them optimally based on limit
3. **No one can pair:** Each person gets their own boat
4. **Perfect pairing:** Uses exactly n/2 boats when possible
5. **All weights equal to limit:** Each person needs their own boat

## Pattern Recognition

This problem combines several important concepts:

- **Greedy algorithms:** Making locally optimal choices
- **Two-pointer technique:** Efficient array traversal
- **Sorting:** Organizing data for optimal processing
- **Proof by contradiction:** Validating greedy choice

## Common Mistakes to Avoid

1. **Forgetting the 2-person limit:** Each boat can carry at most 2 people
2. **Not considering weight limit:** People must fit within boat capacity
3. **Inefficient pairing:** Not using optimal greedy strategy
4. **Edge case handling:** Empty arrays, single person, etc.

## Code Implementation Notes

- **Simple approach:** Good for understanding the problem
- **Optimal approach:** Better for large inputs and competitive programming
- **Variable naming:** Use descriptive names like `lightest_person`, `heaviest_person`
- **Comments:** Explain each major step and the reasoning behind it
