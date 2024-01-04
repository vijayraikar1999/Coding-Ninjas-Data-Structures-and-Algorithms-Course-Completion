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

Node *deleteNode(Node *head, int pos)
{
	if (!head) 
    if (pos == 0) {
		Node* del = head;
		head = head -> next;
		delete del;
		return head;
	}
	Node* p = head;
	Node* q = head -> next;
	int i = 1;
	while (q != NULL && i < pos) {
		p = p -> next;
		q = q -> next;
		i++;
	}
	if (q) {
		p -> next = q -> next;
		delete q;
	}
	return head;
}