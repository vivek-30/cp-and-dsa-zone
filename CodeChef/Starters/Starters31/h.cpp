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

  set<int> includes, excludes;

  int mx = -1;
  rep(i, 0, n-1) {
    if(arr[i] == -1) continue;
    if(arr[i] > i+1 or arr[i] < mx) {
      print("-1\n");
      return;
    }

    if(arr[i] == mx) arr[i] = -1;
    else {
      includes.insert(arr[i]);
      mx = arr[i];
    }
  }

  rep(i, 0, n+1) {
    if(includes.count(i) == 0) {
      excludes.insert(i);
    }
  }

  vi res;
  bool flag = true;
  for(int &val: arr) {
    if(val == -1 or flag) {
      res.pb(*excludes.begin());
      excludes.erase(excludes.begin());
      if(val != -1) flag = false;
    } else {
      res.pb(*includes.begin());
      includes.erase(includes.begin());
    }
  }

  rep(i, 0, n-1) print(res[i], ' ');
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