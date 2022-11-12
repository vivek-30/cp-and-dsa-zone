#include <bits/stdc++.h>
using namespace std;

#define inf 2e18
#define minf -2e18
#define mod 1000000007
#define int long long int
#define ld long double
#define all(v) v.begin(), v.end()
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<char, int> mci;
template<typename... T>
void inp(T&... args) { ((cin >> args), ...);}
template<typename... T>
void out(T&&... args) { ((cout << args), ...);}
#define mid(l, r) (l + (r - l) / 2)
#define f(i, s, e) for(int i = s; i <= e; i++)
#define fr(i, s, e) for(int i = s; i >= e; i--)
#define logarr(s, e, arr) for(int i = s; i <= e; i++) cout << arr[i] << " ";  cout << "\n";
#define bitc(n) __builtin_popcountll(n)
#define debug(a) cout << #a << " = " << a << "\n";
#define mp make_pair
#define eb emplace_back
#define sz size()
#define br "\n"
#define ump unordered_map
#define pqmax priority_queue<int, vi>
#define pqmin priority_queue<int, vi, greater<int> >
#define py cout << "YES" << "\n";
#define pn cout << "NO" << "\n";
#define fi first
#define se second

#define N 100001

int n, q;

vi level(N), arr(N), store(N);
vi g[N];
vvi jump(21, vi(N));

void dfs(int src, int parent, int xr, int l) {
  xr ^= arr[src];
  store[src] = xr;
  level[src] = l;
  jump[0][src] = parent;

  for(int child: g[src]) {
    if(child != parent) {
      dfs(child, src, xr, l+1);
    }
  }
}
 
int getLCA(int a, int b) {
  if(level[a] < level[b]) swap(a, b);
  
  fr(i, 20, 0) {
    if(level[b] + (1 << i) <= level[a]) {
      a = jump[i][a];
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

void preProcessLCA() {
  dfs(1, 0, 0, 0);
 
  f(i, 1, 20) {
    f(j, 1, n) {
      int parent = jump[i - 1][j];
      jump[i][j] = jump[i - 1][parent];
    }
  }
}

void solve(int tc) {
  inp(n, q);
  f(i, 1, n) inp(arr[i]);

  f(i, 2, n) {
    int a, b;
    inp(a, b);

    g[a].eb(b);
    g[b].eb(a);
  }

  preProcessLCA();

  while(q--) {
    int a, b;
    inp(a, b);

    int ans = store[a]^store[b];
    int lca = getLCA(a, b);

    out((ans^arr[lca]), br);
  }
}

int32_t main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  clock_t begin = clock();

  int tc = 1;

  f(t, 1, tc) {
    solve(t);
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
