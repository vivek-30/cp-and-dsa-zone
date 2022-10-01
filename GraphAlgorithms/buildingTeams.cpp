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
vi g[N];
vi teams(N);
vb visited(N);

bool bfs(int src = 1) {
  queue<int> q;
  q.push(src);

  visited[src] = 1;
  teams[src] = 1;

  while(!q.empty()) {
    int curr = q.front();
    q.pop();

    for(int child: g[curr]) {
      if(!visited[child]) {
        visited[child] = 1;
        q.push(child);
        teams[child] = teams[curr] == 1 ? 2 : 1;
      } else if(teams[child] == teams[curr]) return false;
    }
  }

  return true;
}

bool dfs(int src = 1, int team = 1) {
  visited[src] = 1;
  teams[src] = team;

  for(int child: g[src]) {
    if(!visited[child]) {
      bool res = dfs(child, (teams[src] == 1 ? 2 : 1));
      if(res == false) return false;
    } else if(teams[child] == teams[src]) return false;
  }

  return true;
}

void solve(int tc) {
  inp(n, m);

  f(i, 1, m) {
    int a, b;
    inp(a, b);

    g[a].eb(b);
    g[b].eb(a);
  }

  bool flag = true;
  f(i, 1, n) {
    if(!visited[i] && bfs(i) == false) {
      flag = false;
      break;
    }
  }

  if(flag) {
    logarr(1, n, teams);
  } else out("IMPOSSIBLE\n");
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
