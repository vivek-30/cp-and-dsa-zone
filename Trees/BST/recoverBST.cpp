#include <iostream>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left, *right;
  TreeNode(int data)
  {
    val = data;
    left = right = NULL;
  }
};

TreeNode *previous, *adjacentPos, *endPos, *startPos;

void swap(int &first, int &second)
{

  int temp = first;
  first = second;
  second = temp;
}

void recoverBstUtil(TreeNode *root)
{

  if (root == nullptr)
    return;

  recoverBstUtil(root->left);

  if (previous and previous->val > root->val)
  {

    if (startPos)
    {
      endPos = root;
    }
    else
    {
      startPos = previous;
      adjacentPos = root;
    }
  }
  previous = root;
  recoverBstUtil(root->right);
}

void recoverBst(TreeNode *root)
{
  previous = adjacentPos = endPos = startPos = NULL;
  recoverBstUtil(root);
  if (endPos)
    swap(startPos->val, endPos->val);
  else
    swap(startPos->val, adjacentPos->val);
  return;
}

void inorder(TreeNode *root)
{
  if (root == nullptr)
    return;

  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
}

int main()
{

  TreeNode *root = NULL;

  root = new TreeNode(1);
  root->left = new TreeNode(3);
  root->right = new TreeNode(4);

  cout << "Before change\n";
  inorder(root);

  recoverBst(root);
  cout << "After change\n";
  inorder(root);

  delete root->left;
  delete root->right;
  delete root;
  root = nullptr;

  return 0;
}
