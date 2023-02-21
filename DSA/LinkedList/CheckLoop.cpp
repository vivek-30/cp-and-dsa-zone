#include <iostream>
#include <set>
using namespace std;

class node {
  public:
    int data;
    node *next;
};

bool hasCycle(node *head) {
  if (!head)
    return false;

  set<node *> s;
  while (head) {
    // auto res = s.insert(head);
    if (s.insert(head).second == false) // Failed to add duplicate value / address.
      return true;
    head = head->next;
  }
  return false;
}

bool findLoop(node *head) {
  if (!head)
    return false;

  node *slow = head, *fast = head;
  
  while(fast and fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      return true;
  }

  return false;
}

int main() {

  node *head = NULL;
  int n;
  cout << "Enter a number" << endl;
  cin >> n;

  if (findLoop(head))
    cout << "Loop Exists.\n";
  else
    cout << "Loop Does Not Exists.\n";

  return 0;
}
