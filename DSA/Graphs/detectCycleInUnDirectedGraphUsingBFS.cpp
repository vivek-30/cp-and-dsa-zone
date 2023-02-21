#include <bits/stdc++.h>
using namespace std;

bool findCycle(vector<int> adj[], int src, bool visited[])
{

  queue<int> q;
  q.push(src);

  int curr;

  while (!q.empty())
  {
    curr = q.front();
    q.pop();

    if (!visited[curr])
      visited[curr] = true;
    else
      return true;

    for (auto i : adj[curr])
      if (!visited[i])
        q.push(i);
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
    if (!visited[i] and findCycle(adj, i, visited))
      return true;
  }

  return false;
}
