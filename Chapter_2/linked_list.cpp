#include<iostream>

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

void print_pos(Node* n, int num) {//prints node at a specific index
	int count = 0;

	while (n != NULL) {
		if (count == num) {
			cout << n->data << endl;
			return;
		}
		count++;
		n = n->next;
	}

	cout << "position is geater than length of list" << endl;
}

void push(Node** n, int data) {//add node to the head
	Node* nn = new Node();//generate a new node
	nn->data = data;//add the data node
	nn->next = (*n);//point next of new node as current head
	(*n) = nn;//make new node as the head
}

void append(Node** n, int data) {//add node to the end
	Node* nn = new Node();//generate a new node
	nn->data = data;//add the data
	nn->next = NULL;
	Node* next = new Node();
	next = (*n);
	if (next==NULL) {
		(*n) = nn;
		return;
	}
	while (next->next != NULL) {
		next = next->next;
	}
	next->next = nn;
	return;
}

void delnode(Node** n, int data) {//add node to the end

	if ((*n) == NULL) {
		return;
	}
	if ((*n)->data == data) {
		*n = (*n)->next;
		return;
	}
	Node* nn = new Node();
	nn = (*n);
	while (nn->next != NULL) {
		if (nn->next->data == data) {
			nn->next = nn->next->next;
		}
		nn = nn->next;
	}

}

void insertAfter(struct Node* prev_node, int new_data)// insert node affter a node
{
	/*1. check if the given prev_node is NULL */
	if (prev_node == NULL)
	{
		printf("the given previous node cannot be NULL");
		return;
	}

	/* 2. allocate new node */
	struct Node* new_node = new Node();

	/* 3. put in the data  */
	new_node->data = new_data;

	/* 4. Make next of new node as next of prev_node */
	new_node->next = prev_node->next;

	/* 5. move the next of prev_node as new_node */
	prev_node->next = new_node;
}
void deleteList(Node** head_ref)
{

	/* deref head_ref to get the real head */
	Node* current = *head_ref;
	Node* next;

	while (current != NULL)
	{
		next = current->next;
		delete(current);
		current = next;
	}

	/* deref head_ref to affect the real head back
		in the caller. */
	*head_ref = NULL;
}
int main() {

	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;

	// allocate 3 nodes in the heap 
	head = new Node();
	second = new Node();
	third = new Node();


	head->data = 1; // assign data in first node 
	head->next = second; // Link first node with 
	// the second node 

// assign data to second node 
	second->data = 2;

	// Link second node with the third node 
	second->next = third;


	third->data = 3; // assign data to third node 
	third->next = NULL;
	push(&head,3);
	append(&head, 55);
	print_list(head);
	delnode(&head, 2);
	print_list(head);
	deleteList(&head);
	cout << "Printing Deleted List" << endl;
	print_list(head);
	return 0;
}