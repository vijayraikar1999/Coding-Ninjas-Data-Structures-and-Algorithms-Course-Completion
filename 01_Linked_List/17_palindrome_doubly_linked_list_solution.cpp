#include <cstddef>
#include <string>

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

bool palindromeDLL(Node* head){
    string ans_string1 = "";
	string ans_string2 = "";
	Node* temp = head;

	while (temp != NULL) {
		ans_string1 = ans_string1 + to_string(temp -> data);
		ans_string2 = to_string(temp -> data) + ans_string2;
		temp = temp -> next;
	}
	if (ans_string1 == ans_string2) {
		return true;
	}
	return false;
}