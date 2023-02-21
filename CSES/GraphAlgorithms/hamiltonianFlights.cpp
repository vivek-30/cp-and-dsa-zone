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

#define N 25
vi g[N], path(N);
vb visited(N);

int n, m;
ll ans = 0;

bool possible(int u, int city) {

  if(visited[city]) return false;

  vi temp = g[path[u-1]];
  auto it = lower_bound(all(temp), city);
  if(it != temp.end() && *it == city) return true;

  return false;
}

void getAns(int curr) {
  if(curr == n) {
    f(city, 1, n) {
      if(possible(curr, city)) {
        ans = (ans + 1) % mod;
      }
    }
    return;
  }

  f(city, 1, n) {
    if(possible(curr, city)) {
      path[curr] = city;
      visited[city] = true;
      
      getAns(curr+1);
      
      path[curr] = 0;
      visited[city] = false;
    }
  }
  
  return;
}

void solve(int tc) {
  inp(n, m);
  
  f(i, 1, m) {
    int a, b;
    inp(a, b);

    g[a].eb(b);
  }

  path[1] = visited[1] = 1;
  getAns(2);
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
