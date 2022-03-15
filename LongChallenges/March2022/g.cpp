#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define mod 1000000007
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
  string s;
  input(s);

  int n = s.sz;
  if(n <= 2) {
    print("-1\n");
    return;
  }

  int len = 0, ans = 0;
  rep(i, 1, n-2) {
    len++;
    if(s[i] == s[0] or s[i] == s[n-1]) {
      ans = max(ans, len-1);
      len = 0;
    }
  }

  ans = max(ans, len);
  if(ans == 0) ans = -1;
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