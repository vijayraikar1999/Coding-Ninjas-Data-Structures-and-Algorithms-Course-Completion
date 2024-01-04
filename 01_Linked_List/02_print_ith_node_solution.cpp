#include <cstddef>
#include <iostream>

using namespace std;

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

void printIthNode(Node *head, int i)
{
	int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        if (count == i) {
            cout << temp->data;
            return;
        }
        count++;
        temp = temp->next;
    }
}