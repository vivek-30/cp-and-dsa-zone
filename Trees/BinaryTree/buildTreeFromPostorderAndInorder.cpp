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

int curr;

TreeNode *buildBinaryTree(vector<int> &inorder, vector<int> &postorder, int start, int end)
{

  if (start > end)
    return NULL;

  int val = postorder[curr--], i;
  TreeNode *newNode = new TreeNode(val);

  if (start == end or postorder.size() == 1)
    return newNode;

  for (i = end; i >= start; i--)
    if (inorder[i] == val)
      break;

  newNode->right = buildBinaryTree(inorder, postorder, i + 1, end);
  newNode->left = buildBinaryTree(inorder, postorder, start, i - 1);

  return newNode;
}

TreeNode *Tree::buildTree(vector<int> &inorder, vector<int> &postorder, int start, int end)
{
  if (inorder.size() == 0 or postorder.size() == 0)
    return NULL;

  curr = postorder.size() - 1;
  return buildBinaryTree(inorder, postorder, start, end);
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
  vector<int> postorder{9, 15, 7, 20, 3};
  vector<int> inorder{9, 3, 15, 20, 7};

  obj->setRoot(obj->buildTree(inorder, postorder, 0, postorder.size() - 1));
  obj->printTree(obj->getRoot());
  cout << endl;

  return 0;
}
