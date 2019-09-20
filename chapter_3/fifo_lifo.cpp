#include<iostream>
using namespace std;

class Node {
public:
	Node* next;
	int data;
};

class Stack {
public:
	Node* head;
	Stack() {
		head = NULL;
		head->data = NULL;
	}
	Stack(Node* n) {
		head = n;
	}
	void push(Node* n) {
		n->next = head;
		head = n;
	}
	Node* pop(){
		Node* top;
		top = head;
		head = head->next;
		return top;
	}
	Node* peek() {
		return head;
	}

};

int main() {


	return 0;
}