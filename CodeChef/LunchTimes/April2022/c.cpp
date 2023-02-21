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
  ll n;
  input(n);

  vi arr(n+1);
  rep(i, 1, n) {
    input(arr[i]);
  }

  ll ans = 0;
  sort(all(arr));

  ll cnt = 0, cnt1 = 0, cnt2 = 0;
  rep(i, 1, n) {
    if(arr[i] == 1) cnt++;
    if(arr[i] == 2) cnt1++;
    else if(arr[i] > 2) cnt2++;
  }

  ll total = n*(n-1)/2, curr = (1LL * cnt1 * cnt2) + (1LL * cnt2 * (cnt2 - 1)) / 2;
  ans = total - curr;

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
