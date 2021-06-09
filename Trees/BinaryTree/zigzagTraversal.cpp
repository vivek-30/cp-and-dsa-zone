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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
  vector<vector<int>> ans;
  vector<int> v;
  if (root == nullptr)
    return ans;

  stack<TreeNode *> s1, s2;

  TreeNode *curr = nullptr;
  int size = 0;
  bool direction = true; // true mean left to right false means right to left;

  s2.push(root);
  while (not s1.empty() or not s2.empty())
  {
    size = s1.size() != 0 ? s1.size() : s2.size();
    for (int i = 0; i < size; i++)
    {

      if (direction)
      {
        curr = s2.top();
        s2.pop();
        if (curr->left)
          s1.push(curr->left);
        if (curr->right)
          s1.push(curr->right);
      }
      else
      {
        curr = s1.top();
        s1.pop();
        if (curr->right)
          s2.push(curr->right);
        if (curr->left)
          s2.push(curr->left);
      }

      v.push_back(curr->val);
    }
    ans.push_back(v);
    v.clear();
    direction = direction ? false : true;
  }

  return ans;
}
