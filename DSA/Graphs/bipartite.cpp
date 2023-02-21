#include <iostream>
#include <list>
using namespace std;

#define V 50
#define N 2
#define src 0

list<int> graph[V];

bool isSafe(int colors[], int u, char color)
{

  for (auto v : graph[u])
    if (colors[v] == color)
      return false;

  return true;
}

bool isBipartite(int colors[], int curr, int vertex)
{

  if (curr >= vertex)
    return true;

  if (vertex <= 0)
    return false;

  for (int color = 1; color <= N; color++)
  {

    if (isSafe(colors, curr, color))
    {

      colors[curr] = color;

      if (isBipartite(colors, curr + 1, vertex))
        return true;

      colors[curr] = -1;
    }
  }

  return false;
}

int main()
{

  int vertex, edges, a, b;
  cout << "Enter total vertex and edges\n";
  cin >> vertex >> edges;

  cout << "Enter edges\n";
  for (int i = 0; i < edges; i++)
  {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  int colors[vertex];
  memset(colors, -1, sizeof(colors));

  if (isBipartite(colors, src, vertex))
    cout << "Graph Is Bipartite\n";
  else
    cout << "Graph Is Not Bipartite\n";

  return 0;
}
