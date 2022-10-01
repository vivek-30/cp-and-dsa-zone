#include <bits/stdc++.h>
using namespace std;


// Incorrect Code Right Now
struct ListNode
{
  int val;
  ListNode *next;

  ListNode(int _val, ListNode *_next = nullptr)
  {
    val = _val;
    next = _next;
  }
};

class Solution
{
public:
  static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    string num1 = "", num2 = "";
    char ch;

    while (l1 != nullptr)
    {
      ch = l1->val + '0';
      num1 = ch + num1;
      l1 = l1->next;
    }

    while (l2 != nullptr)
    {
      ch = l2->val + '0';
      num2 = ch + num2;
      l2 = l2->next;
    }

    int carry = 0, sum = 0;
    ListNode *res = nullptr, *temp = nullptr, *tail = nullptr;

    int mn = min(num1.size(), num2.size());
    int val1, val2, i = 0;
    while (mn--)
    {
      val1 = num1[i] - '0';
      val2 = num2[i] - '0';
      i++;
      sum = val1 + val2 + carry;
      carry = sum / 10;
      sum %= 10;
      temp = new ListNode(sum);
      if (res == nullptr)
        res = tail = temp;
      else
      {
        tail->next = temp;
        tail = temp;
      }
    }

    if (num1.size() < num2.size())
    {
      num1 = num2;
    }

    for (; i < num1.size(); i++)
    {
      val1 = num1[i] - '0';
      sum = val1 + carry;
      carry = sum / 10;
      sum %= 10;
      temp = new ListNode(sum);
      tail->next = temp;
      tail = temp;
    }

    if(carry) tail->next = new ListNode(carry);

    return res;
  }
};

void insert(ListNode **head, int val)
{

  ListNode *temp = new ListNode(val);

  if (*head == nullptr)
  {
    *head = temp;
    return;
  }

  temp->next = *head;
  *head = temp;
}

void print(ListNode *head)
{
  while(head != nullptr)
  {
    cout << head->val << " ";
    head = head -> next;
  }
  cout << "\n";
}

int main()
{

  ListNode *l1 = nullptr, *l2 = nullptr;
  string num1 = "942", num2 = "9465";
  
  for (char ch : num1)
  {
    insert(&l1, (ch - '0'));
  }

  for (char ch : num2)
  {
    insert(&l2, (ch - '0'));
  }

  ListNode *res = Solution::addTwoNumbers(l1, l2);
  print(res);

  return 0;
}
