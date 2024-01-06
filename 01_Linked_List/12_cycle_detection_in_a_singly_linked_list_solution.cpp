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


bool detectCycle(Node *head)
{
	if (head == nullptr || head -> next == nullptr) {
        return false;
    }
    Node* p = head;
    Node* q = head;

    while (p != nullptr && q != nullptr && q -> next != nullptr) {
        p = p -> next;
        q = q -> next -> next;

        if (p == q) {
            return true;
        }
    }
    return false;
}