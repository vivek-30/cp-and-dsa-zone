#include <iostream>
using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next;

  ListNode(int val)
  {
    this->val = val;
  }
};

ListNode *appendNode(ListNode *list, int val)
{

  ListNode *newNode = new ListNode(val);

  if (!list)
    return newNode;

  ListNode *temp = list;

  while (list->next)
    list = list->next;
  list->next = newNode;
  return temp;
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{

  if (!l1 and !l2)
    return NULL;

  if (!l1)
    return l2;
  if (!l2)
    return l1;

  ListNode *result = NULL, *temp;

  while (l1 and l2)
  {
    if (l1->val <= l2->val)
    {
      result = appendNode(result, l1->val);
      temp = l1;
      l1 = l1->next;
    }
    else
    {
      result = appendNode(result, l2->val);
      temp = l2;
      l2 = l2->next;
    }

    delete temp;
  }

  while (l1)
  {
    result = appendNode(result, l1->val);
    l1 = l1->next;
  }
  while (l2)
  {
    result = appendNode(result, l2->val);
    l2 = l2->next;
  }

  return result;
}
