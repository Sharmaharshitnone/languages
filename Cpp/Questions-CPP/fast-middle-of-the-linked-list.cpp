
#include <iostream>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        // Step 1: Initialize two pointers, slow and fast, at the head.
        ListNode *slow_ptr = head;
        ListNode *fast_ptr = head;

        // Step 2: Move pointers through the list.
        // The loop continues as long as fast_ptr can make a full two-step jump.
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            // Move slow_ptr by one step.
            slow_ptr = slow_ptr->next;
            // Move fast_ptr by two steps.
            fast_ptr = fast_ptr->next->next;
        }

        // Step 3: Return the slow_ptr.
        // By the time the fast_ptr reaches the end, slow_ptr is at the middle.
        return slow_ptr;
    }
};

// Helper function to print the list from a given node (for testing)
void printList(ListNode *node)
{
    while (node != NULL)
    {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main()
{
    // Example 1: Odd number of nodes
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode *middle1 = sol.middleNode(head1);
    std::cout << "Middle of [1,2,3,4,5] is: ";
    printList(middle1); // Expected output: 3 4 5

    // Example 2: Even number of nodes
    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    head2->next->next->next->next->next = new ListNode(6);

    ListNode *middle2 = sol.middleNode(head2);
    std::cout << "Middle of [1,2,3,4,5,6] is: ";
    printList(middle2); // Expected output: 4 5 6

    return 0;
}
