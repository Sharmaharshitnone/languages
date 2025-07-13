#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int x): data(x), next(NULL) {}
};

bool hasCycle(Node* head){
	if (head == NULL || head->next == NULL) {
		return false; // List is empty or has only one node
	}
	Node* slow = head;
	Node* fast = head;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next; // Move slow pointer by one step
		fast = fast->next->next; // Move fast pointer by two steps

		if (slow == fast) {
			return true; // Cycle detected
		}
	}
	return false; // No cycle detected
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
			tail = tail->next;
		}
		}
	if(hasCycle(head)){
		cout << "True" << endl;
	} else {
		cout << "False" << endl;
	}

return 0;

}
