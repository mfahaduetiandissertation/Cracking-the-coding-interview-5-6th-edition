#include<iostream>
#include<map>
using namespace std;

class Node {

public:
	int data = NULL;
	Node* next = NULL;

};

void kth_to_last_iter(Node* n, int k) {//prints all nodes in a list
	Node* nn = new Node();
	Node* nn_1 = new Node();
	nn = n;
	nn_1 = n;
	for (int i = 0; i < k-1; i++) {
		if (nn_1 == NULL) {
			cout << "k is less than length of linked list" << endl;
		}
		else {
			nn_1 = n->next;
		}
	}
	while (nn_1->next != NULL) {
		nn = nn->next;
		nn_1 = nn_1->next;
	}
	cout << nn->data << endl;
}

int kth_to_last_recur(Node* n, int k) {//prints all nodes in a list
	if (n->next == NULL)
		return 0;
	
	int val = 0;
	val += (1 + kth_to_last_recur(n->next, k));
	if (val == k)
		cout << n->data << endl;
	return val;
}
void print_list(Node* n) {//prints all nodes in a list
	while (n != NULL) {
		cout << n->data << endl;
		n = n->next;
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
	second->data = 2;

	// Link second node with the third node 
	second->next = third;

	third->data = 3; // assign data to third node 
	third->next = NULL;
	kth_to_last_recur(head,4);
	//print_list(head);
}