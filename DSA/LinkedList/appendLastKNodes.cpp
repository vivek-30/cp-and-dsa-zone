#include <iostream>
using namespace std;

class node {
	public:
		int data;
		node *next;

    node(int data) {
      this -> data = data;
      this -> next = NULL;
    }
};

void insertAtHead(node **head, int data) {
	node *newNode = new node(data);
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

bool appendLastKNodes(node **head, int k) {
  if(!(*head) or k <= 0)
    return false;

  node *temp = *head;
  int len = 0, diff;
  while(temp) {
    ++len;
    temp = temp->next;
  }

  if(k > len)
    return false;

  diff = len - k;
  temp = *head;
  while(temp and --diff)
    temp = temp->next;

  if(temp) {
    node* newHead = temp->next;
    node* temp2  = newHead;
    temp->next = NULL;
    while(newHead and newHead->next)
      newHead = newHead->next;
    
    newHead->next = *head;
    *head = temp2;
  }

  return true;
}

int main() {

	node *head = NULL;
	int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < n; i++)
		insertAtHead(&head, arr[i]);

	cout<<"Orignal Linked List: ";
	print(head);
  if(appendLastKNodes(&head, 3)) {
	  cout<<"Modified Linked List: ";
	  print(head);
  }
  else cout<<"Given value is not feasible\n";

	return 0;
}
