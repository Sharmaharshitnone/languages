#include <iostream>
#include <vector>
#include <unordered_set>

// Step 1: Define the linked list node structure
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Step 2: Simple approach using hash set (easier to understand)
bool detectCycleWithHashSet(ListNode *head)
{
    // Step 2a: Handle edge cases first
    if (head == nullptr || head->next == nullptr)
    {
        return false; // Empty list or single node can't have a cycle
    }

    // Step 2b: Create a set to remember which nodes we've visited
    std::unordered_set<ListNode *> visited_nodes;

    ListNode *current = head;

    // Step 2c: Walk through the list
    while (current != nullptr)
    {
        // Step 2d: Have we seen this node before?
        if (visited_nodes.find(current) != visited_nodes.end())
        {
            return true; // Yes! We found a cycle
        }

        // Step 2e: Remember this node for next time
        visited_nodes.insert(current);

        // Step 2f: Move to the next node
        current = current->next;
    }

    // Step 2g: We reached the end without seeing any repeated nodes
    return false;
}

// Step 3: Optimal approach using Floyd's cycle detection algorithm
bool detectCycleWithTwoPointers(ListNode *head)
{
    // Step 3a: Handle edge cases
    if (head == nullptr || head->next == nullptr)
    {
        return false; // Empty list or single node can't have a cycle
    }

    // Step 3b: Set up our two "runners"
    ListNode *slow_runner = head; // This one moves 1 step at a time (like a turtle)
    ListNode *fast_runner = head; // This one moves 2 steps at a time (like a rabbit)

    // Step 3c: Let them race!
    while (fast_runner != nullptr && fast_runner->next != nullptr)
    {
        // Step 3d: Move the slow runner 1 step forward
        slow_runner = slow_runner->next;

        // Step 3e: Move the fast runner 2 steps forward
        fast_runner = fast_runner->next->next;

        // Step 3f: Did they meet? If so, there's a cycle!
        if (slow_runner == fast_runner)
        {
            return true; // They met inside the cycle
        }
    }

    // Step 3g: The fast runner reached the end, so no cycle
    return false;
}

// Step 4: Helper function to create a linked list for testing
ListNode *createLinkedList(const std::vector<int> &values, int cycle_position)
{
    if (values.empty())
        return nullptr;

    // Step 4a: Create all the nodes first
    std::vector<ListNode *> nodes;
    for (int val : values)
    {
        nodes.push_back(new ListNode(val));
    }

    // Step 4b: Connect all nodes in sequence
    for (int i = 0; i < nodes.size() - 1; ++i)
    {
        nodes[i]->next = nodes[i + 1];
    }

    // Step 4c: Create a cycle if requested
    if (cycle_position >= 0 && cycle_position < nodes.size())
    {
        // Make the last node point back to the cycle_position node
        nodes[nodes.size() - 1]->next = nodes[cycle_position];
    }

    return nodes[0];
}

int main()
{
    // Step 5: Read the input
    int n;
    std::cin >> n;

    std::vector<int> values(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> values[i];
    }

    int cycle_pos;
    std::cin >> cycle_pos;

    // Step 6: Create the linked list
    ListNode *head = createLinkedList(values, cycle_pos >= n ? -1 : cycle_pos);

    // Step 7: Test our cycle detection
    bool result = detectCycleWithTwoPointers(head);

    // Step 8: Output the answer
    std::cout << (result ? "true" : "false") << std::endl;

    return 0;
}

/*
DETAILED EXPLANATION OF WHY TWO POINTERS WORK:

Think of it like this racing analogy:
- Imagine two runners on a track
- One runs at 1 mph (slow), one runs at 2 mph (fast)
- If the track is straight, the fast runner reaches the end first
- If the track is circular, the fast runner will eventually lap the slow runner

In our linked list:
- If there's no cycle, fast pointer reaches the end (nullptr)
- If there's a cycle, both pointers get "trapped" in the cycle
- Inside the cycle, fast pointer gains 1 position on slow pointer each step
- Since the cycle has finite size, they must eventually meet

Mathematical proof:
- Let's say slow pointer enters cycle after k steps
- Fast pointer enters cycle after k/2 steps (since it's 2x faster)
- Once both are in cycle, fast pointer is (k/2) steps ahead
- Each iteration, fast pointer gets 1 step closer to slow pointer
- They will meet after at most (cycle_length) iterations

COMPARISON OF APPROACHES:

Hash Set Approach:
✅ Easy to understand - just remember what you've seen
✅ Straightforward logic
❌ Uses O(n) extra memory
❌ Slower due to hash operations

Two Pointers Approach:
✅ Uses only O(1) extra memory
✅ Faster in practice
✅ Elegant algorithm
❌ Harder to understand initially
❌ Requires mathematical thinking

Real-world analogies:
Hash Set = Dropping breadcrumbs in a maze
Two Pointers = Racing two cars on a track

Both solve the problem correctly, but two pointers is optimal!
*/
