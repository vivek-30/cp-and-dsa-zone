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

int sumOfLeftLeaves(TreeNode *root)
{

  if (not root)
    return 0;

  int ans = 0;
  if (root->left and not root->left->left and not root->left->right)
    ans = root->left->val;

  return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right) + ans;
}
