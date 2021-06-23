#include<iostream>
#include<list>
using namespace std;
 
#define V 50

int src = 1;
bool flag = false;

list<int> graph[V];
char myColors[] = {'R', 'G', 'B', 'P', 'O', 'Y', 'M', 'W'};

void print(char colors[], int src, int n) {
  for(int i=src; i<n ;i++)
    cout<<colors[i]<<" ";
  cout<<endl;
}

bool isSafe(char colors[], int u, char color) {
  for(auto v: graph[u]) {
    if(colors[v] == color)
      return false;
  }

  return true;
}

bool isColorable(char colors[], int curr, int vertex, int n) {

  if(curr >= vertex) {
    flag = true;
    print(colors, src, vertex);
    return false;
  }

  if(vertex <= 0 or n <= 0) return false;

  for(int color = 0; color < n; color++) {
    
    if(isSafe(colors, curr, myColors[color])) {
      
      colors[curr] = myColors[color];

      if(isColorable(colors, curr + 1, vertex, n))
        return true;
      
      colors[curr] = '_';
    }
  }

  return false;
}
 
int main() {
  
  int vertex, n, edges, a, b;
  cout<<"Enter total vertex and edges\n";
  cin>>vertex>>edges;

  cout<<"Enter edges\n";
  for(int i=0; i<edges; i++) {
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  cout<<"Enter total number of colors\n";
  cin>>n;

  char colors[vertex];

  for(int i=0; i<vertex; i++)
    colors[i] = '_';

  isColorable(colors, src, vertex, n);

  if(flag == false)
    cout<<"Graph isn't colorable with"<<n<<" colors\n";
  
  return 0;
}
  