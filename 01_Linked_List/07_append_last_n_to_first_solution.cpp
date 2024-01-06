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

Node *appendLastNToFirst(Node *head, int n)
{
	if (!head) return NULL;
	if (head -> next == NULL || n == 0) {
		return head;
	}
	int length = 0;
	Node* temp = head;
	while (temp != NULL) {
		length++;
		temp = temp -> next;
	}

	if (n == length) {
		return head;
	}

	Node* prev = nullptr;
	temp = head;

	for (int i = 0; i < length - n; i++) {
		prev = temp;
		temp = temp -> next;
	}

	prev -> next = nullptr;
	Node* newHead = temp;
	while ((temp -> next) != nullptr) {
		temp = temp -> next;
	}
	temp -> next = head;
	return newHead;

}