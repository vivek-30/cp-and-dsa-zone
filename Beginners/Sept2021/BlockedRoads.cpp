#include <bits/stdc++.h>
using namespace std;

#define null NULL
#define endl "\n"
#define inf INT_MAX
#define minf INT_MIN
#define mod 1000000007
#define ll long long int
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,string> pis;
typedef pair<string,int> psi;
typedef pair<string,string> pss;
typedef vector<pii > vii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vi > vvi;
typedef vector<vll > vvll;
typedef map<int, int> mii;
typedef map<string, string> mss;
typedef map<int, string> mis;
typedef map<string, int> msi;
#define mid(l, r) (l + (r - l) / 2)
#define f(i,s,n) for(ll i = s; i <= n; i++)
#define fr(i,s,e) for(ll i = s; i >= e; i--)
#define mp make_pair
#define pb push_back
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define fi first
#define se second
#define INF 2e18

queue<int> q;
vector<bool> visited(405, false);
vi dist(405, 0);
vii edges;

void bfs(int src, int u, int v, vi g[]) {
  q.push(src);
  visited[src] = true;

  while(!q.empty()) {
    int curr = q.front();
    q.pop();

    for(auto child: g[curr]) {
      if(!(src == u and child == v ) and !visited[child]) {
        q.push(child);
        visited[child] = true;
        dist[child] = dist[curr] + 1;
      }
    }
  }
}

void solve(vi g[], int v, int e) {

  cout<<(dist[v-1] != 0 ? dist[v-1] : -1)<<endl;
  f(i, 0, 405) {
    dist[i] = 0;
    visited[i] = false;
  }

  while(!q.empty()) {
    q.pop();
  }
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll v, e;
  cin>>v>>e;

  vi g[v+1];

  f(i, 1, e) {
    int a, b;
    cin>>a>>b;
    edges.pb(mp(a,b));

    g[a].pb(b);
    g[b].pb(a);
  }

  f(i, 0, e-1) {
    bfs(1, edges[i].fi, edges[i].se, g);
    solve(g, v, e);
  }


  return 0;
}
