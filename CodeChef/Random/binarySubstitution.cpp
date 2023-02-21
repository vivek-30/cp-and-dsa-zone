#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define inf 2e18
#define minf -2e18
#define mod 998244353
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vi>
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz size()
#define mid(s, e) (s + (e - s) / 2)
#define rep(i, s, e) for(int i = s; i <= e; i++)
#define reprev(i, s, e) for(int i = s; i >= e; i--)
template<typename... T>
void input(T&... args) { ((cin >> args), ...);}
template<typename... T>
void output(T&&... args) { ((cout << args), ...);}
#define debug(x) cout << #x << " = " << x << '\n';
#define bitcount(x) __builtin_popcountll(x)
#define yes cout << "YES" << "\n";
#define no cout << "NO" << "\n";

int go(int n, string &s, vi &dp) {
  if(n < 0) {
    return 0;
  }

  if(n <= 1) {
    if(n == 0) return 1;
    if(s[n] != s[n-1]) {
      return 2;
    }
    else return 1;
  }

  if(dp[n] != -1) return dp[n];

  int ans = go(n-1, s, dp) % mod;
  if(s[n-1] != s[n]) {
    ans = (ans + go(n-2, s, dp) % mod) % mod;
  }

  return dp[n] = ans;
}

void solve() {
  string s;
  input(s);

  vi dp(s.sz, -1);

  output(go(s.sz-1, s, dp), '\n');
}

int32_t main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int t = 1;
  cin >> t;

  while(t--) {
    solve();
  }

  return 0;
}
