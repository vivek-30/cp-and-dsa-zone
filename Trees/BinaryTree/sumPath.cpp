#include <bits/stdc++.h>
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

// Count total number of nodes in a binary tree.
int countNodes(TreeNode *root)
{
  if (root == NULL)
    return 0;

  return countNodes(root->left) + countNodes(root->right) + 1;
}

// Count sum of all nodes in a binary tree.
int countSumOfAllNodes(TreeNode *root)
{
  if (root == NULL)
    return 0;

  return countNodes(root->left) + countNodes(root->right) + root->val;
}

// Check Whether there is path from root to leaf whose sum of all nodes in that path is equals to target value.
bool hasPathSum(TreeNode *root, int targetSum)
{

  if (root == NULL)
    return false;

  targetSum -= root->val;

  if (targetSum == 0 and root->left == NULL and root->right == NULL)
    return true;

  return hasPathSum(root->left, targetSum) or hasPathSum(root->right, targetSum);
}
