#include <iostream>
#include <vector>
using namespace std;

// Approach - Check whether the node we are currenty on is already present in recursion stack or not using auxiliary space (track array), if yes then cycle exists else cycle does not exists.
bool foundCycle(vector<int> adj[], int start, bool isVisited[], bool track[])
{

  isVisited[start] = true;
  track[start] = true;

  for (auto it = adj[start].begin(); it != adj[start].end(); it++)
  {
    if (!isVisited[*it] and foundCycle(adj, *it, isVisited, track))
      return true;
    else if (track[*it])
      return true;
  }

  track[start] = false;
  return false;
}

bool isCyclic(int V, vector<int> adj[])
{

  bool isVisited[V];
  bool track[V];

  for (int i = 0; i < V; i++)
    isVisited[i] = track[i] = false;

  for (int i = 0; i < V; i++)
    if (foundCycle(adj, i, isVisited, track))
      return true;

  return false;
}
