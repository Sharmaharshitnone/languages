#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
      	Node(int val) : data(val), next(nullptr) {}
};

void reverseList(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    
    while (current) {
	next = current->next; // Store the next node
	current->next = prev; // Reverse the link
	prev = current;       // Move prev to current
	current = next;       // Move to the next node
    }
    
    head = prev; // Update head to the new first node
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
	cout << current->data << "->";
	current = current->next;
    }
    cout<<"NULL";
    cout << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    
    int n, val;
    std::cin >> n;
    
    while (n--) {
        std::cin >> val;
        Node* newNode = new Node(val);
        if (!head) head = tail = newNode;
        else tail = tail->next = newNode;
    }
	reverseList(head);
    printList(head);
    
    // Rest of your code here
    return 0;
}
