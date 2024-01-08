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

class Stack {
	Node* head;
    Node* top_pointer;
    int size;
   public:
    Stack() {
        head = nullptr;
        top_pointer = nullptr;
        size = 0;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return size;
    }

    bool isEmpty() {
        if (head == nullptr) {
            return true;
        }
        return false;
    }

    void push(int element) {
        Node* node = new Node(element);

        if (head == nullptr) {
            top_pointer = node;
            head = node;
        } else {
            top_pointer -> next = node;
            top_pointer = node;
        }
        size++;
    }

    int pop() {
        if (head == nullptr) {
            return -1;
        }
        int ans;
        if (head -> next == nullptr) {
            ans = head -> data;
            Node* del = head;
            head = nullptr;
            size--;
            delete del;
            return ans;
        }
        Node* temp = head;
        while (true) {
            if (temp -> next -> next == nullptr) {
                break;
            }
            temp = temp -> next;
        }
        ans = temp -> next -> data;
        Node* del = temp -> next;
        delete del;
        temp -> next = nullptr;
        top_pointer = temp;
        size--;
        return ans;
    }

    int top() {
        if (head == nullptr) {
            return -1;
        }
        return top_pointer -> data;
    }
};