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

void solve() {
  int n;
  inp(n);

  vi a(n), b(n);
  set<int> sa, sb;

  f(i, 0, n-1) inp(a[i]), sa.insert(a[i]);
  f(i, 0, n-1) inp(b[i]), sb.insert(b[i]);

  ll ans1 = abs(a[0] - b[0]) + abs(a[n-1] - b[n-1]), curr1 = INF, curr2 = INF, ans2 = 0;

  for(auto val : sb) {
    curr1 = min(curr1, (ll)(abs(a[0] - val)));
  }
  
  for(auto val : sb) {
    curr2 = min(curr2, (ll)(abs(a[n-1] - val)));
  }

  ans2 = (curr1 + curr2);
  curr1 = curr2 = INF;

  for(auto val : sa) {
    curr1 = min(curr1, (ll)(abs(b[0] - val)));
  }

  for(auto val : sa) {
    curr2 = min(curr2, (ll)(abs(b[n-1] - val)));
  }

  ans2 += (curr1 + curr2);
  
  out(min(ans1, ans2), br);
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
  cin >> t;

  while(t--) {
    solve();
  }

  #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif

  return 0;
}
