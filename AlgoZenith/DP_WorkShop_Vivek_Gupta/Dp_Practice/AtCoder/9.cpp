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

double getAns(int n, int x, vector<double> &arr, vector<vector<double> > &dp) {
  if(x == 0) return 1;

  if(n < 0) return 0;

  if(dp[n][x] > -0.9) {
    return dp[n][x];
  }

  return dp[n][x] = (getAns(n-1, x-1, arr, dp)*arr[n] + getAns(n-1, x, arr, dp)*(1 - arr[n]));
}

void solve(int tc) {
  int n;
  inp(n);

  vector<double> arr(n);
  f(i, 0, n-1) inp(arr[i]);

  int x = (n+1)/2;

  vector<vector<double> > dp(n, vector<double>(x+1, -1.0));

  cout<<setprecision(10)<<fixed;
  out(getAns(n-1, x, arr, dp), br);
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
