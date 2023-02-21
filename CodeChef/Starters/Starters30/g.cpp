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
#define vvi vector<vi>
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

vi LIS(vi &arr) {
  vi res;
  for(ll &val: arr) {
    auto it = lower_bound(all(res), val);
    if(it == res.end()) {
      res.pb(val);
    } else {
      *it = val;
    }
  }

  return res;
}

void solve() {
  int n;
  input(n);

  vi arr(n);
  rep(i, 0, n-1) {
    input(arr[i]);
  }

  if(n == 1) {
    print("1\n");
    return;
  }

  vi res = LIS(arr);
  int ans = res.sz;

  if(ans == n) {
    print(ans, '\n');
    return;
  }

  vector<bool> visited(200007, false);

  for(ll val: arr) {
    auto it = lower_bound(all(res), val);
    if(it == res.end()) {
      auto t = upper_bound(all(res), val);
      if(t != res.end() && val + 1 != *t) {
        print(ans+1, '\n');
        return;
      }
    } else if(visited[val] == true) {
      auto t = upper_bound(all(res), val);

      if(t == res.end()) {
        print(ans+1, '\n');
        return;
      }

      if(t != res.end() && val + 1 != *t) {
        print(ans+1, '\n');
        return;
      }
    }

    visited[val] = true;
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