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

Node *reverseLinkedListRec(Node *head)
{
    if (head == nullptr || head -> next == nullptr) {
		return head;
	}

	Node* right_head = reverseLinkedListRec(head -> next);
	Node* temp = right_head;
	while (temp -> next != nullptr) {
		temp = temp -> next;
	}
	temp -> next = head;
	head -> next = nullptr;
	return right_head;

}