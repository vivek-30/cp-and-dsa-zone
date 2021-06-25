#include<iostream>
using namespace std;
 
#define V 50
#define inf INT_MAX

void floydWarshall(int graph[V][V], int src, int size) {
  
  int paths[V][V];

  for(int i=src; i<size; i++)
    for(int j=src; j<size; j++)
      paths[i][j] = graph[i][j];

  for(int k=src; k<size; k++)
    for(int i=src; i<size; i++)
      for(int j=src; j<size; j++)
        if(paths[i][k] != inf and paths[k][j] != inf)
          paths[i][j] = min(paths[i][j], (paths[i][k] + paths[k][j]));

  cout<<"Shortest paths are:\n";
  for(int i=src; i<size; i++) {
    for(int j=src; j<size; j++)
      cout<<paths[i][j]<<" ";
    cout<<endl;
  } 
}
 
int main() {
  
  int graph[V][V] = {
    {0, 3, inf, 7},
    {8, 0, 2, inf},
    {5, inf, 0, 1},
    {2, inf, inf, 0}
  };

  int size = 4, src = 0;

  floydWarshall(graph, src, size);
  
  return 0;
}
  