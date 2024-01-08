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

class Queue {
	Node* head;
	Node* tail;
	int size;
   public:
    Queue() {
		head = nullptr;
		tail = nullptr;
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

    void enqueue(int data) {
		Node* node = new Node(data);
		if (head == nullptr) {
			head = node;
			tail = node;
		} else {
			tail -> next = node;
			tail = node;
		}
		size++;
	}

    int dequeue() {
		if (head == nullptr) {
			return -1;
		}
        int ans = head -> data;
		Node* del = head;
		head = head -> next;
		delete del;
		size--;
		if (head == nullptr) {
			tail = nullptr;
		}
		return ans;
    }

    int front() {
        if (head == nullptr) {
			return -1;
		}
		return head -> data;
    }
};