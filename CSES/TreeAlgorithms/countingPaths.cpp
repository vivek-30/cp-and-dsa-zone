#include <bits/stdc++.h>
using namespace std;

#define null NULL
#define endl "\n"
#define inf INT_MAX
#define minf INT_MIN
#define mod 1000000007
#define ll long long int
#define all(v) v.begin(), v.end()
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii > vii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vi > vvi;
typedef vector<vll > vvll;
typedef map<int, int> mii;
typedef map<char, int> mci;
template<typename... T>
void inp(T&... args) { ((cin >> args), ...);}
template<typename... T>
void out(T&&... args) { ((cout << args << " "), ...);}
#define mid(l, r) (l + (r - l) / 2)
#define f(i, s, e) for(ll i = s; i <= e; i++)
#define fr(i, s, e) for(ll i = s; i >= e; i--)
#define logarr(arr, s, e) for(int i = s; i <= e; i++) cout<<arr[i]<<" "; cout<<endl;
#define bitc(n) __builtin_popcount(n)
#define mp make_pair
#define pb push_back
#define sz size()
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define py cout<<"YES"<<endl;
#define pn cout<<"NO"<<endl;
#define fi first
#define se second
#define INF 2e18

// Algorithm Used "Difference Array Range Update Query In O(1)"    (GFG)

vi g[200005];
int jump[21][200005];
vi path(200005, 0), level(200005, 0);

void dfs(int src, int parent, int l) {

  jump[0][src] = parent;
  level[src] = l;

  for(int child: g[src]) {
    if(child != parent) {
      dfs(child, src, l+1);
    }
  }
}

void preProcessLCA() {
  dfs(1, 0, 0);

  f(i, 1, 20) {
    f(j, 1, 200004) {
      jump[i][j] = jump[i-1][jump[i-1][j]];
    }
  }
}

int findLCA(int a, int b) {

  if(level[a] > level[b]) swap(a, b);

  int diff = level[b] - level[a];

  f(i, 0, 20) {
    if(diff & (1<<i)) {
      b = jump[i][b];
    }
  }

  if(a == b) return a;

  fr(i, 20, 0) {
    if(jump[i][a] != jump[i][b]) {
      a = jump[i][a];
      b = jump[i][b];
    }
  }

  return jump[0][a];
}

void solve(int src, int parent) {
  for(int child: g[src]) {
    if(child != parent) {
      solve(child, src);
      path[src] += path[child];
    }
  }
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  clock_t begin = clock();

  int n, m;
  inp(n, m);

  f(i, 1, n-1) {
    int a, b;
    inp(a, b);

    g[a].pb(b);
    g[b].pb(a);
  }

  preProcessLCA();

  f(i, 1, m) {
    int a, b;
    inp(a, b);

    int LCA = findLCA(a, b);
    int parentLCA = jump[0][LCA];

    path[a]++;
    path[b]++;
    path[LCA]--;
    path[parentLCA]--;
  }

  solve(1, 0);

  f(i, 1, n) {
    cout<<path[i]<<" ";
  }
  cout<<endl;

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
