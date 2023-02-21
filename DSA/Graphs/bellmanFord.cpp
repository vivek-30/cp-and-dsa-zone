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
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define fi first
#define se second
#define INF 2e18
 
void buildGraph(map<int, list<pii > > &adj, int a, int b, int w, bool bidir)
{
  adj[a].push_back({b, w});
  if(bidir)
    adj[b].push_back({a, w});
}

void bellmanFord(map<int, list<pii> > &adj, int src, int v) {
  
  bool isCycle = false;

  int dist[v];
  f(i, src, v)
    dist[i] = inf;
  
  dist[src] = 0;

  f(i, src, v) {  // Relax Every Vertex for (|v| - 1) times.
    f(u, src, v) {
      for(auto j: adj[u]) {
        if((dist[j.fi] > dist[u] + j.se) and (dist[u] != inf)) {
          dist[j.fi] = dist[u] + j.se;
        }
      }
    }
  }

  f(i, src, v) {
    for(auto v: adj[i]) {
      if((dist[v.fi] > dist[i] + v.se) and dist[i] != inf) {
        isCycle = true;
        break;
      }
    }

    if(isCycle) {
      cout<<"Given Graph has negative weight cycle\n";
      return;
    }
  }

  cout << "Shortest path is\n";
  f(i, src, v)
    cout << src << " -> " << i << " (" << dist[i] << ")\n";
}
 
int main() {
 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  int v, e, w, a, b, i;
  map<int, list<pii > > adj;
  bool bidir = true;

  cout << "Enter total no of vertex and edges\n";
  cin >> v >> e;

  cout<<"Enter 1 for Undirected and 0 for directed graph\n";
  cin>>i;
  if(i != 1)
    bidir = false;

  cout << "Enter edges with weight\n";
  f(i, 0, e)
  {
    cin >> a >> b >> w;
    buildGraph(adj, a, b, w, bidir);
  }

  int src = 0;
  bellmanFord(adj, src, v);
 
  return 0;
}
 