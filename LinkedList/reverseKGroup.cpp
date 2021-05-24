#include <iostream>
using namespace std;

class node {
	public:
		int data;
		node *next;
};

node *get(int data) {
	node *ptr = new node();
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}

void insertAtHead(node **head, int data) {
	node *newNode = get(data);
	newNode->next = *head;
	*head = newNode;
}

void print(node *head) {
	while (head) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}

bool isKLengthLeft(node* head, int k) {
	while(head and --k)
		head = head->next;
	return k == 0 ? true : false;
}

node* reverseKGroup(node *head, int k) {

	if(!head or k <= 1)
		return head;

	if(!isKLengthLeft(head, k))
		return head;

	int i = 1;
	node *curr = head, *prev = NULL, *fwd = head;
	while (curr and i <= k) {
		fwd = curr->next;
		curr->next = prev;
		prev = curr;
		curr = fwd;
		i++;
	}

	if (fwd)
		head->next = reverseKGroup(fwd, k);
	return prev;
}

int main() {

	node *head = NULL;
	int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < n; i++)
		insertAtHead(&head, arr[i]);

	cout<<"Orignal Linked List: ";
	print(head);
	node *modified = reverseKGroup(head, 5);
	cout<<"Modified Linked List: ";
	print(modified);

	return 0;
}
