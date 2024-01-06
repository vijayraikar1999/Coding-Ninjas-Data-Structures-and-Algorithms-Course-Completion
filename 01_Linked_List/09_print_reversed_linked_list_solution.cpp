#include <iostream>
#include<string>
#include <cstddef>

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

void printReverse(Node *head)
{
    if (head == nullptr) {
		return;
	}
	Node* temp = head;
	string ans_string = to_string(head -> data);
	temp = head -> next;
	while (temp != nullptr) {
		ans_string = to_string(temp -> data) + ' ' + ans_string;
		temp = temp -> next;
	}
	cout << ans_string;

}