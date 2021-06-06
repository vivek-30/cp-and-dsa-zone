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

vector<int> leftView(TreeNode *root)
{
  vector<int> lv;

  if (!root)
    return lv;

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
      if (i == 0)
        lv.push_back(temp->val);
      if (temp->left)
        q.push(temp->left);
      if (temp->right)
        q.push(temp->right);
    }
  }

  return lv;
}
