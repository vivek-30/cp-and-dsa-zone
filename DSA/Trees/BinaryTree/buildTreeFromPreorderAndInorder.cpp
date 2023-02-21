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

class Tree
{

  TreeNode *root;

public:
  Tree()
  {
    root = NULL;
  }

  void setRoot(TreeNode *);
  TreeNode *getRoot();
  TreeNode *buildTree(vector<int> &, vector<int> &, int, int);
  void printTree(TreeNode *);
};

void Tree::setRoot(TreeNode *address)
{
  root = address;
}

TreeNode *Tree::getRoot()
{
  return root;
}

// Global variable current
int curr = 0;

TreeNode *Tree::buildTree(vector<int> &preorder, vector<int> &inorder, int start, int end)
{

  if (preorder.size() == 0 or inorder.size() == 0 or start > end)
    return NULL;

  int val = preorder[curr++], i;
  TreeNode *newNode = new TreeNode(val);

  if (start == end)
    return newNode;

  for (i = start; i <= end; i++)
    if (inorder[i] == val)
      break;

  newNode->left = buildTree(preorder, inorder, start, i - 1);
  newNode->right = buildTree(preorder, inorder, i + 1, end);

  return newNode;
}

void Tree::printTree(TreeNode *root)
{

  if (root == NULL)
    return;

  printTree(root->left);
  cout << root->val << " ";
  printTree(root->right);
}

int main()
{

  Tree *obj = new Tree();
  vector<int> preorder{1, 2, 4, 3, 5};
  vector<int> inorder{4, 2, 1, 5, 3};

  obj->setRoot(obj->buildTree(preorder, inorder, 0, inorder.size() - 1));
  obj->printTree(obj->getRoot());
  cout << endl;

  return 0;
}
