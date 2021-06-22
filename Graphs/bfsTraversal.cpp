#include <bits/stdc++.h>
using namespace std;

void getBfs(vector<int> adj[], int start, bool isVisited[], vector<int> &ans)
{
  queue<int> q;
  q.push(start);
  int curr;
  while (!q.empty())
  {
    curr = q.front();
    q.pop();

    if (!isVisited[curr])
    {
      ans.push_back(curr);
      isVisited[curr] = true;
    }

    for (auto it = adj[curr].begin(); it != adj[curr].end(); it++)
      if (!isVisited[*it])
        q.push(*it);
  }
}

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
  vector<int> ans;
  if (V == 0)
    return ans;

  bool isVisited[V];
  for (int i = 0; i < V; i++)
    isVisited[i] = false;

  getBfs(adj, 0, isVisited, ans);
  return ans;
}

// Sample Graph For BFS.

//         8
//         |
// 0 - 2   1    3 - 4
// |     / |    |   |
// |    /  6    |   |
// |   /        |   |
// |  /         |   |
// 5 /_ _ _ _ _ |   7
// |                |
// |_ _ _ _ _ _ _ _ |
