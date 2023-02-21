#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define inf 2e18
#define minf -2e18
#define mod 1000000007
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

void solve() {
  int n;
  input(n);

  int x, mx = minf;
  map<int, int> m;
  rep(i, 1, n) {
    input(x);
    m[x]++;
    mx = max(mx, m[x]);
  }

  int ans = mx;
  if(ans == n) {
    output("0\n");
    return;
  }
  vi arr;
  for(auto [key, val]: m) {
    arr.pb(key);
  }


  int i = 0;
  while(i <= arr.sz - 2) {
    if(((arr[i])^( arr[i+1])) <= 1) {
      ans = max(ans, m[arr[i]] + m[arr[i+1]]);
    }
    i++;
  }

  output(n - ans, '\n');
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
