#include <bits/stdc++.h>
using namespace std;

// Kahn Algorithm
vector<int> topoOrder;

bool findCycle(vector<int> adj[], int v, int src, int indegree[])
{

  queue<int> q;

  int count = 0, curr;
  for (int i = 0; i < v; i++)
  {
    if (indegree[i] == 0)
      q.push(i);
  }

  while (!q.empty())
  {
    curr = q.front();
    q.pop();

    topoOrder.push_back(curr);

    for (auto i : adj[curr])
    {
      indegree[i]--;
      if (indegree[i] == 0)
        q.push(i);
    }

    count++;
  }

  if (count != v)
    return true;

  return false;
}

bool isCyclic(int V, vector<int> adj[])
{
  if (V == 0)
    return false;

  int indegree[V];
  for (int i = 0; i < V; i++)
    indegree[i] = 0;

  for (int i = 0; i < V; i++)
    for (auto j : adj[i])
      indegree[j]++;

  return findCycle(adj, V, 0, indegree);
}
