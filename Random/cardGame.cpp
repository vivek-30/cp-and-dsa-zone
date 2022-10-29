#include <bits/stdc++.h>
using namespace std;

#define inf 2e18
#define minf -2e18
#define mod 998244353
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

vi fact(65, 1), inv(65, 1);

int exp(int a, int b) {
  a %= mod;
  int res = 1;
  while(b) {
    if(b&1) res = (res * a) % mod;
    b >>= 1;
    a = (a * a) % mod;
  }

  return res;
}

int ncr(int n, int r) {
  return ((((fact[n] * inv[r]) % mod) * inv[n-r]) % mod);
}

int dp[61][3];

void getAns(int n) {
  if(n == 2) {
    return;
  }

  getAns(n-2);

  dp[n][0] = (dp[n-2][1] + ncr(n-1, n/2)) % mod;
  dp[n][1] = (dp[n-2][0] + ncr(n-2, n/2)) % mod;
  dp[n][2] = (dp[n-2][2]) % mod;
}

void solve(int tc) {
  int n;
  inp(n);

  // Base Cases :
  dp[2][0] = 1;
  dp[2][1] = 0;
  dp[2][2] = 1;

  getAns(n);

  out(dp[n][0], ' ', dp[n][1], ' ', dp[n][2], br);
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

  f(i, 2, 64) {
    fact[i] = (fact[i-1] * i) % mod;
    inv[i] = exp(fact[i], mod-2);
  }

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
