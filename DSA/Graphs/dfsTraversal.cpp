#include <iostream>
#include <vector>
using namespace std;

void giveDfs(vector<int> adj[], int start, bool isVisited[], vector<int> &ans)
{
  isVisited[start] = true;

  vector<int>::iterator it;
  ans.push_back(start);

  for (it = adj[start].begin(); it != adj[start].end(); it++)
    if(!isVisited[*it])
      giveDfs(adj, *it, isVisited, ans);
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
  vector<int> ans;
  if (V == 0)
    return ans;

  bool isVisited[V];
  for (int i = 0; i < V; i++)
    isVisited[i] = false;

  for(int i=0; i<V; i++)
    if(!isVisited[i])
      giveDfs(adj, i, isVisited, ans);
  return ans;
}
