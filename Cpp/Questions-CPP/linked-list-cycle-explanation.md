# Linked List Cycle Detection

## Problem Statement

Given the head of a linked list, determine if the linked list has a cycle in it. A cycle occurs when a node's next pointer points back to a previous node in the list.

## Problem Breakdown

**Input:**

- Head of a linked list
- Position where tail connects (for testing purposes)

**Output:**

- `true` if there's a cycle
- `false` if there's no cycle

**Example 1:**

```
Input: [1,3,4] with tail connecting to position 2
List: 1 → 3 → 4 → (back to 4)
Output: true
```

**Example 2:**

```
Input: [1,2] with no cycle
List: 1 → 2 → NULL
Output: false
```

## Visual Representation

```
Cycle Example:
Position: 0   1   2
Values:  [1] [3] [4]
          ↓   ↓   ↓
          1 → 3 → 4
              ↑   ↓
              └───┘

No Cycle Example:
[1] → [2] → [3] → NULL
```

## Approaches

### 1. Hash Set Approach O(n) time, O(n) space

**File:** `comprehensive-linked-list-cycle.cpp` (detectCycleWithHashSet)

**Logic:**

- Keep track of all visited nodes in a hash set
- If we encounter a node we've seen before, there's a cycle
- If we reach the end (null), there's no cycle

**Step-by-step:**

1. Create an empty hash set
2. Traverse the list node by node
3. For each node, check if it's already in the set
4. If yes → cycle found
5. If no → add to set and continue
6. If we reach null → no cycle

**Time Complexity:** O(n)

- Visit each node at most once
- Hash set operations are O(1) average

**Space Complexity:** O(n)

- Store up to n nodes in the hash set

### 2. Floyd's Cycle Detection (Two Pointers) O(n) time, O(1) space

**File:** `comprehensive-linked-list-cycle.cpp` (detectCycleWithTwoPointers)

**Logic:**

- Use two pointers moving at different speeds
- Slow pointer moves 1 step, fast pointer moves 2 steps
- If there's a cycle, they will eventually meet
- If there's no cycle, fast pointer reaches the end

**Step-by-step:**

1. Initialize slow and fast pointers to head
2. Move slow pointer 1 step forward
3. Move fast pointer 2 steps forward
4. If they meet → cycle detected
5. If fast pointer reaches end → no cycle

**Time Complexity:** O(n)

- Slow pointer visits each node at most once
- Fast pointer visits each node at most twice

**Space Complexity:** O(1)

- Only uses two pointer variables

## Algorithm Comparison

| Approach     | Time | Space | Pros                      | Cons                 |
| ------------ | ---- | ----- | ------------------------- | -------------------- |
| Hash Set     | O(n) | O(n)  | Easy to understand        | Uses extra memory    |
| Two Pointers | O(n) | O(1)  | Memory efficient, elegant | Harder to understand |

## Why Floyd's Algorithm Works

**The Racing Analogy:**

- Think of two runners on a track
- Slow runner: 1 mph, Fast runner: 2 mph
- Straight track: Fast runner reaches end first
- Circular track: Fast runner eventually laps slow runner

**Mathematical Proof:**

1. If no cycle: Fast pointer reaches end before meeting slow
2. If cycle exists: Both pointers eventually enter the cycle
3. Inside cycle: Fast pointer gains 1 position on slow each step
4. Since cycle has finite length: They must eventually meet

**Visual Example:**

```
Step 1: S=1, F=2     Step 2: S=2, F=4     Step 3: S=3, F=2
        F             S     F             S   F
        ↓             ↓     ↓             ↓   ↓
    1 → 2 → 3 → 4    1 → 2 → 3 → 4      1 → 2 → 3 → 4
        ↑       ↓        ↑       ↓          ↑       ↓
        └───────┘        └───────┘          └───────┘

Step 4: They meet at position 4!
```

## Implementation Details

### Edge Cases Handled:

1. **Empty list:** Return false
2. **Single node:** Return false
3. **Two nodes with cycle:** Properly detected
4. **Large cycles:** Algorithm remains efficient
5. **Self-loop:** Node pointing to itself

### Key Implementation Points:

1. **Null checking:** Always check `fast != null && fast->next != null`
2. **Initialization:** Both pointers start at head
3. **Movement:** Move slow first, then fast (order doesn't matter)
4. **Comparison:** Use pointer equality, not value equality

## Real-World Applications

1. **Memory leak detection:** Finding circular references
2. **Infinite loop detection:** In state machines
3. **Graph cycle detection:** Modified for general graphs
4. **Deadlock detection:** In concurrent systems

## Common Mistakes

1. **Not checking fast->next:** Can cause null pointer dereference
2. **Using value comparison:** Should compare pointer addresses
3. **Wrong initialization:** Starting pointers at different positions
4. **Forgetting edge cases:** Empty or single-node lists

## Practice Variations

1. **Find cycle start:** Where does the cycle begin?
2. **Cycle length:** How long is the cycle?
3. **Remove cycle:** Break the cycle while preserving the list
4. **Multiple cycles:** Detect if there are multiple disconnected cycles

## Complexity Analysis Summary

**Time Complexity Analysis:**

- Best case: O(1) - cycle detected immediately
- Average case: O(n) - traverse part of the list
- Worst case: O(n) - traverse entire list

**Space Complexity Analysis:**

- Hash Set: O(n) - proportional to number of nodes
- Two Pointers: O(1) - only two variables regardless of list size

The two-pointer approach is preferred in interviews and production code due to its optimal space complexity and elegant algorithm design.
