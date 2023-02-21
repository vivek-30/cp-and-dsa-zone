#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define mod 998244353
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define inf 2e18
#define minf -2e18
#define pii pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vll>
#define mid(s, e) (s + (e - s) / 2)
#define all(v) v.begin(), v.end()
#define rep(i, s, e) for(ll i = s; i <= e; i++)
#define reprev(i, s, e) for(ll i = s; i >= e; i--)
template<typename... T>
void input(T&... args) { ((cin >> args), ...);}
template<typename... T>
void print(T&&... args) { ((cout << args), ...);}
#define debug(x) cout << #x << " = " << x << '\n';
#define bitcount(x) __builtin_popcountll(x)
#define sz size()

void solve() {
  int n;
  string s;

  input(n, s);
  vi store(n);

  rep(i, 0, n-1) {
    if(s[i] == '1') store[n - i - 1] += (i+1);
  }

  reprev(i, n-2, 0) store[i] += store[i+1];

  ll ans = 0, val = 1;
  rep(i, 0, n-1) {
    if(store[i]&1) {
      ans = (ans + val) % mod;
    }
    val = (val * 2) % mod;
  }

  print(ans, '\n');
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  ll t = 1;
  cin >> t;

  while(t--) {
    solve();
  }

  return 0;
}
