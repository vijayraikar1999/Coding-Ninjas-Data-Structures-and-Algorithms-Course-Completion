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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{

	if (head1 == nullptr) {
		return head2;
	}
	if (head2 == nullptr) {
		return head1;
	}

    Node* i = head1;
	Node* j = head2;
	Node* k = head1;
	if (head1 -> data <= head2 -> data) {
		k = head1;
		i = head1 -> next;
	} else {
		k = head2;
		j = j -> next;
	}
	Node* newHead = k;

	while (i != nullptr && j != nullptr) {
		if (i -> data <= j -> data) {
			k -> next = i;
			i = i -> next;
			k = k -> next;
		} else {
			k -> next = j;
			j = j -> next;
			k = k -> next;
		}
	}

	while (i != nullptr) {
		k -> next = i;
		i = i -> next;
		k = k -> next;
	}

	while (j != nullptr) {
		k -> next = j;
		j = j -> next;
		k = k -> next;
	}

	return newHead;
}