#include <iostream>
#include <vector>

// Node structure
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Visual demonstration of Floyd's cycle detection
bool detectCycleWithVisualization(ListNode *head)
{
    std::cout << "=== FLOYD'S CYCLE DETECTION VISUALIZATION ===" << std::endl;
    std::cout << std::endl;

    if (head == nullptr || head->next == nullptr)
    {
        std::cout << "Edge case: Empty list or single node - no cycle possible" << std::endl;
        return false;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    int step = 0;

    std::cout << "Starting the race between turtle (slow) and rabbit (fast):" << std::endl;
    std::cout << "Turtle moves 1 step at a time, Rabbit moves 2 steps at a time" << std::endl;
    std::cout << std::endl;

    while (fast != nullptr && fast->next != nullptr)
    {
        step++;

        // Move pointers
        slow = slow->next;
        fast = fast->next->next;

        std::cout << "Step " << step << ":" << std::endl;
        std::cout << "  Turtle is at node with value: " << slow->val << std::endl;
        std::cout << "  Rabbit is at node with value: " << fast->val << std::endl;

        // Check if they meet
        if (slow == fast)
        {
            std::cout << "  🎉 THEY MET! Cycle detected!" << std::endl;
            std::cout << std::endl;
            std::cout << "Why did they meet?" << std::endl;
            std::cout << "- Both pointers are now trapped in the cycle" << std::endl;
            std::cout << "- Rabbit gains 1 position on turtle each step" << std::endl;
            std::cout << "- Since cycle has finite length, they must eventually meet" << std::endl;
            return true;
        }

        std::cout << "  They haven't met yet, continuing..." << std::endl;
        std::cout << std::endl;

        // Safety check to avoid infinite loops in demo
        if (step > 20)
        {
            std::cout << "  (Stopping demo after 20 steps to avoid infinite output)" << std::endl;
            break;
        }
    }

    std::cout << "Rabbit reached the end of the list - no cycle detected!" << std::endl;
    std::cout << std::endl;
    std::cout << "Why no cycle?" << std::endl;
    std::cout << "- Rabbit reached nullptr (end of list)" << std::endl;
    std::cout << "- If there was a cycle, rabbit would never reach the end" << std::endl;
    return false;
}

// Create test linked lists
ListNode *createTestList1()
{
    // Create list: 1 -> 2 -> 3 -> 4 -> back to 2 (cycle)
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Creates cycle back to node2

    return node1;
}

ListNode *createTestList2()
{
    // Create list: 1 -> 2 -> 3 -> nullptr (no cycle)
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);

    node1->next = node2;
    node2->next = node3;
    node3->next = nullptr; // No cycle

    return node1;
}

int main()
{
    std::cout << "🔍 LINKED LIST CYCLE DETECTION DEMO" << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << std::endl;

    // Test 1: List with cycle
    std::cout << "TEST 1: List with cycle [1 -> 2 -> 3 -> 4 -> back to 2]" << std::endl;
    std::cout << "Visual: 1 -> 2 -> 3 -> 4" << std::endl;
    std::cout << "             ↑         ↓" << std::endl;
    std::cout << "             └─────────┘" << std::endl;
    std::cout << std::endl;

    ListNode *list1 = createTestList1();
    bool result1 = detectCycleWithVisualization(list1);
    std::cout << "Result: " << (result1 ? "CYCLE DETECTED" : "NO CYCLE") << std::endl;
    std::cout << std::endl;

    std::cout << "=============================================" << std::endl;
    std::cout << std::endl;

    // Test 2: List without cycle
    std::cout << "TEST 2: List without cycle [1 -> 2 -> 3 -> nullptr]" << std::endl;
    std::cout << "Visual: 1 -> 2 -> 3 -> nullptr" << std::endl;
    std::cout << std::endl;

    ListNode *list2 = createTestList2();
    bool result2 = detectCycleWithVisualization(list2);
    std::cout << "Result: " << (result2 ? "CYCLE DETECTED" : "NO CYCLE") << std::endl;
    std::cout << std::endl;

    std::cout << "🎯 KEY INSIGHTS:" << std::endl;
    std::cout << "1. If there's a cycle, fast pointer will eventually catch slow pointer" << std::endl;
    std::cout << "2. If there's no cycle, fast pointer will reach the end first" << std::endl;
    std::cout << "3. This works because fast pointer gains 1 step on slow pointer each iteration" << std::endl;
    std::cout << "4. In a finite cycle, they must eventually meet!" << std::endl;

    return 0;
}

/*
This visualization helps you understand:

1. How the two pointers move at different speeds
2. Why they meet if there's a cycle
3. Why fast pointer reaches the end if there's no cycle
4. The step-by-step process of the algorithm

The key insight is the race analogy:
- On a straight track, fast runner wins
- On a circular track, fast runner eventually laps slow runner
*/
