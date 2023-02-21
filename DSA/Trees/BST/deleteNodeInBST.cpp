#include <iostream>
using namespace std;

class TreeNode
{

public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int _val)
  {
    val = _val;
    left = right = NULL;
  }
};

int findMaxInLeft(TreeNode *root)
{
  if (root == NULL)
    return INT_MIN;

  if (!root->right)
    return root->val;
  return findMaxInLeft(root->right);
}

TreeNode *deleteNode(TreeNode *root, int key)
{
  if (root == NULL)
    return root;

  if (root->val > key)
    root->left = deleteNode(root->left, key);
  else if (root->val < key)
    root->right = deleteNode(root->right, key);
  else
  {

    // case 1: when node to be deleted is leaf node.
    if (!root->left and !root->right)
    {
      delete root;
      root = NULL;
    }
    // case 2: when node to be deleted has both child.
    else if (root->left and root->right)
    {
      int maxNode = findMaxInLeft(root->left);
      root->val = maxNode;
      root->left = deleteNode(root->left, maxNode);
    }
    // case 3: when node to be deleted has only one child.
    else
    {
      TreeNode *temp = root->left ? root->left : root->right;
      delete root;
      root = temp;
    }
  }
  return root;
}
