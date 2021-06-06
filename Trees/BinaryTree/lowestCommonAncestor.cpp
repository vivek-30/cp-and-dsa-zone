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

// O(N) + O(N) space less efficient.
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{

  if (root == NULL)
    return root;

  vector<TreeNode *> p1;
  vector<TreeNode *> p2;

  TreeNode *result = nullptr;

  findPath(root, p, p1);
  findPath(root, q, p2);

  int size = min(p1.size(), p2.size());

  for (int i = 0; i < size; i++)
  {
    if (p1[i] == p2[i])
      result = p1[i];
    else
      break;
  }

  return result;
}

bool findPath(TreeNode *root, TreeNode *target, vector<TreeNode *> &path)
{

  if (root == NULL)
    return false;

  path.push_back(root);
  if (root == target)
    return true;

  if (findPath(root->left, target, path) or findPath(root->right, target, path))
    return true;

  path.pop_back();
  return false;
}

// O(N) but more efficient.
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{

  if (!root or root == p or root == q)
    return root;

  TreeNode *left = lowestCommonAncestor(root->left, p, q);
  TreeNode *right = lowestCommonAncestor(root->right, p, q);

  if (left and right)
    return root;
  else
    return left ? left : right;
}
