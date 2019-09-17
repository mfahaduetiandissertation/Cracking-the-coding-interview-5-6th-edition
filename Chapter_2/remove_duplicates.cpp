#include<iostream>
#include<map>
using namespace std;

class Node {

public:
	int data = NULL;
	Node* next = NULL;

};

void print_list(Node* n) {//prints all nodes in a list
	while (n != NULL) {
		cout << n->data << endl;
		n = n->next;
	}
}

void remove_dupl(Node* n) {//prints all nodes in a list
	map<int, int> dat;
	map<int, int>::iterator it;
	if (n == NULL || n->next == NULL) {
		return;
	}
	dat[n->data] = 1;
	while (n != NULL) {
		it = dat.find(n->data);
		if (it == dat.end()) {
			dat[n->data]=1;
		}
		else {
			n->next = n->next->next;
		}
		n = n->next;
	}
}
void remove_dupl_no_data(Node* n) {//prints all nodes in a list
	if (n == NULL || n->next == NULL) {
		return;
	}
	Node* next = new Node();
	Node* current = new Node();
	Node* prev_next = new Node();
	current = n;
	next = n->next;
	prev_next = n;
	while (current != NULL) {
		while (next != NULL) {
			if (current->data == next->data) {
				prev_next->next = next->next;
				next = prev_next->next->next;
			}
			else {
				prev_next = next;
				next = next->next;
			}
		}
		current = current->next;
	}
}
int main() {

	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();

	head->data = 1; // assign data in first node 
	head->next = second; // Link first node with 
	// the second node 

// assign data to second node 
	second->data = 1;

	// Link second node with the third node 
	second->next = third;

	third->data = 3; // assign data to third node 
	third->next = NULL;
	remove_dupl_no_data(head);
	print_list(head);
}