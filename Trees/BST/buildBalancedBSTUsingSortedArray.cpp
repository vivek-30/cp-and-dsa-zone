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

TreeNode *sortedArrayToBST(vector<int> &nums)
{
  if (nums.size() == 0)
    return NULL;
  return create(nums, 0, nums.size() - 1);
}

TreeNode *create(vector<int> &nums, int start, int end)
{
  if (start > end)
    return NULL;

  int mid = (start + end) / 2;
  TreeNode *root = new TreeNode(nums[mid]);
  root->left = create(nums, start, mid - 1);
  root->right = create(nums, mid + 1, end);

  return root;
}
