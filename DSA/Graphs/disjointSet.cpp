#include <bits/stdc++.h>
using namespace std;

class Graph
{

  unordered_map<int, int> m;

public:
  void makeSet(vector<int> &arr);
  int findSet(int e);
  void makeUnion(int a, int b);
  void printDisjointSet();
};

void Graph::makeSet(vector<int> &arr)
{
  for (int i: arr)
    m[i] = -1;
}

int Graph::findSet(int e)
{

  if (m[e] < 0)
  {
    return e;
  }

  int res = findSet(m[e]);
  m[e] = res;
  return res;
}

void Graph::makeUnion(int a, int b)
{
  int parentA = findSet(a);
  int parentB = findSet(b);

  if(parentA == parentB) 
    return;

  if (m[parentA] <= m[parentB])
  { // parentA has more -ve weight.
    m[parentA] += m[parentB];
    m[parentB] = parentA;
  }
  else
  {
    m[parentB] += m[parentA];
    m[parentA] = parentB;
  }
}

void Graph::printDisjointSet() {
  cout<<"Resultant Disjoint Set Is\n";
  for(auto i: m)
    cout<<i.first<<" "<<i.second<<endl;
}

int main()
{

  vector<int> v {1, 2, 3, 4, 5, 6, 7, 8};

  Graph G;
  G.makeSet(v);

  G.printDisjointSet();
  G.makeUnion(1, 2);
    G.printDisjointSet();

  G.makeUnion(3, 4);
  G.makeUnion(5, 6);
  G.makeUnion(7, 8);
    G.printDisjointSet();

  G.makeUnion(2, 4);
    G.printDisjointSet();

  G.makeUnion(2, 5);
    G.printDisjointSet();

  G.makeUnion(1, 3);
  G.makeUnion(6, 8);

  G.printDisjointSet();

  return 0;
}
