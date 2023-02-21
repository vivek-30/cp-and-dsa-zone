#include<iostream>
using namespace std;

class ListNode {
  public:
    int data;
    ListNode *next;
};

ListNode* findIntersection(ListNode *headA, ListNode *headB) {
  if (!headA or !headB)
    return NULL;

  int len1 = 0, len2 = 0, diff;
  ListNode *temp1 = headA, *temp2 = headB;

  while (temp1) {
    ++len1;
    temp1 = temp1->next;
  }

  while (temp2) {
    ++len2;
    temp2 = temp2->next;
  }

  temp1 = headA;
  temp2 = headB;

  if (len1 > len2) {
    diff = len1 - len2;
    while (temp1 and diff--)
      temp1 = temp1->next;
  }
  else if (len2 > len1) {
    diff = len2 - len1;
    while (temp2 and diff--)
      temp2 = temp2->next;
  }

  while (temp1 and temp2) {
    if (temp1 == temp2)
      return temp1;
    temp1 = temp1->next;
    temp2 = temp2->next;
  }
  return NULL; // No Intersection Point Exists.
}
