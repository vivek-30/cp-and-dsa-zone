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

void generate(int i, int j, int &n, int &m, vvi &grid, vvi &dp) {

  if(i > n or j > m or i <= 0 or j <= 0) return;

  if(i == n && j == m) {
    dp[i][j] = grid[i][j];
     if(i-1 >= 1) {
      dp[i][j] += dp[i-1][j];
    }

    if(j-1 >= 1) {
      dp[i][j] += dp[i][j-1];
    }

    return;
  }

  dp[i][j] = grid[i][j];
  if(i-1 >= 1) {
    dp[i][j] += dp[i-1][j];
  }

  if(j-1 >= 1) {
    dp[i][j] += dp[i][j-1];
  }

  generate(i+1, j, n, m, grid, dp);
  generate(i, j+1, n, m, grid, dp);
}

void solve(int tc) {
  int n, m;
  inp(n, m);

  vvi grid(n+1, vi(m+1, 0)), dp(n+1, vi(m+1, 0));;
  f(i, 1, n) {
    f(j, 1, m) {
      inp(grid[i][j]);
    }
  }

  if(n == 1 && m == 1) {
    if(grid[1][1] >= 0)
      py
    else pn
    return;
  }

  if(grid[1][1] != grid[n][m]) {
    pn
    return;
  }

  fr(i, m-1, 1) {
    if(grid[1][i] < grid[1][i+1]) {
      pn
      return;
    }
  }

  ll sum = 0;
  f(i, 1, n) {
    f(j, 1, m) {
      sum += grid[i][j];
    }
  }

  sum -= grid[1][1];
  sum -= grid[n][m];

  if(sum != grid[1][1]) {
    pn
    return;
  }

  dp[1][1] = grid[1][1];
  generate(1, 1, n, m, grid, dp);
 
  f(i, 1, n) {
    f(j, 1, m) {
      if(grid[i][j] > dp[i][j]) {
        pn
        return;
      }
    }
  }

  py
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
  cin >> tc;

  f(t, 1, tc) {
    solve(t);
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
