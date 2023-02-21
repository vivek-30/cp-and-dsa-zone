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
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vi>
#define mid(s, e) (s + (e - s) / 2)
#define all(v) v.begin(), v.end()
#define rep(i, s, e) for(int i = s; i <= e; i++)
#define reprev(i, s, e) for(int i = s; i >= e; i--)
template<typename... T>
void input(T&... args) { ((cin >> args), ...);}
template<typename... T>
void output(T&&... args) { ((cout << args), ...);}
#define debug(x) cout << #x << " = " << x << '\n';
#define bitcount(x) __builtin_popcountll(x)
#define sz size()

void solve() {
  int n, k;
  input(n, k);

  int mx = -1;
  set<int> s;
  rep(i, 1, 2*n) {
    s.insert(i);
  }

  rep(i, 1, n) {
    int x;
    input(x);
    s.erase(x);
    mx = max(mx, x);
  }

  ll ans1 = 0, ans2 = 0, ans = 0;
  
  if(mx == 2*n) {
    auto it = s.begin();
    while(it != s.end() && k--) {
      ans = (ans + (mx - (*it)));
      it++;
    }
    output(ans, '\n');
    return;
  }

  auto it = s.begin();
  int temp = k;
  while(k-- && (it != s.end() && (*it) < mx)) {
    ans = (ans + (mx - (*it)));
    it++;
  }

  k--;
  while(k-- > 0) {
    ans = (ans + (2*n - (*it)));
    it++;
  }
  
  it = s.begin();
  k = temp-1;
  while(k-- > 0&& (it != s.end() && (*it) < 2*n)) {
    ans1 = (ans1 + (2*n - (*it)));
    it++;
  }

  ans = max(ans, ans1);
  output(ans, '\n');
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