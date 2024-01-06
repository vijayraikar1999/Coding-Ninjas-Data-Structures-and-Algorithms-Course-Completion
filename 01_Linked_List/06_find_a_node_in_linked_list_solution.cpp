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

int findNode(Node *head, int n){
    if (head == NULL) {
        return -1;
    }
    Node* temp = head;
    int i = 0;
    while (temp != NULL) {
        if (temp -> data == n) {
            return i;
        }
        temp = temp -> next;
    }
    return -1;
}