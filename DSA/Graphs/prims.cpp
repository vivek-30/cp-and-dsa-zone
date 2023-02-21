#include <bits/stdc++.h>
using namespace std;

#define null NULL
#define endl "\n"
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

class Node {
  public:
    int curr, parent, wt;

    Node() {
      curr = parent = wt = -1;
    }
};

map<int, list<pii > > adj;

void buildGraph(int a, int b, int w) {
  adj[a].push_back({ b, w });
  adj[b].push_back({ a, w });
}

void prims(int src, int v) {
  
  if(v <= 0) 
    return;

  int count = 0;

  Node res[v];
  bool visited[v];
  
  f(i, src, v)
    visited[i] = false;

  set<pair<int, pii > > s;

  s.insert(mp(0, mp(src, -1)));
  while(!s.empty() and count < v-1) {
    auto it = *(s.begin());
    s.erase(s.begin());

    if(visited[it.se.fi]) // Most Important Part!!!!
      continue;

    visited[it.se.fi] = true;

    if(it.se.se != -1) {
      res[count].wt = it.fi;
      res[count].curr = it.se.fi;
      res[count].parent = it.se.se;
      count++;
    }

    for(auto v: adj[it.se.fi]) {
      if(!visited[v.fi]) {
        s.insert(mp(v.se, mp(v.fi, it.se.fi)));
      }
    }
  }

  cout<<"Edges Selected For MST Are:\nsrc\t\tdest\t\tweight\n";
  f(i, src, v-1)
    cout<<res[i].parent<<"\t\t"<<res[i].curr<<"\t\t"<<res[i].wt<<endl; 
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int v, e, w, a, b;

  cout << "Enter total no of vertex and edges\n";
  cin >> v >> e;

  cout << "Enter edges with weight\n";
  f(i, 0, e)
  {
    cin >> a >> b >> w;
    buildGraph(a, b, w);
  }

  int src = 0;
  prims(src, v);

  return 0;
}
