#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Step 1: Handle edge cases
        // If the list is empty or has only one node, no cycle is possible.
        if (head == NULL || head->next == NULL) {
            return false;
        }

        // Step 2: Initialize pointers
        // The 'slow' pointer moves one step at a time.
        ListNode *slow = head;
        // The 'fast' pointer moves two steps at a time.
        ListNode *fast = head;

        // Step 3: Loop and move pointers
        // We continue as long as the fast pointer can safely move two steps forward.
        while (fast != NULL && fast->next != NULL) {
            // Move slow pointer one st1
            slow = slow->next;
            // Move fast pointer two steps
            fast = fast->next->next;

            // Step 4: Check for a meeting
            // If they point to the same node, we've found a cycle.
            if (slow == fast) {
                return true;
            }
        }

        // Step 5: No meeting
        // If the loop finishes, the fast pointer reached the end of the list.
        return false;
    }
};

// Helper function to test the code
int main() {
    // Example 1: Cycle
    ListNode* head1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node0 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);
    head1->next = node2;
    node2->next = node0;
    node0->next = node4;
    node4->next = node2; // Creates a cycle

    Solution sol;
    if (sol.hasCycle(head1)) {
        std::cout << "Example 1 has a cycle." << std::endl; // Expected
    } else {
        std::cout << "Example 1 does not have a cycle." << std::endl;
    }

    // Example 2: No Cycle
    ListNode* head2 = new ListNode(1);
    if (sol.hasCycle(head2)) {
        std::cout << "Example 2 has a cycle." << std::endl;
    } else {
        std::cout << "Example 2 does not have a cycle." << std::endl; // Expected
    }

    return 0;
}
0110101010000000000000