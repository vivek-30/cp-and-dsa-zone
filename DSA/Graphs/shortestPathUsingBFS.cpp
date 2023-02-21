#include<bits/stdc++.h>
using namespace std;

#define null NULL
#define inf INT_MAX
#define minf INT_MIN
#define ll long long int
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ump unordered_map
#define mid(l, r) (l + (r - l) / 2)
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define f(i,s,n) for(ll i = s; i < n; i++)

map<int, list<int> > adj;

void buildGraph(int a, int b) {
  adj[a].push_back(b);
  adj[b].push_back(a);
}

void shortestPath(int src, int dest, int v) {
  
  if(v <= 0)
    return;

  int dist[v];
  bool visited[v];

  f(i, src, v) {
    dist[i] = inf;
    visited[i] = false;
  }

  queue<int> q;
  q.push(src);
  visited[src] = true;

  dist[src] = 0;
  
  bool found = false;
  int j = src + 1, curr;

  while(!q.empty()) {
    
    curr = q.front();
    q.pop();

    for(auto v: adj[curr]) {
      if(!visited[v]) {
        dist[v] = dist[curr] + 1;
        q.push(v);
        visited[v] = true;
        if(v == dest) {
          found = true;
          break;
        }
      }
    }

    if(found)
      break;
  }

  while(!q.empty())   // Clear The Queue.
    q.pop();

  cout<<"Shortest Path From "<<src<<" To "<<dest<<" Is: "<<dist[dest]<<endl;
}

int main() {

  int v, e, a, b, src, dest;

  cout << "Enter total no of vertex and edges\n";
  cin >> v >> e;

  cout << "Enter edges\n";
  f(i, 0, e)
  {
    cin >> a >> b;
    buildGraph(a, b);
  }

  cout<<"Enter source and destination\n";
  cin>>src>>dest;

  shortestPath(src, dest, v);

  return 0;
}
