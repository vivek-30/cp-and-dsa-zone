#include<iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int data)
  {
    this->data = data;
    next = NULL;
  }
};

void putEvenNodesAfterOdd(Node *head)
{
  if (!head or !head->next)
    return;

  Node *odd = head, *even = head->next, *evenPtr = head->next;

  while (odd->next and even->next)
  {
    odd->next = even->next;
    odd = odd->next;
    even->next = odd->next;
    even = even->next;
  }

  odd->next = evenPtr;

  if (!odd->next)
    even->next = NULL;
}
