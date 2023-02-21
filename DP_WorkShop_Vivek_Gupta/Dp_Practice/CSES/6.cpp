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

void solve(int tc) {
  int n;
  inp(n);

  vector<vector<char> > arr(n+1, vector<char>(n+1));
  f(i, 1, n) {
    f(j, 1, n) {
      inp(arr[i][j]);
    }
  }

  if(arr[1][1] == '*' or arr[n][n] == '*') {
    out("0\n");
    return;
  }

  vvi dp(n+1, vi(n+1));
  fr(i, n, 1) {
    if(arr[i][n] == '*') break;
    dp[i][n] = 1;
  }

  fr(i, n, 1) {
    if(arr[n][i] == '*') break;
    dp[n][i] = 1;
  }

  fr(i, n-1, 1) {
    fr(j, n-1, 1) {
      if(arr[i][j] == '.') dp[i][j] = (dp[i+1][j] + dp[i][j+1]) % mod;
    }
  }

  out(dp[1][1], br);
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
