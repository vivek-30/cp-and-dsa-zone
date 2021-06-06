#include <iostream>
using namespace std;

struct TreeNode
{

  int val;
  TreeNode *left, *right;
};

void flatten(TreeNode *root)
{

  if (!root or (!root->left and !root->right))
    return;

  if (root->left)
  {
    flatten(root->left);
    TreeNode *temp = root->right;
    root->right = root->left;
    root->left = NULL;
    while (root->right)
      root = root->right;
    root->right = temp;
  }

  flatten(root->right);
}
