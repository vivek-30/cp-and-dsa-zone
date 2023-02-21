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

int dp[20][10][2][2];

int getAns(int curr, string &s, int prev, int leading_zeros, int is_tight) {
  if(s[0] == '-') return 0;

  if(curr == s.sz) return 1;

  if(prev != -1 && dp[curr][prev][leading_zeros][is_tight] != -1) {
    return dp[curr][prev][leading_zeros][is_tight];
  }

  int ub = is_tight ? s[curr] - '0' : 9;
  int ans = 0;
  f(digit, 0, ub) {
    if(digit == prev && leading_zeros == 0) continue;
    ans = (ans + getAns(curr + 1, s, digit, ((leading_zeros)&(digit == 0)), ((is_tight)&(digit == ub))));
  }

  if(prev == -1) return ans;
  else return dp[curr][prev][leading_zeros][is_tight] = ans;
}

void solve(int tc) {
  int a, b;
  inp(a, b);

  string aa = to_string(a-1), bb = to_string(b);

  memset(dp, -1, sizeof(dp));
  int ub = getAns(0, bb, -1, 1, 1);

  memset(dp, -1, sizeof(dp));
  int lb = getAns(0, aa, -1, 1, 1);

  out(ub - lb, br);
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
