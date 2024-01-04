// #include <cstddef>

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


int length(Node *head)
{
	int ans_length = 0;

    Node* temp = head;

    while (temp != NULL) {
        ans_length++;
        temp = temp -> next;
    }
    return ans_length;
}