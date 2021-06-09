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

// Method 1: using inorder traversal.
void getInorder(TreeNode *root, vector<int> &v)
{
  if (root == nullptr)
    return;

  getInorder(root->left, v);
  v.push_back(root->val);
  getInorder(root->right, v);
}

bool isValidBST(TreeNode *root)
{

  if (root == nullptr or (not root->left and not root->right))
    return true;

  vector<int> v;
  getInorder(root, v);
  for (int i = 1; i < v.size(); i++)
  {
    if (v[i] <= v[i - 1])
      return false;
  }

  return true;
}

// Space optimized Method 1 - O(1) space.
TreeNode *previous = NULL;
bool isValidBST(TreeNode *root)
{
  if (root == nullptr)
    return true;

  bool curr = true;
  bool left = isValidBST(root->left);
  if (previous and previous->val >= root->val)
    curr = false;
  previous = root;
  bool right = isValidBST(root->right);

  if (curr and left and right)
    return true;

  return false;
}

// Method 2: by comparing max from left and min from right with present node (for every node).
bool isValidBST(TreeNode *root)
{

  if (root == nullptr)
    return true;

  if (not isValidBST(root->left) or not isValidBST(root->right))
    return false;

  if (root->left and maxInLeft(root->left) >= root->val)
    return false;

  if (root->right and minInRight(root->right) <= root->val)
    return false;

  return true;
}

int maxInLeft(TreeNode *root)
{
  if (root == nullptr)
    return INT_MAX;

  if (root->right == nullptr)
    return root->val;

  return maxInLeft(root->right);
}

int minInRight(TreeNode *root)
{
  if (root == nullptr)
    return INT_MIN;

  if (root->left == nullptr)
    return root->val;

  return minInRight(root->left);
}

// Method 3: By using Permissible range. (most efficient).
bool isValidBST(TreeNode *root)
{
  return checkbst(root, -1e10, 1e10);
}

bool checkbst(TreeNode *root, long long minRange, long long maxRange)
{
  if (root == nullptr)
    return true;

  if ((root->val > minRange and root->val < maxRange) and checkbst(root->left, minRange, root->val) and checkbst(root->right, root->val, maxRange))
    return true;

  return false;
}
