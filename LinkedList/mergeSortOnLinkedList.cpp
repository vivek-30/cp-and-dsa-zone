#include<iostream>
using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node* insert(Node* head, int data) {
  Node* newNode = new Node(data);
  newNode->next = head;
  head = newNode;
  return head;
}

Node* merge(Node* left, Node* right) {

  if(not left and not right) return NULL;

  if(not left) return right;
  if(not right) return left;

  Node* res = new Node(0), *curr;
  curr = res;

  while(left and right) {
    if(left->data <= right->data) {
      curr->next = left;
      left = left->next;
    }
    else {
      curr->next = right;
      right = right->next;
    } 
    curr = curr->next;
  }

  while(left) {
    curr->next = left;
    left = left->next;
    curr = curr->next;
  }

  while(right) {
    curr->next = right;
    right = right->next;
    curr = curr->next;
  }

  curr->next = NULL;

  curr = res;
  res = res->next;
  delete curr;

  return res;
}
 
Node* mergeSort(Node* head) {
  
  if(!head or !head->next) return head;

  Node* slow, *fast, *mid;
  slow = fast = mid = head;

  while(fast and fast->next) {
    mid = slow;
    slow = slow->next;
    fast = fast->next->next;
  }

  mid->next = NULL; // Most Crucial Step i.e, break linked list into 2 parts

  Node* left = mergeSort(head);
  Node* right = mergeSort(slow);

  return merge(left, right);
}

void print(Node* head) {
  
  while(head) {
    cout<<head->data<<" ";
    head = head->next;
  }

  cout<<"\n";
}
 
int main() {
  
  int arr[] = {3,4,2,5,6,-1,3,4,-2,-2,56,6};
  int n = sizeof(arr)/sizeof(arr[0]);

  Node* head = NULL;

  for(int i=0; i<n; i++)
    head = insert(head, arr[i]);

  cout<<"Before Sorting\n";
  print(head);

  head = mergeSort(head);

  cout<<"After Sorting\n";
  print(head);
  
  return 0;
}
  