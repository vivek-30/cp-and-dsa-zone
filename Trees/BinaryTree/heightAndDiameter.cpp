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

// To find height of a tree.

int findHeight(TreeNode *root)
{
  if (root == NULL)
    return 0;

  return max(findHeight(root->left), findHeight(root->right)) + 1;
}

// O(N * N)
int diameterOfBinaryTree(TreeNode *root)
{
  if (root == NULL)
    return 0;

  int leftHeight = findHeight(root->left);
  int rightHeight = findHeight(root->right);
  int currentDiameter = leftHeight + rightHeight; // Note if we count no. of nodes in our diameter then add 1 to this statment indicating rootNode includence else leave it as it is which means that we are only considering no. of edges as diameter.

  int leftDiameter = diameterOfBinaryTree(root->left);
  int rightDiameter = diameterOfBinaryTree(root->right);
  return max(max(leftDiameter, rightDiameter), currentDiameter);
}

// O(N)
int diameterOfBinaryTree(TreeNode *root)
{
  int h = 0;
  return findDiameter(root, h);
}

int findDiameter(TreeNode *root, int &height)
{
  if (root == NULL)
    return height = 0;

  int lh = 0, rh = 0;

  int ld = findDiameter(root->left, lh);
  int rd = findDiameter(root->right, rh);

  height = max(lh, rh) + 1;
  int currentDiameter = lh + rh;

  return max(currentDiameter, max(ld, rd));
}
