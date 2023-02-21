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

#define MX 200005

vi g[MX];
vi val(MX), start(MX), finish(MX);
vll FT(MX);
int timer = 0, n;

// All the subtree Nodes are enclosed between start and finish time of src node
void update(int i, int val) {
  for(; i <= n; i += (i & (-i)))
    FT[i] += val;
}

ll query(int i) {
  ll sum = 0;
  for(; i > 0; i -= (i & (-i)))
    sum += FT[i];

  return sum;
}

void dfs(int src, int parent) {

  start[src] = ++timer;
  update(timer, val[src]);

  for(int child: g[src]) {
    if(child != parent) {
      dfs(child, src);
    }
  }

  finish[src] = timer;
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

  int q;
  inp(n, q);

  f(i, 1, n) {
    inp(val[i]);
  }

  f(i, 1, n-1) {
    int a, b;
    inp(a, b);

    g[a].pb(b);
    g[b].pb(a);
  }

  dfs(1, 0);

  f(i, 1, q) {
    int type, s, x;
    inp(type, s);

    if(type == 1) {
      inp(x);
      update(start[s], -val[s]);
      val[s] = x;
      update(start[s], val[s]);
    }
    else {
      ll ans = query(finish[s]) - query(start[s]-1);
      cout<<ans<<endl;
    }
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
