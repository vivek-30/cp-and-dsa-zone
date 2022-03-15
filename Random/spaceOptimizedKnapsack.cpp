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

// Space Optimized Knapsack.
void solve() {
  int n, w;
  inp(n, w);

  vi val(n+1), weight(n+1);
  f(i, 1, n) inp(val[i]);
  f(i, 1, n) inp(weight[i]);
  
  vi dp(w+1, 0);
  f(i, 1, n) {
    fr(j, w, weight[i]) {
      dp[j] = max(dp[j], val[i] + dp[j - weight[i]]);
    }
  }

  out(dp[w], br);
}

// KnapSack With Different Variant. (Needs to fix it)
void solve2() {
  int n, w;
  inp(n, w);

  vi val(n+1), weight(n+1);
  f(i, 1, n) inp(val[i]);
  f(i, 1, n) inp(weight[i]);

  ll mxval = accumulate(all(val), 0LL);

  vi dp(mxval+1, inf);
  dp[0] = 0;

  f(i, 1, n) {
    fr(j, mxval - val[i], 0) {
      dp[j + val[i]] = min(dp[j + val[i]], weight[i] + dp[j]);
    }
  }

  int ans;
  f(i, 0, mxval) {
    if(dp[i] <= w) ans = i;
  }
  
  out(ans, br);
}

// unbounded knapsack
void solve3() {
  int n, w;
  inp(n, w);

  vi val(n+1), weight(n+1);
  f(i, 1, n) inp(val[i]);
  f(i, 1, n) inp(weight[i]);
  
  vi dp(w+1, 0);
  f(i, 1, w) {
    f(j, 1, n) {
      if(weight[j] > i) continue;
      dp[i] = max(dp[i], val[j] + dp[i - weight[j]]);
    }
  }

  out(dp[w], br);
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

  int t = 1;
  // cin >> t;

  while(t--) {
    solve2();
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
