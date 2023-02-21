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

int height(TreeNode *root)
{
  if (root == NULL)
    return 0;

  return max(height(root->left), height(root->right)) + 1;
}

// O(N * N)
bool isBalanced(TreeNode *root)
{

  if (!root)
    return true;

  int diff = height(root->left) - height(root->right);

  return isBalanced(root->left) and isBalanced(root->right) and abs(diff) <= 1;
}

// O(N)
bool checkHeightBalanced(TreeNode *root, int &height)
{
  if (!root)
  {
    height = 0;
    return true;
  }

  int lh = 0, rh = 0;
  bool lres = checkHeightBalanced(root->left, lh);
  bool rres = checkHeightBalanced(root->right, rh);
  height = max(lh, rh) + 1;

  return lres and rres and abs(lh - rh) <= 1;
}

bool isBalanced(TreeNode *root)
{
  int height = 0;
  return checkHeightBalanced(root, height);
}
