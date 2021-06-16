#include <bits/stdc++.h>
using namespace std;

class ListNode
{

public:
  int val;
  ListNode *next;

  ListNode(int x)
  {
    val = x;
    next = NULL;
  }
};

// Approach 1: Time - O(N * logK) total Nodes N and logK for k linked list (logn for push and pop in heap),  Space - O(N + K) N for new linked list k for heap.
priority_queue<int, vector<int>, greater<int>> pq;

void createList(ListNode **head, ListNode **tail)
{

  ListNode *newNode = nullptr;
  while (not pq.empty())
  {
    newNode = new ListNode(pq.top());
    pq.pop();

    if (*head == nullptr)
      *head = *tail = newNode;
    else
    {
      (*tail)->next = newNode;
      *tail = newNode;
    }
  }
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{

  int n = lists.size();
  if (n == 0)
    return nullptr;
  if (n == 1)
    return lists[0];

  ListNode *temp = nullptr, *head = nullptr, *tail = nullptr;
  int i;
  bool isSomething = true;

  while (isSomething)
  {
    i = 0;
    isSomething = false;
    while (i < n)
    {
      temp = lists[i];
      if (temp)
      {
        if (temp->next)
          isSomething = true;
        pq.push(temp->val);
        lists[i] = temp->next;
      }
      i++;
    }
    if (not pq.empty()) // Add top element(smallest value) of each iteration in linked list.
    {
      ListNode *newNode = new ListNode(pq.top());
      pq.pop();

      if (head == nullptr)
        head = tail = newNode;
      else
      {
        tail->next = newNode;
        tail = newNode;
      }
    }
  }

  createList(&head, &tail); // Add all the remaining values;
  return head;
}

// Approach 2: (Divide and Conquer) Time - O(N * logK) k - total linked list, N - (for merging 2 sorted lists), Space - O(1)

ListNode *mergeKLists(vector<ListNode *> &lists)
{

  int n = lists.size();
  if (n == 0)
    return nullptr;
  if (n == 1)
    return lists[0];

  return mergeLists(lists, 0, n - 1);
}

ListNode *mergeLists(vector<ListNode *> &lists, int start, int end)
{

  if (start > end)
    return NULL;

  if (start == end)
    return lists[start];

  int mid = start + (end - start) / 2;

  ListNode *left = mergeLists(lists, start, mid); // Very Very Important order it should be start to mid and then mid + 1 to right.
  ListNode *right = mergeLists(lists, mid + 1, end);

  return merge(left, right);
}

ListNode *merge(ListNode *l1, ListNode *l2)
{

  if (!l1 and !l2)
    return NULL;

  if (!l1)
    return l2;
  if (!l2)
    return l1;

  ListNode *result = new ListNode(0);
  ListNode *temp = result;

  while (l1 and l2)
  {
    if (l1->val <= l2->val)
    {
      result->next = l1;
      l1 = l1->next;
    }
    else
    {
      result->next = l2;
      l2 = l2->next;
    }
    result = result->next;
  }

  while (l1)
  {
    result->next = l1;
    l1 = l1->next;
    result = result->next;
  }
  while (l2)
  {
    result->next = l2;
    l2 = l2->next;
    result = result->next;
  }

  result->next = NULL;
  result = temp->next;
  delete temp;

  return result;
}

// Approach 3: Merge one by one i.e, merge first 2 lists after that merge resultant with 3rd list and so on ... Time - O(N * K) (2 lists takes O(N) time for merging and we have to repeat this process for k - 1 times)

// Approach 4: Build a linked list containing all values and then sort it (Merge Sort). Time - O(N * LogN).
