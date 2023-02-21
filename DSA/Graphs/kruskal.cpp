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

class Edge {
  public:
    int src, dest, wt;

    Edge() {
      src = dest = wt = -1;
    }
};

class DisJoint
{

  unordered_map<int, int> m;

public:
  void makeSet(int src, int v);
  int findSet(int e);
  bool makeUnion(int a, int b);
};

void DisJoint::makeSet(int src, int v)
{
  f(i, src, v)
    m[i] = -1;
}

int DisJoint::findSet(int e)
{

  if (m[e] < 0)
  {
    return e;
  }

  int res = findSet(m[e]);
  m[e] = res;
  return res;
}

bool DisJoint::makeUnion(int a, int b)
{
  int parentA = findSet(a);
  int parentB = findSet(b);

  if(parentA == parentB) 
    return false;

  if (m[parentA] <= m[parentB])
  { // parentA has more -ve weight.
    m[parentA] += m[parentB];
    m[parentB] = parentA;
  }
  else
  {
    m[parentB] += m[parentA];
    m[parentA] = parentB;
  }

  return true;
}

map<int, list<pii > > adj;

void buildGraph(int a, int b, int w) {
  adj[a].push_back({ b, w });
  adj[b].push_back({ a, w });
}

void kruskal(int src, int v) {
  if(v <= 0) return;

  Edge res[v-1];
  DisJoint obj;
  obj.makeSet(src, v);

  multiset<pair<int, pii > > s; // Keep data sorted according to the weight of a edge.
  f(i, src, v) {
    for(auto j: adj[i]) {
      s.insert(mp(j.se, mp(i, j.fi)));
    }
  }

  int count = 0;

  while(!s.empty() and count < v - 1) { // Collect only (|v| - 1) edges.
    auto it = *(s.begin());
    s.erase(s.begin());

    if(obj.makeUnion(it.se.fi, it.se.se)) {
      res[count].wt = it.fi;
      res[count].src = it.se.fi;
      res[count].dest = it.se.se;
      count++;
    }
  }

  cout<<"Edges Included In MST are:\nsrc\t\tdest\t\tweight\n";
  f(i, src, v-1)
    cout<<res[i].src<<"\t\t"<<res[i].dest<<"\t\t"<<res[i].wt<<endl;
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
  kruskal(src, v);

  return 0;
}
