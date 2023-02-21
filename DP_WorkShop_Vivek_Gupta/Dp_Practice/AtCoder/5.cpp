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

ll getAns(int n, ll mx, vii &arr, vvll &dp) {

  if(mx == 0) {
    return 0;
  }

  if(n < 0 or mx < 0) {
    return INF;
  }

  if(dp[n][mx] != -1) return dp[n][mx];

  ll ans = INF;
  ans = min(ans, getAns(n-1, mx, arr, dp));

  ll res = getAns(n-1, mx - arr[n].se, arr, dp);
  if(res != INF) ans = min(ans, res + arr[n].fi);

  return dp[n][mx] = ans;
}

void solve(int tc) {
  int n, w;
  inp(n, w);

  ll mx = 0;
  vii arr(n);   // {wt, val}
  f(i, 0, n-1) inp(arr[i].fi, arr[i].se), mx += arr[i].se;

  vvll dp(n, vll(mx+1, -1));
  getAns(n-1, mx, arr, dp);

  fr(i, mx, 0) {
    if(getAns(n-1, i, arr, dp) <= w) {
      out(i, br);
      return;
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

  int tc = 1;
  // cin >> tc;

  f(t, 1, tc) {
    solve(t);
  }

  return 0;
}
