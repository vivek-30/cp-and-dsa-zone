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

int maxSum = INT_MIN;

int maxPathSum(TreeNode *root)
{

  if (root == nullptr)
    return 0;

  findMaxSum(root);

  return maxSum;
}

int findMaxSum(TreeNode *root)
{
  if (root == nullptr)
    return 0;

  int left = findMaxSum(root->left);
  int right = findMaxSum(root->right);

  int total = left + right + root->val;

  int current = max(root->val, max(left + root->val, right + root->val));
  maxSum = max(maxSum, max(total, current));
  return current;
}
