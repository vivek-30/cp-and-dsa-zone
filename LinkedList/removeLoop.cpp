#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
};

void removeLoopFromLL(Node *head, Node *fast) {

  Node* prev;

  while (head != fast) {
    prev = fast;
    fast = fast->next;
    head = head->next;
  }

  prev->next = NULL;
}

void removeLoop(Node *head) {
  if (!head)
    return;

  if (head->next == head) {
    head->next = NULL;
    return;
  }

  Node *slow = head, *fast = head;
  while (fast and fast->next) {
    fast = fast->next->next;
    slow = slow->next;
    if (slow == fast) {
      removeLoopFromLL(head, fast);
      return;
    }
  }
}

int main() {

  Node *head = NULL;

  return 0;
}
