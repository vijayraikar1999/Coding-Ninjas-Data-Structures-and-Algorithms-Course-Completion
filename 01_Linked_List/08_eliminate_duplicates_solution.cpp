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

Node *removeDuplicates(Node *head)
{
    if (!head) return nullptr;

	if (head -> next == nullptr) {
		return head;
	}
	Node* temp = head;
	while (temp != nullptr) {
		if (temp -> next != nullptr && (temp -> data == (temp -> next) -> data)) {
			Node* del = temp -> next;
			temp -> next = (temp -> next) -> next;
		} else {
			temp = temp -> next;
		}
	}
	return head;
}