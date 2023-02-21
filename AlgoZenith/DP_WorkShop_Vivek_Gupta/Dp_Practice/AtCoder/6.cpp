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

string s, t;

int getAns(int n, int m, vvi &dp) {
  if(n < 0 or m < 0) return 0;

  if(dp[n][m] != -1) return dp[n][m];

  int ans = 0;
  if(s[n] == t[m]) {
    ans = 1 + getAns(n-1, m-1, dp);
  } else {
    ans = max(getAns(n-1, m, dp), getAns(n, m-1, dp));
  }

  return dp[n][m] = ans;
}

string ans = "";

void getString(int n, int m, vvi &dp) {
  if(n < 0 or m < 0) return;

  if(s[n] == t[m]) {
    ans = s[n] + ans;
    getString(n-1, m-1, dp);
  } else {
    if(getAns(n-1, m, dp) > getAns(n, m-1, dp)) {
      getString(n-1, m, dp);
    } else getString(n, m-1, dp);
  }
}

void solve(int tc) {
  inp(s, t);

  vvi dp(s.sz, vi(t.sz, -1));
  getAns(s.sz-1, t.sz-1, dp);

  ans = "";

  getString(s.sz-1, t.sz-1, dp);
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

  int tc = 1;
  // cin >> tc;

  f(t, 1, tc) {
    solve(t);
  }

  return 0;
}
