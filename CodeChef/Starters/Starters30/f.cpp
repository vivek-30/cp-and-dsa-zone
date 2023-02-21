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

void solve() {
  int n, m;
  input(n, m);

  int x1, y1, x2, y2;
  input(x1, y1);
  input(x2, y2);

  vvi res(n+1, vi(m+1, -1));
  res[x1][y1] = 1;
  res[x2][y2] = 2;

  ll mx = 1e9;

  rep(i, 1, n) {
    rep(j, 1, m) {
      rep(val, 1, mx) {
        if(res[i][j] != -1) break;

        if((i-1 >= 1 && res[i-1][j] == val)) continue;
        if((i+1 <= n && res[i+1][j] == val)) continue;
        if((j-1 >= 1 && res[i][j-1] == val)) continue;
        if((j+1 <= m && res[i][j+1] == val)) continue;

        res[i][j] = val;
        break;
      }
    }
  }

  rep(i, 1, n) {
    rep(j, 1, m) {
      print(res[i][j], ' ');
    }
    print('\n');
  }
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