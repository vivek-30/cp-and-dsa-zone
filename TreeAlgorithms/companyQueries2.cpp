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

vi g[200005];
int level[200005];
int jump[200005][21];

void solve(int src, int parent, int l) {
  level[src] = l;
  jump[src][0] = parent;

  for(int child: g[src]) {
    if(child == parent) continue;

    solve(child, src, l+1);
  }
}

void preProcessLCA() {
  solve(1, 0, 0);

  f(i, 1, 200004) {
    f(j, 1, 20) {
      int parent = jump[i][j-1];
      jump[i][j] = jump[parent][j-1];
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

  int n, q;
  inp(n, q);

  f(i, 2, n) {
    int e;
    inp(e);

    g[e].pb(i);
    g[i].pb(e);
  }

  preProcessLCA();

  while(q--) {
    int a, b;
    inp(a, b);

    if(level[a] > level[b]) swap(a, b);

    int extra = level[b] - level[a];
    f(i, 0, 20) {
      if(extra & (1<<i)) {
        b = jump[b][i];
      }
    }

    if(a == b) {
      cout<<a<<endl;
      continue;
    }

    fr(i, 20, 0) {
      if(jump[a][i] != jump[b][i]) {
        a = jump[a][i];
        b = jump[b][i];
      }
    }

    cout<<jump[a][0]<<endl;
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
