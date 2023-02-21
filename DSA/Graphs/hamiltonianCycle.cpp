#include<iostream>
#include<list>
using namespace std;
 
#define V 50

bool flag = false;
int src = 1;

void print(int path[], int vertex) {
  
  for(int i=src; i<vertex; i++)
    cout<<path[i]<<" ";

  cout<<endl;
}

bool pathExists(int graph[V][V], int path[], int curr, int u, int vertex) {

  for(int i=src; i<curr; i++)
    if(path[i] == u)
      return false;

  if(graph[path[curr-1]][u])
    return true;

  return false;
}

bool findHamiltonianPath(int graph[V][V], int path[], int curr, int vertex) {

  if(vertex <= 0 or curr <= 0) return false;
  
  if(curr == vertex) {
    if(graph[path[curr - 1]][src]) {
      flag = true;
      print(path, vertex);
    }
    return false;
  }

  for(int u=src; u<vertex; u++) {

    if(pathExists(graph, path, curr, u, vertex)) {
      path[curr] = u;

      if(findHamiltonianPath(graph, path, curr + 1, vertex))
        return true;

      path[curr] = -1;
    }
  }

  return false;
}
 
int main() {
  
  int vertex, n, edges, a, b;
  cout<<"Enter total vertex and edges\n";
  cin>>vertex>>edges;

  int graph[V][V];
  for(int i=0; i<V; i++)
    for(int j=0; j<V; j++)
      graph[i][j] = 0;

  cout<<"Enter edges\n";
  for(int i=0; i<edges; i++) {
    cin>>a>>b;
    graph[a][b] = 1;
    graph[b][a] = 1;
  }

  int path[vertex];

  for(int i=0; i<vertex; i++)
    path[i] = -1;

  path[src] = src;

  findHamiltonianPath(graph, path, src + 1, vertex);

  if(flag == false)
    cout<<"Graph does not have hamiltonian cycle/path\n";
  
  return 0;
}
  