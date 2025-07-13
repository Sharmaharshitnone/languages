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
    ListNode *reverseList(ListNode *head)
    {
        // Step 1: Initialize pointers
        // previous_node will store the node we just visited
        ListNode *previous_node = NULL;
        // current_node is the node we are currently processing
        ListNode *current_node = head;

        // Step 2: Iterate through the list
        // We continue as long as we haven't fallen off the end of the list
        while (current_node != NULL)
        {
            // Store the next node in the original list before we change anything
            ListNode *next_node = current_node->next;

            // This is the reversal step!
            // Make the current node point to the one that came before it
            current_node->next = previous_node;

            // Move our pointers one step forward for the next iteration
            // The node we just processed becomes the new 'previous_node'
            previous_node = current_node;
            // And we move on to the next node in the original list
            current_node = next_node;
        }

        // Step 3: Return the new head
        // When the loop ends, previous_node is pointing to the new head of the reversed list
        return previous_node;
    }
};

// Helper function to print the list (for testing)
void printList(ListNode *head)
{
    while (head != NULL)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    // Example 1
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode *reversed_head1 = sol.reverseList(head1);
    printList(reversed_head1); // Expected output: 5 4 3 2 1

    // Example 2
    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    ListNode *reversed_head2 = sol.reverseList(head2);
    printList(reversed_head2); // Expected output: 2 1

    return 0;
}
