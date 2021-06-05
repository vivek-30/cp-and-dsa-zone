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

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{

  vector<int> ans;
  vector<TreeNode *> path;

  if (root == nullptr)
    return ans;
  TreeNode *visitedNode;

  getNodesPath(root, target, path);
  for (int i = 0; i < path.size(); i++)
  {
    visitedNode = i == 0 ? NULL : path[i - 1];
    findNodes(path[i], k - i, visitedNode, ans);
  }

  return ans;
}

bool getNodesPath(TreeNode *root, TreeNode *target, vector<TreeNode *> &path)
{
  if (root == nullptr)
    return false;

  if (root == target)
  {
    path.push_back(root);
    return true;
  }

  if (getNodesPath(root->left, target, path))
  {
    path.push_back(root);
    return true;
  }

  if (getNodesPath(root->right, target, path))
  {
    path.push_back(root);
    return true;
  }

  return false;
}

void findNodes(TreeNode *root, int k, TreeNode *visitedNode, vector<int> &ans)
{

  if (k < 0 or root == nullptr or root == visitedNode)
    return;

  if (k == 0)
  {
    ans.push_back(root->val);
    return;
  }

  findNodes(root->left, k - 1, visitedNode, ans);
  findNodes(root->right, k - 1, visitedNode, ans);
}
