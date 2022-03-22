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
#define vi vector<int>
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
  int n;
  input(n);

  vi arr(n);
  rep(i, 0, n-1) input(arr[i]);

  if(n == 2) {
    if(arr[0]%2 == 1 && arr[1]%2 == 1) {
      print(arr[0], ' ', arr[1], '\n');
    } else print("-1\n");
    return;
  }

  vi even, odd;

  rep(i, 0, n-1) {
    if(arr[i]%2 == 0) even.pb(arr[i]);
    else odd.pb(arr[i]);
  }

  vi res;
  for(int val: even) res.pb(val);
  for(int val: odd) res.pb(val);

  int pairs = odd.sz-1;
  
  if(pairs <= 0) {
    print("-1\n");
    return;
  }

  if(pairs&1) {
    rep(i, 0, n-1) print(res[i], ' ');
    print('\n');
    return;
  }

  bool isSwapped = false;
  rep(i, 0, n-2) {
    if(res[i]%2 == 0 && res[i+1]%2 == 1) {
      isSwapped = true;
      swap(res[i], res[i+1]);
      break;
    }
  }
  if(isSwapped) {
    rep(i, 0, n-1) print(res[i], ' ');
  } else print("-1");
  print('\n');
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