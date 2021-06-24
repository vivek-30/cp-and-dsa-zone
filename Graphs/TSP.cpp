#include<iostream>
#include<list>
using namespace std;
 
#define V 50

bool flag = false;
int src = 1, res = INT_MAX;

bool pathExists(int graph[V][V], int path[], int curr, int u, int vertex) {

  for(int i=src; i<curr; i++)
    if(path[i] == u)
      return false;

  if(graph[path[curr-1]][u] != INT_MIN)
    return true;

  return false;
}

bool findHamiltonianPath(int graph[V][V], int path[], int curr, int vertex, int ans) {

  if(vertex <= 0 or curr <= 0) return false;
  
  if(curr == vertex) {
    if(graph[path[curr - 1]][src] != INT_MIN) {
      flag = true;
      res = min(ans + graph[path[curr - 1]][src], res);
    }
    return false;
  }

  for(int u=src; u<vertex; u++) {

    if(pathExists(graph, path, curr, u, vertex)) {
      path[curr] = u;
      
      int oldValue = ans;

      if(ans == INT_MAX)
        ans = graph[path[curr - 1]][u];
      else 
        ans += graph[path[curr - 1]][u];

      if(findHamiltonianPath(graph, path, curr + 1, vertex, ans))
        return true;

      path[curr] = -1;
      ans = oldValue;
    }
  }

  return false;
}
 
int main() {
  
  int vertex, n, edges, a, b, w;
  cout<<"Enter total vertex and edges\n";
  cin>>vertex>>edges;

  int graph[V][V];
  for(int i=0; i<V; i++)
    for(int j=0; j<V; j++)
      graph[i][j] = INT_MIN;

  cout<<"Enter edges with their weights\n";
  for(int i=0; i<edges; i++) {
    cin>>a>>b>>w;
    graph[a][b] = w;    // Weighted Directed Graph.
  }

  int path[vertex];

  for(int i=0; i<vertex; i++)
    path[i] = -1;

  path[src] = src;

  int ans = INT_MAX;
  findHamiltonianPath(graph, path, src + 1, vertex, ans);

  if(res == INT_MAX)
    cout<<"No Feasbile Solution Exists\n";
  else cout<<"Min cost of travelling is: "<<res<<endl;
  
  return 0;
}
  