#include <iostream>
using namespace std;

class Node
{

public:
  int val;
  Node *next;
  Node *random;

  Node(int value)
  {
    val = value;
    next = random = NULL;
  }
};

Node *copyRandomList(Node *head)
{
  if (!head)
    return head;

  Node *temp = head, *newNode;

  while (temp)
  {
    newNode = new Node(temp->val);
    newNode->next = temp->next;
    temp->next = newNode;
    temp = newNode->next;
  }

  temp = head;
  newNode = temp->next;

  while (temp)
  {
    if (!temp->random)
      newNode->random = temp->random;
    else
      newNode->random = temp->random->next;

    temp = newNode->next;
    if (temp)
      newNode = temp->next;
  }

  temp = head;
  newNode = head->next;
  Node *newHead = newNode;

  while (temp)
  {
    temp->next = newNode->next;
    temp = temp->next;

    if (temp)
      newNode->next = temp->next;

    newNode = newNode->next;
  }

  return newHead;
}
