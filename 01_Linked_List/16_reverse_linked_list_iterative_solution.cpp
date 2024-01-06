#include <cstddef>

class Node{
    public:
        int data;
        Node *next;
        Node() {
            this->data = 0;
            next = NULL;
        }
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
        Node(int data, Node* next) {
            this->data = data;
            this->next = next;
        }
};

Node *reverseLinkedList(Node *head) {
    if (head == nullptr || head -> next == nullptr) {
		return head;
	}
	Node* temp = head;
	Node* prev = nullptr;
	Node* newHead = head;
	while (temp != nullptr) {
		if (temp -> next == nullptr) {
			newHead = temp;
		}
		Node* temp1 = temp -> next;
		temp -> next = prev;
		prev = temp;
		temp = temp1;
	}
	return newHead;
}