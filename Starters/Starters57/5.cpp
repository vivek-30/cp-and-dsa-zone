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
#define yes cout << "YES" << "\n";
#define no cout << "NO" << "\n";
#define pii pair<ll, ll>
#define vi vector<ll>
#define vii vector<pii>
#define vvi vector<vi>
#define mid(s, e) (s + (e - s) / 2)
#define all(v) v.begin(), v.end()
#define rep(i, s, e) for(int i = s; i <= e; i++)
#define reprev(i, s, e) for(int i = s; i >= e; i--)
template<typename... T>
void input(T&... args) { ((cin >> args), ...);}
template<typename... T>
void print(T&&... args) { ((cout << args), ...);}
#define debug(x) cout << #x << " = " << x << '\n';
#define bitcount(x) __builtin_popcountll(x)
#define sz size()

void solve() {
  int n, p, k, q;
  input(n);

  vi arr(n), prefix(n);
  ll mx = -1;
  map<int, vi> m;

  rep(i, 0, n-1) {
    input(arr[i]);
    if(i == 0) prefix[i] = arr[i];
    else prefix[i] = prefix[i-1]+arr[i];
    mx = max(mx, arr[i]);
    m[arr[i]].pb(i+1);
  }

  input(q);

  while(q--) {
    input(p, k);
    if(p > mx) {
      print(prefix[k-1], '\n');
    } else {
      multiset<int> s;
      int cnt = 0;
      ll rem = 0, pt = p;
      while(pt <= mx) {
        if(m.count(pt)) {
          for(ll val: m[pt]) {
            if(val <= k) cnt++, rem += arr[val-1];
            s.insert(arr[val-1]);
          }
        }
        pt += p;
      }
      auto it = s.end();
      if(s.sz) --it;
      ll ans = prefix[k-1] - rem;
      while(cnt--) {
        ans += (*it);
        it--;
      }
      print(ans, '\n');
    }
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

  int t = 1;
  cin >> t;

  while(t--) {
    solve();
  }

  return 0;
}
