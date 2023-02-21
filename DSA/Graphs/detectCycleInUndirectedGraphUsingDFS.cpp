#include <iostream>
#include <vector>
using namespace std;

bool findCycle(vector<int> adj[], int start, int parent, bool visited[])
{

  visited[start] = true;

  for (auto it = adj[start].begin(); it != adj[start].end(); it++)
  {
    if (!visited[*it])
    {
      if (findCycle(adj, *it, start, visited))
        return true;
    }

    else if (visited[*it] and parent != *it)
      return true;
  }

  return false;
}

bool isCycle(int V, vector<int> adj[])
{
  if (V == 0)
    return false;

  bool visited[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  for (int i = 0; i < V; i++)
  {
    if (!visited[i] and findCycle(adj, i, -1, visited))
      return true;
  }

  return false;
}
