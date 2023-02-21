#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX
#define minf INT_MIN
#define mod 1000000007
#define ll long long int
#define ld long double
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
void out(T&&... args) { ((cout << args), ...);}
#define mid(l, r) (l + (r - l) / 2)
#define f(i, s, e) for(ll i = s; i <= e; i++)
#define fr(i, s, e) for(ll i = s; i >= e; i--)
#define logarr(s, e, arr) for(int i = s; i <= e; i++) cout << arr[i] << " ";  cout << "\n";
#define bitc(n) __builtin_popcount(n)
#define debug(x) cout << #x << " = " << x << "\n";
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
#define INF 2e18

int blue_count, red_count, ans;
vi graph[300005];
vi color(300005);

pii dfs(int src, int parent) {
  pii curr;
  curr.fi = (color[src] == 1);
  curr.se = (color[src] == 2);

  for(int child: graph[src]) {
    if(child != parent) {
      pii temp = dfs(child, src);

      if(temp.fi == red_count && temp.se == 0) ans++;
      if(temp.fi == 0 && temp.se == blue_count) ans++;

      curr.fi += temp.fi;
      curr.se += temp.se;
    }
  }

  return curr;
}

void solve() {
  
  int n, u, v;
  inp(n);
  
  blue_count = red_count = 0, ans = 0;
  
  f(i, 1, n) {
    inp(color[i]);
    red_count += (color[i] == 1);
    blue_count += (color[i] == 2);
  }
  
  f(i, 1, n-1) {
    inp(u, v);
    graph[u].eb(v);
    graph[v].eb(u);
  }
  
  dfs(1, -1);
  out(ans, br);
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

  solve();

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
