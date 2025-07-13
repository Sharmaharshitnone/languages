#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int x): data(x), next(NULL) {}
};

void middleNode(Node*& head){
	if (head == NULL || head->next == NULL) {
		return; // List is empty or has only one node
	}
	Node* slow = head;
	Node* fast = head;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next; // Move slow pointer by one step
		fast = fast->next->next; // Move fast pointer by two steps
	}
	head = slow;
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

int main(){
	int n, value;
	cin >> n;
	Node* head = NULL;
	Node* tail = NULL;
	while(n--){
		cin >> value;
		Node* newNode = new Node(value);
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}else{
			tail -> next = newNode;
			tail = newNode;
		}
	}
        middleNode(head);
        printList(head);
        return 0;


}
