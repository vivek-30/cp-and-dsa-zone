#include <iostream>
#include <vector>
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

TreeNode *bstFromPreorder(vector<int> &preorder)
{
  if (preorder.size() == 0)
    return NULL;
  TreeNode *root = NULL;

  for (auto element : preorder)
    root = insertNode(root, element);

  return root;
}

TreeNode *insertNode(TreeNode *root, int element)
{
  if (root == NULL)
  {
    return new TreeNode(element);
  }

  if (root->val > element)
    root->left = insertNode(root->left, element);
  else
    root->right = insertNode(root->right, element);

  return root;
}
