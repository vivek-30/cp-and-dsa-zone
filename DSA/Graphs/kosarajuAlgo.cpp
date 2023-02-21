#include <bits/stdc++.h>
using namespace std;
 
#define null NULL
#define inf INT_MAX
#define minf INT_MIN
#define ll long long int
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,string> pis;
typedef pair<string,int> psi;
typedef pair<string,string> pss;
typedef vector<pii > vii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef map<int, int> mii;
typedef map<string, string> mss;
typedef map<int, string> mis;
typedef map<string, int> msi;
#define mid(l, r) (l + (r - l) / 2)
#define f(i,s,n) for(ll i = s; i < n; i++)
#define mp make_pair
#define pb push_back
#define ump unordered_map
#define pq priority_queue
#define fi first
#define se second
#define INF 2e18

map<int, list<int> > adj;

void buildGraph(int a, int b) {
  adj[a].push_back(b);
} 

void print() {
  for(auto u: adj) {
    cout<<u.fi<<" -> ";
    for(auto v: adj[u.fi])
      cout<<v<<", ";
    cout<<endl;
  }
}

void reverseGraph(int src, int v, list<int> res[]) {

  f(i, src, v) {
    for(auto j: adj[i]) {
      res[j].push_back(i);
    }
  }

}

void dfs(int src, vector<bool> &visited, list<int> res[]) {
  
  visited[src] = true;
  cout<<src<<" ";

  for(auto i: res[src])
    if(!visited[i])
      dfs(i, visited, res);
}

void topoOrder(int src, vector<bool> &visited, stack<int> &s) {
  
  visited[src] = true;

  for(auto i: adj[src])
    if(!visited[i])
      topoOrder(i, visited, s);
    
  s.push(src);
}

void kosaRaju(int src, int v) {
  
  stack<int> s;

  vector<bool> visited;
  f(i, src, v)
    visited.push_back(false);

  f(i, src, v)
    if(!visited[i])
      topoOrder(i, visited, s);

  // Reverse Graph
  list<int> res[v];
  reverseGraph(src, v, res);

  f(i, src, v)
    visited[i] = false;
  
  int curr, i = 1;
  cout<<"Strongly Connected Components are:\n";
  while(!s.empty()) {
    curr = s.top();
    s.pop();

    if(!visited[curr]) {
      cout<<i++<<") ";
      dfs(curr, visited, res);
      cout<<endl;
    }
  }
}

int main() {
 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  int vertex, n, edges, a, b;
  cout<<"Enter total vertex and edges\n";
  cin>>vertex>>edges;
  
  cout<<"Enter edges\n";
  for(int i=0; i<edges; i++) {
    cin>>a>>b;
    buildGraph(a, b);
  }

  int src = 0;
  kosaRaju(src, vertex);
 
  return 0;
}
 