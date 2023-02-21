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
  int n, x1, y1, x2, y2;
  input(n, x1, y1, x2, y2);

  int ans = abs(x1-x2) + abs(y1-y2);
  ans = min(ans, 2 + min({abs(1-x1), abs(n-x1), abs(1-y1), abs(n-y1)}) +  min({abs(1-x2), abs(n-x2), abs(1-y2), abs(n-y2)}));

  output(ans, '\n'); 
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
