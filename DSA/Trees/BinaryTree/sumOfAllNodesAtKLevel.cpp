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

int maxLevelSum(TreeNode *root)
{
  if (root == NULL)
    return 0;

  long long int ans = INT_MIN, curr = 0;
  int level = 0, result = 1;

  queue<TreeNode *> q;
  q.push(root);
  q.push(NULL);

  TreeNode *temp;

  while (!q.empty())
  {
    temp = q.front();

    while (temp != NULL)
    {
      q.pop();
      curr += temp->val;
      if (temp->left)
        q.push(temp->left);
      if (temp->right)
        q.push(temp->right);
      temp = q.front();
    }

    q.pop();
    level++;
    if (curr > ans)
    {
      ans = curr;
      result = level;
    }
    curr = 0;
    if (!q.empty()) // Most Important Condition
      q.push(NULL);
  }

  return result;
}

int main()
{

  Tree *obj = new Tree();
  vector<int> postorder{1, 4, 7, 6, 3, 13, 14, 10, 8};
  vector<int> inorder{1, 3, 4, 6, 7, 8, 10, 13, 14};

  obj->setRoot(obj->buildTree(inorder, postorder, 0, postorder.size() - 1));
  cout << "Level " << maxLevelSum(obj->getRoot()) << endl;

  return 0;
}
