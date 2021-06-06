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

vector<int> rightSideView(TreeNode *root)
{

  vector<int> rv;

  if (!root)
    return rv;

  queue<TreeNode *> q;
  TreeNode *temp;
  int total = 0;
  q.push(root);

  while (!q.empty())
  {

    total = q.size();
    for (int i = 0; i < total; i++)
    {
      temp = q.front();
      q.pop();
      if (i == total - 1)
        rv.push_back(temp->val);
      if (temp->left)
        q.push(temp->left);
      if (temp->right)
        q.push(temp->right);
    }
  }

  return rv;
}
