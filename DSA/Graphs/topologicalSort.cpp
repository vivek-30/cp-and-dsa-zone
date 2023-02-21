#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int start, bool visited[], vector<int> &ans)
{
  visited[start] = true;

  for (auto it = adj[start].begin(); it != adj[start].end(); it++)
  {
    if (!visited[*it])
      dfs(adj, *it, visited, ans);
  }

  ans.insert(ans.begin(), start); // insert elements according to their finish time in stack (lastly finished element get pushed last).
}

vector<int> topoSort(int V, vector<int> adj[])
{
  bool visited[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  vector<int> ans; // behaving like stack.

  for (int i = 0; i < V; i++)
  {
    if (!visited[i])
      dfs(adj, i, visited, ans);
  }

  return ans;
}
