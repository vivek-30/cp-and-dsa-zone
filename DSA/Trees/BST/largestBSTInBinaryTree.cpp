#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *left, *right;

  Node(int data)
  {
    this->data = data;
    left = right = NULL;
  }
};

class Info
{
public:
  int min, max, size, ans;
  bool isBST;

  Info()
  {
    min = INT_MAX;
    max = INT_MIN;
    size = ans = 0;
    isBST = true;
  }

  Info(int min, int max, int size, int ans, bool isBST)
  {
    this->min = min;
    this->max = max;
    this->size = size;
    this->ans = ans;
    this->isBST = isBST;
  }
};

Info largestBstUtil(Node *root)
{

  if (root == nullptr)
  {
    Info res(INT_MAX, INT_MIN, 0, 0, true);
    return res;
  }

  if (root->left == nullptr and root->right == nullptr)
  { // Leaf Node.
    Info res(root->data, root->data, 1, 1, true);
    return res;
  }

  Info leftInfo = largestBstUtil(root->left);
  Info rightInfo = largestBstUtil(root->right);

  Info curr;
  curr.size = 1 + leftInfo.size + rightInfo.size;
  if (leftInfo.isBST and rightInfo.isBST and leftInfo.max < root->data and rightInfo.min > root->data)
  {
    curr.min = min(root->data, min(leftInfo.min, rightInfo.min));
    curr.max = max(root->data, max(leftInfo.max, rightInfo.max));
    curr.isBST = true;
    curr.ans = curr.size;
  }
  else
  {
    curr.isBST = false;
    curr.ans = max(leftInfo.ans, rightInfo.ans);
  }

  return curr;
}

int largestBst(Node *root)
{
  Info res = largestBstUtil(root);
  return res.ans;
}
