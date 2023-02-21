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

struct Task {
  int a, b, c;
};

ll getAns(int n, int prev, vector<Task> &arr, vvll &dp) {
  if(n == 0) {
    if(prev == -1) return max({arr[n].a, arr[n].b, arr[n].c});
    if(prev == 0) return max({arr[n].b, arr[n].c});
    if(prev == 1) return max({arr[n].a, arr[n].c});
    if(prev == 2) return max({arr[n].a, arr[n].b});
  }

  if(prev != -1 && dp[n][prev] != -1) return dp[n][prev];

  ll ans = -1, val;
  f(i, 0, 2) {
    if(prev != i) {
      if(i == 0) val = arr[n].a;
      else if(i == 1) val = arr[n].b;
      else val = arr[n].c;
      ans = max(ans, getAns(n-1, i, arr, dp) + val);
    }
  }

  if(prev == -1) return ans;
  return dp[n][prev] = ans;
}

void solve(int tc) {
  int n;
  cin>>n;

  vector<Task> arr(n);
  vvll dp(n, vll(3, -1));
  f(i, 0, n-1) inp(arr[i].a, arr[i].b, arr[i].c);

  out(getAns(n-1, -1, arr, dp), br);
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
