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
#define f(i, s, e) for(int i = s; i <= e; i++)
#define fr(i, s, e) for(int i = s; i >= e; i--)
#define logarr(s, e, arr) for(int i = s; i <= e; i++) cout << arr[i] << " ";  cout << "\n";
#define bitc(n) __builtin_popcountll(n)
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
 
#define N 100007
 
int n, m;
vii g[N];
vll dist(N, INF);
vb visited(N);
 
void dijkstra(int src) {
 
  dist[src] = 0;
  multiset<pll> s;
  s.insert({dist[src], src});
 
  while(!s.empty()) {
    pii curr = *s.begin();
    s.erase(s.begin());
 
    if(!visited[curr.se]) {
      visited[curr.se] = 1;
      for(pii child: g[curr.se]) {
        if(dist[curr.se] != INF && dist[child.fi] > dist[curr.se] + child.se) {
          dist[child.fi] = dist[curr.se] + child.se;
          s.insert({dist[child.fi], child.fi});
        }
      }
    }
  }
 
  logarr(src, n, dist);
}
 
void solve(int tc) {
  inp(n, m);
 
  f(i, 1, m) {
    int a, b, w;
    inp(a, b, w);
 
    g[a].eb(mp(b, w));
  }
 
  dijkstra(1);
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
