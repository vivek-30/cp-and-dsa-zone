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

int replaceSum(TreeNode* root) {

  if(root == NULL)
    return 0;

  int leftValue = replaceSum(root->left);
  int rightValue = replaceSum(root->right);

  root->val = leftValue + rightValue + root->val;
  return root->val;
}
